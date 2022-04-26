# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:17:53 by mgirardo          #+#    #+#              #
#    Updated: 2022/01/20 16:25:45 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_ptf_put.c \
			ft_ptf_start_to_put.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
