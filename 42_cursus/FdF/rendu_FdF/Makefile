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
#	ranlib li***.a			permet de creer un index dans la bibliotheque pour
#							optimiser le temps dexecution du programme
#	nm -s ${NAME}			permet de lister lindex que lon vient de creer avec
#							ranlib
#	gcc main.c -L. -l***	permet de faire appelle a une bibliotheque lors de
#							la compilation, -lft represente le nom du *.a que
#							lon veut utiliser

#	variables declarer avec '='

#	regles declarer avec ':'

SRCS	=	sources/ft_fdf_split.c \
			sources/parsing_map.c \
			sources/print_window.c \
			sources/fdf_get_next_line.c

OBJS	=	${SRCS:.c=.o}

INCL	=	-I./libft -I./minilibx-linux

NAME	=	fdf

#	mettre gcc au lieu de cc

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g3

RM		=	rm -f

LIBFT	=	libft/libft.a

LIBMLX	=	minilibx-linux/libmlx_Linux.a

CMPMLX	=	-lXext -lX11 -lm -lz -lbsd -Lmath

#	demander ce qui est mieux, 'rm -f' ou 'rm -rf'

.c.o:	
			${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

all:		${NAME}

${LIBFT}:
			${MAKE} -C libft all

libftc:
			${MAKE} -C libft clean

libftfc:
			${MAKE} -C libft fclean

${LIBMLX}:
			${MAKE} -C minilibx-linux all

libmlxc:
			${MAKE} -C minilibx-linux clean

${NAME}:	${OBJS} ${LIBFT} ${LIBMLX}
			${CC} -o ${NAME} ${OBJS} ${LIBFT} ${LIBMLX} ${CMPMLX}

clean:		libftc libmlxc
			${RM} ${OBJS}

fclean:		clean libftfc
			${RM} ${NAME}

re:			fclean all

#	permet au programme dexecuter la regle meme si un fichier du meme nom existe

.PHONY:		all clean fclean re 
