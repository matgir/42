# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 15:49:18 by mgirardo          #+#    #+#              #
#    Updated: 2022/10/11 17:16:00 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	Sources/philo_free1.c \
			Sources/philo_free2.c \
			Sources/philo_god.c \
			Sources/philo_init.c \
			Sources/philo_parsing.c \
			Sources/philo_philo1.c \
			Sources/philo_philo2.c \
			Sources/philo_utils.c \
			Sources/philo.c

OBJS	=	${SRCS:.c=.o}

DOBJS	=	${SRCS:.c=.d}

NAME	=	philo

INCL	=	-I./Includes

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -lpthread -pthread -MMD

RM		=	rm -f

all:		${NAME}

-include $(DOBJS)
.c.o:	
			${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} ${DOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all .c.o clean fclean re
