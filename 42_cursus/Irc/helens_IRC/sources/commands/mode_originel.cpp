/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:59:01 by Helene            #+#    #+#             */
/*   Updated: 2024/11/02 15:49:13 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/irc.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/Client.hpp"
#include "../../includes/Server.hpp"

typedef struct s_tuple
{
   char        mode;
   std::string modeArg;
}  t_tuple;


void  passwordMode(bool setMode, Client &client, Channel *channel, std::string const& pass)
{
   // check if valid password (remove blank spaces ?)
   std::cout << "in passwordMode(), " << (setMode ? "adding" : "removing") << " mode" << std::endl;
}

void  operatorMode(bool setMode, Client &client, Channel *channel, std::string const& newOp)
{
   std::cout << "in operatorMode(), " << (setMode ? "adding" : "removing") << " mode" << std::endl;
}

void  usersLimitMode(bool setMode, Client &client, Channel *channel, int const& limit)
{
   // check if valid limit, ie non negative
   // if (limit < 0)
   //    ; // error msg
   
   std::cout << "in usersLimitMode(), " << (setMode ? "adding" : "removing") << " mode" << std::endl;
}

/*
The MODE command is a dual-purpose command in IRC. It allows both
   usernames and channels to have their mode changed.
   When parsing MODE messages, it is recommended that the entire message
   be parsed first and then the changes which resulted then passed on.
*/

static void    addChanModes(Channel *channel, std::vector<t_tuple> const& modes, Client &client)
{
   for (std::vector<t_tuple>::const_iterator it = modes.begin(), end = modes.end(); it != end; it++)
   {
      if (it->mode == 'i')
         channel->setInviteOnlyMode(true);
      else if (it->mode == 't')
         channel->setTopicRestrictionMode(true);
      else if (it->mode == 'k')
         passwordMode(true, client, channel, it->modeArg);
      else if (it->mode == 'o')
         operatorMode(true, client, channel, it->modeArg);
      else if (it->mode == 'l')
         usersLimitMode(true, client, channel, std::atoi(it->modeArg.c_str()));
      else // unknown command
         ; // already printed an error msg in the calling function though
         
   }
}

static void removeChanModes(Channel *channel, std::vector<t_tuple> const& modes, Client &client)
{
   for (std::vector<t_tuple>::const_iterator it = modes.begin(), end = modes.end(); it != end; it++)
   {
      
   }
}

