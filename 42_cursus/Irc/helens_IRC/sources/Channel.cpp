/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:51:52 by Helene            #+#    #+#             */
/*   Updated: 2024/12/17 19:30:06 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Channel.hpp"


// ######## CONSTRUCTORS & ASSIGNMENT ######


Channel::Channel() : _topic(""), _topicRestrictionMode(0), _inviteOnlyMode(0),
	_passwordMode(0), _userLimitMode(0) {}

Channel::Channel(const Channel& other)
{
	this->_members = other._members;
	this->_operators = other._operators;
	this->_name = other._name;
	this->_topic = other._topic;
	this->_topicRestrictionMode = other._topicRestrictionMode;
	this->_inviteOnlyMode = other._inviteOnlyMode;
	this->_invitedUsers = other._invitedUsers;
	this->_passwordMode = other._passwordMode;
	this->_password = other._password;
	this->_userLimitMode = other._userLimitMode;
	this->_userLimit = other._userLimit;
	// this->_founder = other._founder;
}

Channel::Channel(const std::string& name, Client* member) : _topic(""),
	_topicRestrictionMode(0), _inviteOnlyMode(0), _passwordMode(0),
	_userLimitMode(0)
{
	this->_name = name;
	this->_members[member->getNickname()] = member; 
	this->_operators[member->getNickname()] = member;
	// this->_founder = member->getNickname();
	// std::cout << "at channel creation founder is : " << this->_founder << "\n"; //debugmg
}

Channel::~Channel() {}

// Channel& Channel::operator = (const Channel& other)
Channel& Channel::operator = (Channel& other) //debugmg
{
	// this->_members = other._members;
	this->_members = other.getAllMembers();
	// this->_operators = other._operators;
	this->_operators = other.getAllOperators();
	// this->_name = other._name;
	this->_name = other.getName();
	// this->_topic = other._topic;
	this->_topic = other.getTopic();
	// this->_topicRestrictionMode = other._topicRestrictionMode;
	this->_topicRestrictionMode = other.getTopicRestrictionMode();
	// this->_inviteOnlyMode = other._inviteOnlyMode;
	this->_inviteOnlyMode = other.getInviteOnlyMode();
	// this->_invitedUsers = other._invitedUsers;
	this->_invitedUsers = other.getInvitedUsers();
	// this->_passwordMode = other._passwordMode;
	this->_passwordMode = other.getPasswordMode();
	// this->_password = other._password;
	this->_password = other.getPassword();
	// this->_userLimitMode = other._userLimitMode;
	this->_userLimitMode = other.getUserLimitMode();
	// this->_userLimit = other._userLimit;
	this->_userLimit = other.getUserLimit();
	// this->_founder = other._founder;
	return (*this);
}



// ######## MEMBER METHODS #################


bool Channel::isMember(const std::string& nick)
{
	std::map<std::string, Client*>::const_iterator it;

	it = this->_members.find(nick);
	if (it != this->_members.end())
		return true;
	return false;
}

//Client &
Client* Channel::getMember(const std::string& nick)
{
	std::map<std::string, Client*>::iterator it;

	it = this->_members.find(nick);
	return (it->second);
}

unsigned int Channel::getNumberOfMembers()
{
	std::map<std::string, Client*>::iterator	it;
	int										n;

	n = 0;
	std::cout << "appel a getNumberOfMembers -1" << std::endl; //debugms
	for (it = this->_members.begin(); it != this->_members.end(); it++)
		n++;
	std::cout << "appel a getNumberOfMembers -2" << std::endl; //debugms
	return n;
}

void Channel::addMember(Client *client)
{
	this->_members[client->getNickname()] = client;
}

// void Channel::removeMember(std::string const& client)
// {
// 	std::map<std::string, Client*>::iterator	it;
 
// 	it = this->_members.find(client);
// 	std::cout << client << " was removed from channel " << this->getName() << '\n'; //debugmg
// 	this->_members.erase(it);
// }

void Channel::removeMember(std::string const& client)
{
	std::map<std::string, Client*>::iterator	it;

	it = this->_members.find(client);
	if (it == this->_members.end())
		return ;
	// this->_members[client] = NULL; // tocheck
	this->_members.erase(it);
	std::cout << client << " was removed from channel " << this->getName() << '\n'; //debugmg

	it = this->_operators.find(client);
	if (it == this->_operators.end())
		return ;
	this->_operators.erase(it);
}



// ######## OPERATOR METHODS ###############


bool Channel::isOperator(const std::string& nick)
{
	std::map<std::string, Client*>::const_iterator it;

	it = this->_operators.find(nick);
	if (it != this->_operators.end())
		return true;
	return false;
}

Client& Channel::getOperator(const std::string& nick)
{
	std::map<std::string, Client*>::iterator it;

	it = this->_operators.find(nick);
	return *(it->second);
}

unsigned int Channel::getNumberOfOperators()
{
	std::map<std::string, Client*>::iterator	it;
	int										n;

	n = 0;
	for (it = this->_operators.begin(); it != this->_operators.end(); it++)
		n++;
	return n;
}

void Channel::addOperator(Client *client)
{
	this->_operators[client->getNickname()] = client;
	std::cout << client->getNickname() << " was added to operators\n"; //debugmg
}

void 	Channel::removeOperator(std::string const& client)
{
	std::map<std::string, Client*>::iterator it;

	it = this->_operators.find(client);
	this->_operators.erase(it);
}


// ######## INVITED USER METHODS ###########

bool Channel::isInvited(const std::string& nick)
{
	// std::map<std::string, Client*>::const_iterator it;
	// it = this->_invitedUsers.find(nick);
	// if (it != this->_invitedUsers.end())
		// return true;
	// return false;
	
	std::vector<std::string>::const_iterator it;
	it = std::find(this->_invitedUsers.begin(), this->_invitedUsers.end(), nick);
	if (it != this->_invitedUsers.end())
		return true;
	return false;
}

// Client& Channel::getInvitedUser(const std::string& nick)
// {
// 	std::map<std::string, Client*>::iterator it;

// 	it = this->_invitedUsers.find(nick);
// 	return *(it->second);
// }

unsigned int Channel::getNumberOfInvitedUsers()
{
	return	this->_invitedUsers.size();
}

void	Channel::addInvitedUser(std::string const& client)
{
	this->_invitedUsers.push_back(client);
}

void 	Channel::removeInvitedUser(std::string const& client)
{
	std::vector<std::string>::iterator it;

	it = std::find(this->_invitedUsers.begin(), this->_invitedUsers.end(), client);
	if (it == this->_invitedUsers.end())
		return ;
	this->_invitedUsers.erase(it);
}

void	Channel::removeInviteList(void)
{
	this->_invitedUsers.clear();
}

// void Channel::addInvitedUser(Client *client)
// {
// 	this->_invitedUsers[client->getNickname()] = client;
// }

// void Channel::removeInvitedUser(const Client& client)
// {
// 	std::map<std::string, Client*>::iterator	it;

// 	it = this->_invitedUsers.find(client.getNickname());
// 	this->_invitedUsers.erase(it);
// }



// ########### OTHER METHODS ###############


const std::string& Channel::getName()
{
	return this->_name;
}

bool Channel::hasTopic()
{
	if (this->_topic.empty())
		return false;
	return true;
}

const std::string& Channel::getTopic()
{
	return this->_topic;
}

void 	Channel::setTopic(std::string const& newTopic)
{
	this->_topic = newTopic;
}

const bool& Channel::getTopicRestrictionMode()
{
	return this->_topicRestrictionMode;
}

void	Channel::setTopicRestrictionMode(bool mode)
{
	this->_topicRestrictionMode = mode;
}

const bool& Channel::getInviteOnlyMode()
{
	return this->_inviteOnlyMode;
}

void	Channel::setInviteOnlyMode(bool mode)
{
	this->_inviteOnlyMode = mode;
}

const bool& Channel::getPasswordMode()
{
	return this->_passwordMode;
}

void 	Channel::setPasswordMode(bool mode)
{
	this->_passwordMode = mode;
}

const std::string& Channel::getPassword()
{
	return this->_password;
}

void	Channel::setPassword(std::string const& passwd)
{
	this->_password = passwd;
}

const bool& Channel::getUserLimitMode()
{
	return this->_userLimitMode;
}

void 	Channel::setUserLimitMode(bool mode)
{
	this-> _userLimitMode = mode;
}

const unsigned int& Channel::getUserLimit()
{
	return this->_userLimit;
}

void 	Channel::setUserLimit(int const& limit)
{
	this->_userLimit = limit;
}

bool 	Channel::isFull()
{
	if (_userLimitMode && _members.size() >= _userLimit)
		return true;
	return false;
}

bool	Channel::isEmpty()
{
	return (!_members.size());
}

// ###########  ###############

// std::string		Channel::getFounder()
// {
// 	return this->_founder;
// }

// bool 			Channel::isFounder(std::string const& client)
// {
// 	return (client == _founder);
// }

Channel::members 	&Channel::getAllMembers(void)
{
	return this->_members;
}

Channel::operators	&Channel::getAllOperators(void)
{
	return this->_operators;
}

Channel::invitedUsers	&Channel::getInvitedUsers(void)
{
	return this->_invitedUsers;
}

void 	Channel::sendToAll(std::string const& client, std::string const& msg, bool excludeSource)
{
	for (members::iterator it = this->_members.begin(); it != this->_members.end(); it++)
	{
		if (it->first == client && excludeSource)
			continue;
		it->second->addToWriteBuffer(msg); // + CRLF ?
	}
}

void	Channel::sendToOperators(std::string const& client, std::string const& msg, bool excludeSource)
{
	for (members::iterator it = this->_operators.begin(); it != this->_operators.end(); it++)
	{
		if (it->first == client && excludeSource)
			continue;
		it->second->addToWriteBuffer(msg); // + CRLF ?
	}
}

void 	Channel::updateNickOnChannel(std::string const& oldNick, std::string const& newNick)
{
	Client *client = this->getMember(oldNick);
	
	this->_members.erase(oldNick);
	this->_members[newNick] = client;
	
	if (this->isOperator(oldNick))
	{
		this->_operators.erase(oldNick);
		this->_operators[newNick] = client;
	}

	if (this->isInvited(oldNick))
	{
		this->removeInvitedUser(oldNick);
		this->addInvitedUser(newNick);
	}
}