// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Channel.hpp                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/10/03 17:22:29 by hepompid          #+#    #+#             */
// /*   Updated: 2024/10/03 18:45:14 by hepompid         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#pragma once

#include "irc.hpp"
#include "Client.hpp"

typedef enum 
{
	Normal = 0,
	// Founder = 1 << 0,
	Operator = 1 << 1
}	e_memberState;

class Channel
{
    private:
        typedef std::map<std::string, Client*> members;
        typedef std::map<std::string, Client*> operators; // autre maniere de garder en memoire quels users sont operators, qui ne necessite pas une copie de leur nick ? car fait un truc de plus a changer qd user modifie son nick
		typedef std::vector<std::string> invitedUsers;
        
		members			_members;
		operators		_operators;
        std::string     _name;
        std::string     _topic;
        bool            _topicRestrictionMode; // MODE t
        bool            _inviteOnlyMode; // MODE i
		invitedUsers	_invitedUsers;
        bool            _passwordMode; // MODE k
        std::string     _password;
        bool            _userLimitMode; // MODE l
        unsigned int    _userLimit;
		// std::string 	_founder;
        
    public:
        Channel();
		Channel(const std::string& name, Client *client);
        Channel (const Channel& other);
        ~Channel();

        // Channel& operator = (const Channel& other);
        Channel& operator = (Channel& other); //debugmg

		bool				isMember(const std::string& nick);
        Client*				getMember(const std::string& nick);
		unsigned int		getNumberOfMembers();
		void				addMember(Client *client);
		void				removeMember(std::string const& client);

		bool				isOperator(const std::string& nick);
		Client& 			getOperator(const std::string& nick);
		unsigned int		getNumberOfOperators();
		void				addOperator(Client *client); // MODE o
		void				removeOperator(std::string const& client); // MODE o

		bool				isInvited(const std::string& nick); // MODE i
		// Client&				getInvitedUser(const std::string& nick);
		unsigned int		getNumberOfInvitedUsers(); // MODE i
		void				addInvitedUser(std::string const& client); // MODE i
		void				removeInvitedUser(std::string const& client); // MODE i
		void				removeInviteList(void);
		// void				addInvitedUser(Client *client);
		// void				removeInvitedUser(const Client& client);

		const std::string&	getName();
		bool				hasTopic();
		const std::string&	getTopic();
		void 				setTopic(std::string const& newTopic); // MODE t
		const bool&			getTopicRestrictionMode();
		void 				setTopicRestrictionMode(bool mode); // MODE t
		const bool&			getInviteOnlyMode();
		void 				setInviteOnlyMode(bool mode); // MODE i
		const bool&			getPasswordMode();
		void 				setPasswordMode(bool mode); // MODE k
		void 				setPassword(std::string const& passwd); // MODE k
		const std::string&	getPassword(); // MODE k
		const bool&			getUserLimitMode(); // MODE l
		void 				setUserLimitMode(bool mode); // MODE l
		const unsigned int&	getUserLimit();
		void 				setUserLimit(int const& limit); // MODE l ?
		bool 				isFull();
		bool 				isEmpty();

		// send the given message to all clients of this channel, excluding the client given as parameter
		void				sendToAll(std::string const& client, std::string const& msg, bool excludeSource = true);
		void 				sendToOperators(std::string const& client, std::string const& msg, bool excludeSource = true);
		members&			getAllMembers(void);
		operators&			getAllOperators(void);
		invitedUsers&		getInvitedUsers(void);
		// std::string 		getFounder();
		// bool 				isFounder(std::string const& client);
		void 				updateNickOnChannel(std::string const& oldNick, std::string const& newNick);
};
