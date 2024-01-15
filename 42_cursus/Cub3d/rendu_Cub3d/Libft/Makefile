SRC =  ft_isalpha.c		\
	ft_calloc.c		\
	ft_atoi.c		\
	ft_isalnum.c		\
	ft_strlen.c		\
	ft_strncmp.c		\
	ft_strdup.c		\
	ft_toupper.c		\
	ft_tolower.c		\
	ft_strrchr.c		\
	ft_strchr.c		\
	ft_strnstr.c		\
	ft_strlcat.c		\
	ft_memset.c		\
	ft_isdigit.c		\
	ft_isprint.c		\
	ft_strlcpy.c		\
	ft_memcpy.c		\
	ft_memmove.c		\
	ft_memchr.c		\
	ft_bzero.c		\
	ft_memcmp.c		\
	ft_isascii.c	        \
	ft_strtrim.c	        \
	ft_strjoin.c			\
	ft_putchar_fd.c	        \
	ft_putstr_fd.c	        \
	ft_putnbr_fd.c			\
	ft_putendl_fd.c			\
	ft_split.c              \
	ft_split_utils.c        \
	ft_itoa.c               \
	ft_substr.c   \
        ft_striteri.c \
        ft_strmapi.c \
        ft_printf.c		\
	ft_printf_utils.c	\
	ft_printf_utils2.c	\
	get_next_line.c \
	get_next_line_utils.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c

BONUS = ft_lstnew.c		\
	ft_lstadd_front.c	\
	ft_lstsize.c		\
	ft_lstlast.c		\
	ft_lstadd_back.c	\
	ft_lstdelone.c		\
	ft_lstclear.c		\
	ft_lstiter.c		\
	ft_lstmap.c		\

CC	= gcc

CFLAGS = -Wall -Werror -Wextra -g3

OBJ = ${SRC:.c=.o}

BONUSOBJ = ${BONUS:.c=.o}

NAME = libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}

bonus: ${OBJ} ${BONUSOBJ}
	ar -rcs ${NAME} ${OBJ} ${BONUSOBJ}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)


.PHONY: all clean fclean re
