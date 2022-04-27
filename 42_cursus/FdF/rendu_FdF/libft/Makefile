# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 14:53:41 by mgirardo          #+#    #+#              #
#    Updated: 2022/01/04 17:25:10 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ce makefie va devoir allier le makefile qui creer un ecxecutable et les regles de creation dune lib.a du type 'ar rc' et dautres
#faire regle specifique pour les bonus avec comme nom "_bonus.{c/h}."

#gcc -c *.c			transforme les *.c en *.o
#ar rc libft.a *.o		va integrer les *.o a notre libft.a, attention a toujours utiliser le prefixe lib...
#ranlib libft.a			permet de creer un index dans la bibliotheque pour optimiser le temps dexecution du programme
#nm -s ${NAME}			permet de lister lindex aue lon vient de creer avec ranlib
#gcc main.c -L. -lft		-L. permet de faire appelle a une bibliotheque lors de la compilation, -lft represente le nom du *.a que lon veut utiliser

#variables declarer avec '='

#regles declarer avec ':'

SRCS	=	fdf_get_next_line.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_printf.c \
			ft_ptf_put.c \
			ft_ptf_start_to_put.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c

OBJS	= 	${SRCS:.c=.o}

OBJSB	= 	${SRCSB:.c=.o}

NAME	= 	libft.a

#mettre gcc au lieu de cc

CC		= 	gcc

CFLAGS	= 	-Wall -Werror -Wextra

RM		=	 rm -f

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

#permet au programme dexecuter la regle meme si un fichier du meme nom existe

.PHONY:		all clean fclean re bonus
