# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:17:53 by mgirardo          #+#    #+#              #
#    Updated: 2022/01/18 17:36:03 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	\
			ft_printf.c \
			ft_putchar.c \
			ft_putpurcent.c \
			ft_putstr.c \
			ft_strlen.c \
			is_variable.c \
			print_c.c \
			print_s.c \
			print_variable.c \
			what_variable.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.c}

${NAME}		${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
