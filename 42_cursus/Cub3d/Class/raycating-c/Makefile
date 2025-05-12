SRC			=	main.c \
				####

OBJ			=	$(SRC:.c=.o)

DOBJ		=	${SRC:.c=.d}

NAME		=	#####

INC			=	#####

CC			=	cc

FLAG		=	-g -Wall -Werror -Wextra -MMD

RM			=	rm -f

all:		$(NAME)

-include ${DOBJ}

.c.o:
			$(CC) $(FLAG) -I include -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ) $(INC)
			$(CC) $(FLAG) $(OBJ) $() -o $(NAME)

bonus:		####
			####

clean:
			${RM} $(OBJ) ${DOBJ}

fclean:		clean
			${RM} $(NAME)

re:			fclean all 

.PHONY:		all clean fclean re .c.o


#### REGARDER MAKEFILE FDF POUR AIDE ####