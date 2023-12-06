# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 15:56:46 by mgirardo          #+#    #+#              #
#    Updated: 2022/04/26 15:56:47 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	gcc -c *.c				transforme les *.c en *.o
#	ar rc lib***.a *.o		va integrer les *.o a notre libft.a, attention a 
#							toujours utiliser le prefixe lib...
#	ranlib lib***.a			permet de creer un index dans la bibliotheque pour
#							optimiser le temps dexecution du programme
#	nm -s ${NAME}			permet de lister lindex que lon vient de creer avec
#							ranlib
#	gcc main.c -L. -l***	permet de faire appelle a une bibliotheque lors de
#							la compilation, -lft represente le nom du *.a que
#							lon veut utiliser

#	variables declarer avec '='

#	regles declarer avec ':'

SRCS	=	microshell.c

OBJS	=	${SRCS:.c=.o}

NAME	=	microshell

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra -g3

RM		=	rm -f

#	demander ce qui est mieux, 'rm -f' ou 'rm -rf'

.c.o:	
			${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:		libftc
			${RM} ${OBJS}

fclean:		clean libftfc
			${RM} ${NAME}

re:			fclean all

#	permet au programme dexecuter la regle meme si un fichier du meme nom existe

.PHONY:		all clean fclean re libftc libftfc
