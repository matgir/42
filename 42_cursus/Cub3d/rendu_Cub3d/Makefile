# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itahani <itahani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 12:17:10 by itahani           #+#    #+#              #
#    Updated: 2024/01/14 18:23:30 by itahani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PARSING = ./src/parsing/

INIT = ./src/init/

UTILS = ./src/utils/

RAYCASTING = ./src/raycasting/

RENDERING = ./src/rendering/

SRCS =	main.c							\
		${PARSING}parsing.c				\
		${PARSING}wall_parsing.c		\
		${PARSING}check_error.c			\
		${PARSING}map_content.c			\
		${PARSING}elem_parsing.c		\
		${PARSING}elem_parsing_utils.c	\
		${PARSING}extensions.c			\
		${PARSING}walkable_path.c		\
		${INIT}init_map.c				\
		${INIT}init_render.c			\
		${INIT}init_render_utils.c		\
		${INIT}player_setup.c			\
		${UTILS}free.c					\
		${UTILS}utils.c					\
		${UTILS}split.c					\
		${UTILS}bresenham.c				\
		${RAYCASTING}rays.c				\
		${RAYCASTING}rays_utils.c		\
		${RENDERING}render_walls.c		\
		${RENDERING}renders.c			\
		${RENDERING}render_floor_ceiling.c	\
		${RENDERING}texture.c			\
		./src/key_hook.c				\
		./src/draw_map.c				\

SRCSB = 


OBJS	=	${SRCS:%.c=%.o}

OBJSB	=	${SRCSB:%.c=%.o}

DEPS	=	${OBJS:%.o=%.d}
DEPSB	=	${OBJSB:%.o=%.d}

INCL	=	-I ./Libft

NAME	=	cub3D

CC		=	gcc -g #-fsanitize=address

CFLAGS	=	-Wall -Werror -Wextra
CPPFLAGS=	-MMD

RM		=	rm -f

BONUS	=	bonus_cub3D

LIBFT	=	-L ./Libft/. -lft

MLX		=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 


all:		${NAME}

%.o: %.c
	$(CC) ${CPPFLAGS} ${CFLAGS} -I Libft/. -I /usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}:	${OBJS} Libft/libft.a mlx_linux/libmlx_Linux.a
			${CC} ${CPPFLAGS} ${CFLAGS} -o $@ $^ ${LIBFT} ${MLX}

-include ${DEPS}
bonus:	${BONUS}

${BONUS}:	${OBJSB} Libft/libft.a mlx_linux/libmlx_Linux.a
			${CC} ${CFLAGS} -o $@ $^ ${LIBFT} ${MLX}

-include ${DEPSB}
Libft/libft.a:
	make -C Libft

mlx_linux/libmlx_Linux.a:
	make -C mlx_linux

clean:
	make -C Libft clean
	make -C mlx_linux clean
	${RM} ${OBJS} ${OBJSB} ${DEPS} ${DEPSB}

fclean:		clean
	make -C Libft fclean
	${RM} ${NAME} ${BONUS}

re:			fclean
	make all

.PHONY:		all clean fclean re libftc libftfc bonus
