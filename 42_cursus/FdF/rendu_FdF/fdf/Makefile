# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 18:27:40 by mgirardo          #+#    #+#              #
#    Updated: 2022/04/26 18:27:42 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_fdf_split.c \
			parsing_map.c \
			print_window.c

OBJS	= 	${SRCS:.c=.o}


NAME	= 	fdf

#mettre gcc au lieu de cc

CC		= 	gcc

CFLAGS	= 	-Wall -Werror -Wextra

RM		=	 rm -f

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

#permet au programme dexecuter la regle meme si un fichier du meme nom existe

.PHONY:		all clean fclean re bonus