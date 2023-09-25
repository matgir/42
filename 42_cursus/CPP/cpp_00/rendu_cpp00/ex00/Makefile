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

OBJ		=	${SRC:.c=.o}

# DOBJ	=	${SRC:.c=.d}

NAME	=	megaphone

#INCL	=	

PP		=	g++

FLAG	=	-g -Werror -Wall -Wextra -Wno-unused
# FLAG	=	-g -Werror -Wall -Wextra -Wno-unused -MMD

RM		=	rm -rf

all:		${NAME}


# -include ${DOBJ}

.c.o:
				${PP} ${FLAG} -c $< -o $(<:.c=.o)
#				${PP} ${FLAG} -I -include -c $< -o $(<:.c=.o)

${NAME}:	${OBJ} ${INC}
				${PP} ${FLAG} ${OBJ} -o ${NAME}

norm:
			norminette

clean:
				${RM} ${OBJ}
#				${RM} ${OBJ} ${DOBJ}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all .c.o norm clean fclean re