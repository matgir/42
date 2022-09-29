# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 15:49:18 by mgirardo          #+#    #+#              #
#    Updated: 2022/09/13 15:49:30 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	Sources/philo2.c \
			Sources/philo_parsing.c

OBJS	=	${SRCS:.c=.o}

NAME	=	philo

CC		=	gcc -fsanitize=thread -g -lpthread -pthread -g3

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all:		${NAME}

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all .c.o clean fclean re

# CC		=	gcc -fsanitize=thread -g -lpthread -pthread -g3

