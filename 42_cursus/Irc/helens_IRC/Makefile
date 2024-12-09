# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 14:23:25 by Helene            #+#    #+#              #
#    Updated: 2024/11/02 15:50:23 by hlesny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv
CC = g++ # c++ ? std::string incomplete type error when compiling using c++ 
CFLAGS = -std=c++98 -Wall -Wextra -g3 #-v (verbose) #-Werror -fsanitize=address
RM = rm -f

SRCS_DIR = ./sources/
OBJS_DIR = ./objects/
INCS_DIR = ./includes/

SRCS = 	main.cpp \
		Server.cpp \
		Server_pollins.cpp \
		Server_pollouts.cpp \
		Server_pollerr.cpp \
		Client.cpp \
		Channel.cpp \
		Logger.cpp \
		CommandsHandler.cpp \
		commands/registration/pass.cpp \
		commands/registration/user.cpp \
		commands/registration/nick.cpp \
		commands/registration/registration.cpp \
		commands/channels_operations/join.cpp \
		commands/channels_operations/part.cpp \
		commands/channels_operations/invite.cpp \
		commands/channels_operations/kick.cpp \
		commands/channels_operations/topic.cpp \
		commands/channels_operations/utils.cpp \
		commands/motd.cpp \
		commands/ping.cpp \
		commands/quit.cpp \
		commands/privmsg.cpp \
		# commands/mode.cpp \
		# commands/mode.cpp \
		# commands/help.cpp 
		
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
DEPS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.d))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)commands/
	mkdir -p $(OBJS_DIR)commands/registration/
	mkdir -p $(OBJS_DIR)commands/channels_operations/
	$(CC) $(CFLAGS) -MMD -I $(INCS_DIR) -c $< -o $@ 

-include $(DEPS)

clean : 
	$(RM) -r $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

docker :
	docker build -t debian .
	docker run -it -v /Users/Helene/Desktop/42/42-projets/42--IRC_and_doc:$$HOME/irc debian
	# docker run -it -v /mnt/nfs/homes/hlesny/42/42cursus/ft_IRC_and_docs:$$HOME/irc debian 

dclean :
	docker rm $$(docker ps -aq);
	docker rmi $$(docker image ls -q)
	yes | docker container prune 
	yes | docker image prune 

re : fclean all

.PHONY:
	all clean fclean re