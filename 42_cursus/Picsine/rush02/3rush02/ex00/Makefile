# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/22 14:57:28 by mgirardo          #+#    #+#              #
#    Updated: 2021/08/22 22:45:38 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main2.c ft_chek_arg.c split.c aff_all.c ft_putchar.c parsing.c ten_power.c ten_ten.c solo_char.c triple_zero.c free_tab.c free_all.c ft_check_error.c ft_lcmparsing.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
