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
	std::string						activeMode = "+";
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
	if (!operatorsList.empty())
		activeMode.append("o");
	
	ctx._client.addToWriteBuffer(RPL_CHANNELMODEIS(clientName, channelName, activeMode, kParams, lParams));

	std::stringstream	ss;
	std::string			prefix;
	ss << RPL_NAMREPLY(clientName, "=", channelName);

	for (std::map<std::string, Client*>::iterator it = chan->getAllOperators().begin(), end = chan->getAllOperators().end(); it != end; it++)
	{
		prefix = getPrefix(*it->second, *chan);
		if (it != chan->getAllOperators().begin())
			ss << " ";
		ss << prefix << it->first;
	}	
	ss << CRLF;
	ctx._client.addToWriteBuffer(ss.str());
	return;
}

void	addModeWithoutParam(char mode, Channel *chan)
{
	if (mode == 'i')
		chan->setInviteOnlyMode(true);
	else
		chan->setTopicRestrictionMode(true);
	return;
}

bool	isStrAllDigit(std::string str)
{
	for (unsigned long int i = 0; str[i]; i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

bool	parseModeWithParams(char mode, std::string param, Channel *chan)
{
	if (param.empty())
		return false;
	else if (mode == 'o' && chan->isMember(param) && !chan->isOperator(param))
		return true;
	else if (mode == 'l' && isStrAllDigit(param))
	{
		unsigned long int	i = std::atol(param.c_str());
		if (i > 4294967295)
			return false;
		else
			return true;
	}
	else if (mode == 'k' && !param.empty())
		return true;
	else
		return false;
}

void	addModeWithParam(char mode, std::string param, Channel *chan, Client *client)
{
	if (mode == 'o')
		chan->addOperator(client);
	else if (mode == 'l')
	{
		chan->setUserLimitMode(true);
		chan->setUserLimit(std::atol(param.c_str()));
	}
	else
	{
		chan->setPasswordMode(true);
		chan->setPassword(param);
	}
}

void	removeMode(char mode, Channel *chan)
{
	if (mode == 'i')
	{
		chan->setInviteOnlyMode(false);
		chan->removeInviteList();
	}
	else if (mode == 't')
		chan->setTopicRestrictionMode(false);
	else if (mode == 'k')
		chan->setPasswordMode(false);
	else
		chan->setUserLimitMode(false);
}

void	channelMode(CommandContext &ctx)
{
	std::string	channelName = ctx._parameters[0];
	if (!ctx._server.getChannel(channelName))
		ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), channelName));
	else if (!ctx._server.getChannel(channelName)->isMember(ctx._client.getNickname()))
		ctx._client.addToWriteBuffer(ERR_NOTONCHANNEL(ctx._client.getNickname(), channelName));
	else if (ctx._parameters.size() == 1)
		channelModeIs(ctx);
	else if (!ctx._server.getChannel(channelName)->isOperator(ctx._client.getNickname()))
		ctx._client.addToWriteBuffer(ERR_CHANOPRIVSNEEDED(ctx._client.getNickname(), channelName));
	else
	{
		std::string	mode = ctx._parameters[1];
		std::string	validMode = "itkol";
		std::string	addedParams;
		std::string	removedParams;
		Channel		*chan = ctx._server.getChannel(channelName);

		addedParams.clear();
		removedParams.clear();

		std::vector<std::string>	modeParams(ctx._parameters.begin() + 2, ctx._parameters.end());
		std::string::const_iterator	it = mode.begin();
		std::string::const_iterator	end = mode.end();
		unsigned int				sizeMode = mode.size();
			
		for (unsigned int i = 0; i < sizeMode; i++)
		{
			if (*it == '+')
			{
				while (it != end && *it != '-')
				{
					if (validMode.find(*it) != std::string::npos)
					{
						if (addedParams.find(*it) == std::string::npos)
						{
							if (*it == 'i' || *it == 't')
							{
								addModeWithoutParam(*it, chan);
								chan->sendToAll(ctx._client.getNickname(), RPL_MODEMSG(ctx._client.getUserID(), chan->getName(), "+" + *it), false);
					 			addedParams += *it;
							}
							else
							{
								if (!modeParams.empty() && parseModeWithParams(*it, modeParams[0], chan))
								{
									addModeWithParam(*it, modeParams[0], chan, ctx._server.getChannel(channelName)->getMember(modeParams[0]));
									chan->sendToAll(ctx._client.getNickname(), RPL_MODEMSG(ctx._client.getUserID(), chan->getName(), "+" + *it + " " + modeParams[0]), false);
									modeParams.erase(modeParams.begin());
									if (*it != 'o')
										addedParams += *it;
								}
								else
									ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), channelName));
							}
						}
					}
					else
					{
						if (*it != '+')
						{
							std::string	umode;
							umode += *it;
							ctx._client.addToWriteBuffer(ERR_UNKNOWNMODE(umode, channelName));
						}
					}
					it++;
					i++;
				}
			}
			else
			{
				while (it != end && *it != '+')
				{
					if (validMode.find(*it) != std::string::npos)
					{
						if (removedParams.find(*it) == std::string::npos)
						{
							if (*it == 'o' && !modeParams.empty())
							{
								if (chan->isMember(modeParams[0]) && chan->isOperator(modeParams[0]))
								{
									chan->removeOperator(modeParams[0]);
									chan->sendToAll(ctx._client.getNickname(), RPL_MODEMSG(ctx._client.getUserID(), chan->getName(), "-" + *it + " " + modeParams[0]), false);
									modeParams.erase(modeParams.begin());
								}
								else
									ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), channelName));
							}
							else
							{
								removeMode(*it, chan);
								chan->sendToAll(ctx._client.getNickname(), RPL_MODEMSG(ctx._client.getUserID(), chan->getName(), "-" + *it), false);
								removedParams += *it;
							}
						}
					}
					else
					{
						if (*it != '-')
						{
							std::string	umode;
							umode += *it;
							ctx._client.addToWriteBuffer(ERR_UNKNOWNMODE(umode, channelName));
						}
					}
					it++;
					i++;
				}
			}
		}
	}
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
	{
		Client	*client = ctx._server.getClientByNick(ctx._parameters[0]);
		if (!client)
			ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), ctx._parameters[0]));
	}
}

