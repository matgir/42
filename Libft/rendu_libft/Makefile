# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 14:53:41 by mgirardo          #+#    #+#              #
#    Updated: 2021/12/07 16:11:37 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ce makefie va devoir allier le makefile qui creer un ecxecutable et les regles de creation dune lib.a du type 'ar rc' et dautres

#gcc -c *.c			transforme les *.c en *.o
#ar rc libft.a *.o		va integrer les *.o a notre libft.a, attention a toujours utiliser le prefixe lib...
#ranlib libft.a			permet de creer un index dans la bibliotheque pour optimiser le temps dexecution du programme
#gcc main.c -L. -lft		-L. permet de faire appelle a une bibliotheque lors de la compilation, -lft represente le nom du *.a que lon veut utiliser

SRCS	= !!!

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

RM	= rm -f

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

#faire regle specifique pour les bonus avec comme nom "_bonus.{c/h}."

.PHONY:		all clean fclean re
