SRC			=	main_cub3d.c \
				####

OBJ			=	$(SRC:.c=.o)

DOBJ		=	${SRC:.c=.d}

INC			=	-I./minilibx-linux

NAME		=	Cub3d

INCL		=	cub3d.h \
				Makefile \
				#####

CC			=	cc

FLAG		=	-g -Wall -Werror -Wextra -MMD -g3

RM			=	rm -f

LIBMLX		=	minilibx-linux/libmlx_Linux.a

CMPMLX		=	-lXext -lX11 -lm -lz -lbsd -Lmath

all:		$(NAME)

-include ${DOBJ}

.c.o:
##			$(CC) $(FLAG) ${INC} -c $< -o $(<:.c=.o)
			$(CC) ${INC} -c $< -o $(<:.c=.o)

${LIBMLX}:
			${MAKE} -C minilibx-linux all

libmlxclean:
			${MAKE} -C minilibx-linux clean

$(NAME):	$(OBJ) $(INCL) ${LIBMLX}
			$(CC) $(FLAG) $(OBJ) ${LIBMLX} ${CMPMLX} -o $(NAME)

bonus:		####
			####

clean:		libmlxclean
			${RM} $(OBJ) ${DOBJ}

fclean:		clean
			${RM} $(NAME)

re:			fclean all 

.PHONY:		all clean fclean re .c.o


#### REGARDER MAKEFILE FDF POUR AIDE ####