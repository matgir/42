#include "../../includes/irc.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/Client.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Channel.hpp"
#include <stdio.h>
#include <stdlib.h>

void	channelModeIs(CommandContext &ctx)
{
	std::string						channelName = ctx._parameters[0];
	Channel							*chan = ctx._server.getChannel(channelName);
	std::map<std::string, Client*>	operatorsList = chan->getAllOperators();
	std::string						activeMode = "+o";
	std::string						kParams;
	std::string						lParams;
	std::string						clientName = ctx._client.getNickname();

	kParams.empty();
	lParams.empty();
	if (chan->getInviteOnlyMode())
		activeMode.append("i");
	if (chan->getPasswordMode())
	{
		activeMode.append("k");
		kParams.append(" ");
		kParams.append(chan->getPassword());
	}
	if (chan->getTopicRestrictionMode())
		activeMode.append("t");
	if (chan->getUserLimitMode())
	{
		activeMode.append("l");
		lParams.append(" ");
		std::ostringstream	ss;
		ss << chan->getUserLimit();
		lParams.append(ss.str());
	}
	
	if (ctx._server.getChannel(channelName)->isOperator(clientName))
		ctx._client.addToWriteBuffer(RPL_CHANNELMODEIS(clientName, channelName, activeMode, kParams, lParams));
	else
	{
		kParams.empty();
		ctx._client.addToWriteBuffer(RPL_CHANNELMODEIS(clientName, channelName, activeMode, kParams, lParams));
	}

	std::stringstream ss;
	ss << RPL_NAMREPLY(clientName, "=", channelName);
	for (std::map<std::string, Client*>::iterator it = chan->getAllOperators().begin(), end = chan->getAllOperators().end(); it != end; it++)
			ss << " " << "@" << it->first;
	ss << CRLF;
	ctx._client.addToWriteBuffer(ss.str());

	return;
}

void	channelMode(CommandContext &ctx)
{
	std::string	channelName = ctx._parameters[0];

	if (!ctx._server.getChannel(channelName))
		ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), channelName));
	else if (!ctx._server.getChannel(channelName)->isMember(ctx._client.getNickname()))
		ctx._client.addToWriteBuffer(ERR_NOTONCHANNEL(ctx._client.getNickname(), channelName));
	if (ctx._parameters.size() == 1)
		channelModeIs(ctx);
	else if (!ctx._server.getChannel(channelName)->isOperator(ctx._client.getNickname()))
		ctx._client.addToWriteBuffer(ERR_NOPRIVILEGES(ctx._client.getNickname(), channelName));

/*	
	if only param = <chanel_name> send this
	# define RPL_CHANNELMODEIS(client, channel, channel_string, mode_arguments) ()
	324 your_nickname #example +itkol secretpass 50
	# define RPL_NAMREPLY(client, symbol, channel) (": 353 " + client + " " + symbol + " " + channel + " :") // [prefix]<nick>{ [prefix]<nick>}, <prefix> is the highest channel membership prefix that client has in the channel, if they have one
	353 your_nickname #example @operator_nick
	pas compris si mode_string etait celui de la commande MODE, ou les current channel
	modes du channel en question ?

to do :	if '-'
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
}

void	cmdMode(CommandContext &ctx)
{
	std::cout << "ctx has this inside :\nprefix :\t" << ctx._prefix << "\ncommand :\t";//debug
	std::cout << ctx._command << "\nparameters :\n";//debug
	for (std::vector<std::string>:: iterator it = ctx._parameters.begin(), end = ctx._parameters.end();//debug
			it != end; it++)//DEBUG
		std::cout << "\t\t" << *it << std::endl; //DEBUG

	if (ctx._parameters.empty())
	{
		ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx.getCommand()));
		return;
	}
	if (ctx._parameters[0][0] == '#' || ctx._parameters[0][0] == '&')
		channelMode(ctx);
	else
		ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), ctx._parameters[0]));
}
