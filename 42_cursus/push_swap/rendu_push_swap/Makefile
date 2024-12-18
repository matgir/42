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

SRCS	=	Sources/fill_stack_a.c \
			Sources/lst_pair_utils.c \
			Sources/lst_ps_utils.c \
			Sources/main.c \
			Sources/median.c \
			Sources/parsing_ps.c \
			Sources/print_stack.c \
			Sources/push.c \
			Sources/reverse_rotate.c \
			Sources/rotate.c \
			Sources/small_big.c \
			Sources/sort_small_stack.c \
			Sources/swap.c \
			Sources/swaping.c \
			Sources/to_the_top.c \
			Sources/utils.c \
			Sources/utils2.c \
			Sources/utils3.c

SRCSB	=	Sources/checker_utils.c \
			Sources/checker.c \
			Sources/fill_stack_a.c \
			Sources/lst_pair_utils.c \
			Sources/lst_ps_utils.c \
			Sources/median.c \
			Sources/parsing_ps.c \
			Sources/print_stack.c \
			Sources/push.c \
			Sources/reverse_rotate.c \
			Sources/rotate.c \
			Sources/small_big.c \
			Sources/sort_small_stack.c \
			Sources/swap.c \
			Sources/swaping.c \
			Sources/to_the_top.c \
			Sources/utils.c \
			Sources/utils2.c \
			Sources/utils3.c

OBJS	=	${SRCS:.c=.o}

OBJSB	=	${SRCSB:.c=.o}

INCL	=	-I./libft

NAME	=	push_swap

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra -g3

RM		=	rm -f

BONUS	=	checker

#	demander ce qui est mieux, 'rm -f' ou 'rm -rf'

LIBFT	=	libft/libft.a

.c.o:	
			${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

all:		${NAME}

${LIBFT}:
			${MAKE} -C libft all

libftc:
			${MAKE} -C libft clean

libftfc:
			${MAKE} -C libft fclean

${BONUS}:	${LIBFT} ${OBJSB}
			${CC} -o ${BONUS} ${OBJSB} ${LIBFT}

${NAME}:	${OBJS} ${LIBFT} ${BONUS}
			${CC} -o ${NAME} ${OBJS} ${LIBFT}

clean:		libftc
			${RM} ${OBJS} ${OBJSB}

fclean:		clean libftfc
			${RM} ${NAME} ${BONUS} ${OBJSB}

re:			fclean all

#	permet au programme dexecuter la regle meme si un fichier du meme nom existe

.PHONY:		all clean fclean re libftc libftfc
