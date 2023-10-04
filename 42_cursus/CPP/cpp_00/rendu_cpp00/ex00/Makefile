# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 17:31:42 by mgirardo          #+#    #+#              #
#    Updated: 2023/09/25 17:31:54 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	megaphone.cpp

OBJ		=	${SRC:.cpp=.o}

DOBJ	=	${SRC:.cpp=.d}

NAME	=	megaphone

INCL	=	Makefile

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