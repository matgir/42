# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 14:53:41 by mgirardo          #+#    #+#              #
#    Updated: 2022/01/04 17:25:10 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ce makefie va devoir allier le makefile qui creer un ecxecutable et les regles de creation dune lib.a du type 'ar rc' et dautres
#faire regle specifique pour les bonus avec comme nom "_bonus.{c/h}."

#gcc -c *.c			transforme les *.c en *.o
#ar rc libft.a *.o		va integrer les *.o a notre libft.a, attention a toujours utiliser le prefixe lib...
#ranlib libft.a			permet de creer un index dans la bibliotheque pour optimiser le temps dexecution du programme
#nm -s ${NAME}			permet de lister lindex aue lon vient de creer avec ranlib
#gcc main.c -L. -lft		-L. permet de faire appelle a une bibliotheque lors de la compilation, -lft represente le nom du *.a que lon veut utiliser

#variables declarer avec '='

#regles declarer avec ':'

SRCS	=	*.c

OBJS	= 	${SRCS:.c=.o}

NAME	= 	CHOOSE NAME OF THE EXECUTABLE

#mettre gcc au lieu de cc

CC		= 	gcc

CFLAGS	= 	-Wall -Werror -Wextra

RM		=	 rm -f

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
		${RM} ${OBJS} ${OBJSB}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

#permet au programme dexecuter la regle meme si un fichier du meme nom existe
.PHONY:		all clean fclean re 
