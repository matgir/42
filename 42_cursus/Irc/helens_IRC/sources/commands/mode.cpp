#include "../../includes/irc.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/Client.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Channel.hpp"

void	channelModeIs(CommandContext &ctx)
{
	std::string						channelName = ctx._parameters[0];
	Channel							*chan = ctx._server.getChannel(channelName);
	std::map<std::string, Client*>	operatorsList = chan->getAllOperators();
	std::string						activeMode = "+o";
	std::string						kParams;
	std::string						lParams;
	std::string						clientName = ctx._client.getNickname();

	kParams.clear();
	lParams.clear();
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
		kParams.clear();
		ctx._client.addToWriteBuffer(RPL_CHANNELMODEIS(clientName, channelName, activeMode, kParams, lParams));
	}

	std::stringstream ss;
	ss << RPL_NAMREPLY(clientName, "=", channelName);

	std::string	founder = chan->getFounder();
	if (chan->isMember(founder))
		ss << " ~" << founder;
	for (std::map<std::string, Client*>::iterator it = chan->getAllOperators().begin(), end = chan->getAllOperators().end(); it != end; it++)
		if (it->first != founder)
			ss << " @" << it->first;
	ss << CRLF;
	ctx._client.addToWriteBuffer(ss.str());

	return;
}

void	channelMode(CommandContext &ctx)
{
	std::string	channelName = ctx._parameters[0];
	/* ###### check how else if work pour etre sur que si rentre dans un ne va pas dans les autres */
	if (!ctx._server.getChannel(channelName))
		ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), channelName));
	else if (!ctx._server.getChannel(channelName)->isMember(ctx._client.getNickname()))
		ctx._client.addToWriteBuffer(ERR_NOTONCHANNEL(ctx._client.getNickname(), channelName));
	else if (ctx._parameters.size() == 1)
		channelModeIs(ctx);
	else if (!ctx._server.getChannel(channelName)->isOperator(ctx._client.getNickname()))
		ctx._client.addToWriteBuffer(ERR_NOPRIVILEGES(ctx._client.getNickname(), channelName));
	else
	{
		std::cout << "ctx has this inside :\nprefix :\t" << ctx._prefix << "\ncommand :\t";//debugmg
		std::cout << ctx._command << "\nparameters :\n";//debugmg
		for (std::vector<std::string>:: iterator it = ctx._parameters.begin(), end = ctx._parameters.end();//debugmg
				it != end; it++)//DEBUGmg
			std::cout << "\t\t" << *it << std::endl; //DEBUGmg
		std::cout << "Mode to code\n"; //debugmg
		
		std::string	mode = ctx._parameters[1];
		std::string	validMode = "itkol";
		std::string	addedParams;
		std::string	removedParams;

		addedParams.clear();
		removedParams.clear();

		if (ctx._parameters.size() > 2)
		{
			std::vector<std::string>	modeParams(ctx._parameters.begin() + 2/* ou 3 a checker */, ctx._parameters.end());
			unsigned int				sizeModeParams = modeParams.size();
			std::string::const_iterator	it = mode.begin();
			std::string::const_iterator	end = mode.end();
			unsigned int				sizeMode = mode.size();
			
			std::cout << "segfault 1	"; //debugmg
			// for (it; it != end; it++)
			for (unsigned int i = 0; i < sizeMode; i++)
			{
			std::cout << "sizeMode = " << sizeMode << "\nint i = " << i << std::endl; //debugmg
			std::cout << "segfault 2	"; //debugmg
				if (*it == '+')
				{
			std::cout << "segfault 3	"; //debugmg
					while (it != end && *it != '-')
					{
			std::cout << "segfault 4	"; //debugmg
						if (validMode.find(*it) != std::string::npos)
						{
			std::cout << "segfault 5	"; //debugmg
							if (addedParams.find(*it) == std::string::npos)
							{
			std::cout << "segfault 6	"; //debugmg
								/* ################ reprendre ici avec parsing des params0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 */
								addedParams += *it;
			std::cout << "list of added params : " << addedParams << std::endl; //debugmg
							}
						}
						else
							ctx._client.addToWriteBuffer(ERR_UNKNOWNCOMMAND(ctx._client.getNickname()));
						it++;
						i++;
					}
				}
			}

			std::cout << "list of added params : " << addedParams << std::endl; //debugmg
		}
	}

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
