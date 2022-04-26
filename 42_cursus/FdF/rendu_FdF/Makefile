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
#	ar rc lib***.a *.o		va integrer les *.o a notre libft.a, attention a toujours
#							utiliser le prefixe lib...
#	ranlib li***.a			permet de creer un index dans la bibliotheque pour optimiser
#							le temps dexecution du programme
#	nm -s ${NAME}			permet de lister lindex que lon vient de creer avec ranlib
#	gcc main.c -L. -l***	permet de faire appelle a une bibliotheque lors de la
#							compilation, -lft represente le nom du *.a que lon veut
#							utiliser

#	variables declarer avec '='

#	regles declarer avec ':'

SRCS	=	*.c

OBJS	= 	${SRCS:.c=.o}

NAME	= 	fdf

#	mettre gcc au lieu de cc

CC		= 	gcc

CFLAGS	= 	-Wall -Werror -Wextra

RM		=	 rm -f

#	demander ce qui est mieux, 'rm -f' ou 'rm -rf'

.c.o:	
			${CC} ${CFLAGS} -I/usr/include -Iminilibx-linux -03 -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${OBJS} -Lminilibx-linux -lminilibx-linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

#	permet au programme dexecuter la regle meme si un fichier du meme nom existe

.PHONY:		all clean fclean re 