/*
Channel modes : 
   Parameters: <channel> {[+|-]|o|p|s|i|t|n|b|v} [<limit>] [<user>] [<ban mask>]
   (or) Parameters: <target> [<modestring> [<mode arguments>...]]

To implement : i - invite-only channel flag;
               t - topic settable by channel operator only flag;
               k - set a channel key (password).
               o - give/take channel operator privileges;
               l - set the user limit to channel;
*/
void  channelMode(CommandContext &ctx) // todo : 
{
   std::vector<std::string> params = ctx._parameters;
   std::string channelName = params[0];
   Channel *channel = ctx._server.getChannel(channelName);
   
   if (!channel)
      ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), channelName));
   else if (params.size() == 1) // check if is member of that channel ? ie ERR_NOTONCHANNEL ? 
   {

/*    324 your_nickname #example +itkol secretpass 50
      353 your_nickname #example @operator_nick
 */   }
      // ctx._client.addToWriteBuffer(RPL_CHANNELMODEIS(ctx._client.getNickname(), channelName, ));
   else if (! channel->isOperator(ctx._client.getNickname()))
      ctx._client.addToWriteBuffer(ERR_CHANOPRIVSNEEDED(ctx._client.getNickname(), channelName));
   else 
   {
      for (std::vector<std::string>:: iterator it = ctx._parameters.begin(); it!= ctx._parameters.end(); it++)//
      {//
         std::cout << *it << std::endl; //TO ERASE
      }//

      /* to do :  if '-'
                     if mode that need param, look for the first param
                        if first param good
                           check if mode already removed
                           update mode
                           add mode to removed mode
                           switch to second param
                        else
                           not enough params
                     else if mode doesn't need param
                        check if mode already removed
                        update mode
                        add mode to removed mode
                     else
                        unknown mode
                     next mode
                  if '+'
                     if mode that need param, look for the first param
                        if first param good
                           check if mode already added
                           update mode
                           add mode to added mode
                           switch to second param
                        else
                           not enough params
                     else if mode doesn't need param
                        check if mode already added
                        update mode
                        add mode to added mode
                     else
                        unkown mode
                     next mode
                */

      /*
      todo :   checker si peut avoir -ik par ex (ie plusieurs modes d'un coup)
               si c'est le cas, checker le comportement à avoir quand a un mode invalide 
                  parmi une chaine de modes valides
                  (ie process ceux valides, ou print juste un msg d'erreur et ignore les valides ?)
      */
      std::string mode = params[1];
      std::string validModes = "itkol";
      std::vector<t_tuple> removedParams;
      std::vector<t_tuple> addedParams;
      
      std::vector<std::string> modeParams(params.begin() + 3, params.end());
      std::vector<std::string>::iterator itParams = modeParams.begin(); // empty if modeParams.begin() == params.end()
      
      for (std::string::const_iterator it = mode.begin(), end = mode.end(); it != end; ++it) // const_iterator for read-only
      {
         if (*it == '-')
         {
            while (it != end && *it != '+')
            {
               if (validModes.find(*it) != std::string::npos)
               {
                  if (!removedParams.empty() && std::find(removedParams.begin(), removedParams.end(), *it) == removedParams.end()
                  && std::find(addedParams.begin(), addedParams.end(), *it) == addedParams.end())
                  // eviter les doublons + ne rien faire si a deja ete added plus tot dans la commande (a verif)
                  {
                     t_tuple mode;
                     mode.mode = *it;
                     if (*it == 'o') //  ( || *it == 'l' || *it == 'k') ?
                     {
                        if (itParams != modeParams.end())
                        {
                           mode.modeArg = *itParams;
                           itParams++;    
                        }
                     }
                     removedParams.push_back(mode);
                  }
               }
               else
                  ctx._client.addToWriteBuffer(ERR_UMODEUNKNOWNFLAG(ctx._client.getNickname()));
               it++;
            }
         }
         else
         {
            while (it != end && *it != '-')
            {
               if (validModes.find(*it) != std::string::npos)
               {
                  if (!addedParams.empty() && std::find(addedParams.begin(), addedParams.end(), *it) == addedParams.end()
                  && std::find(removedParams.begin(), removedParams.end(), *it) == removedParams.end())
                  {
                     t_tuple mode;
                     mode.mode = *it;
                     if (*it == 'k' || *it == 'o' || *it == 'l')
                     {
                        if (itParams != modeParams.end())
                        {
                           mode.modeArg = *itParams;
                           itParams++;    
                        }
                     }
                     addedParams.push_back(mode);
                  }
               }
               else
                  ctx._client.addToWriteBuffer(ERR_UMODEUNKNOWNFLAG(ctx._client.getNickname()));
               it++;
            }
         }
      }
      addChanModes(channel, addedParams, ctx._client);
      removeChanModes(channel, removedParams, ctx._client); 
   }
}

/*
User modes :
    Parameters: <nickname> {[+|-]|i|w|s|o}
    
A user MODE command may only be accepted if both the sender of the
   message and the nickname given as a parameter are both the same.
If a user attempts to make themselves an operator using the "+o"
   flag, the attempt should be ignored (since it would be bypassing
    the OPER command).  There is no restriction,
   however, on anyone `deopping' themselves (using "-o").
*/
void  userMode(CommandContext &ctx)
{
   
}

void  cmdMode(CommandContext &ctx)
{
   std::vector<std::string> params = ctx._parameters;
   if (params.empty())
   {
      //CETTE VERIF N'A PAS L'AIR DE FONCTIONNER
       ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx.getCommand()));
       return ;
   }
   if (params[0][0] == '#' || params[0][0] == '&')
      channelMode(ctx);
   else
      userMode(ctx);
}