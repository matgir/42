# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 16:05:21 by mgirardo          #+#    #+#              #
#    Updated: 2023/10/03 16:05:23 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ContactClass.cpp \
			main.cpp \
			PhoneBookClass.cpp

OBJ		=	${SRC:.cpp=.o}

DOBJ	=	${SRC:.cpp=.d}

NAME	=	MyAwesomePhoneBook

INCL	=	ContactClass.hpp PhoneBookClass.hpp Makefile

PP		=	g++

FLAG	=	-g -Werror -Wall -Wextra -Wno-unused -MMD -std=c++98

RM		=	rm -rf

all:		${NAME}

-include ${DOBJ}

.cpp.o:
				${PP} ${FLAG} -I -include -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJ} ${INCL}
				${PP} ${FLAG} ${OBJ} -o ${NAME}

clean:	
				${RM} ${OBJ} ${DOBJ}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all .cpp.o clean fclean re