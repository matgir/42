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

SRCS	=	Sources/server.c \
			Sources/server_utils.c

SRCSC	=	Sources/client.c \
			Sources/client_utils.c

OBJS	=	${SRCS:.c=.o}

OBJSC	=	${SRCSC:.c=.o}

INCL	=	-I./libft

NAME	=	server

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra -g3

RM		=	rm -f

OTHER	=	client

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

${OTHER}:	${LIBFT} ${OBJSC}
			${CC} -o ${OTHER} ${OBJSC} ${LIBFT}

${NAME}:	${OBJS} ${LIBFT} ${OTHER}
			${CC} -o ${NAME} ${OBJS} ${LIBFT}

clean:		libftc
			${RM} ${OBJS} ${OBJSC}

fclean:		clean libftfc
			${RM} ${NAME} ${OTHER}

re:			fclean all

.PHONY:		all clean fclean re libftc libftfc
