SRC		=	main.cpp \
			AAnimal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp \
			Brain.cpp

OBJ		=	${SRC:.cpp=.o}

DOBJ	=	${SRC:.cpp=.d}

NAME	=	SmartAAnimal

INCL	=	AAnimal.hpp \
			Cat.hpp \
			Dog.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp \
			Brain.hpp

PP		=	g++

FLAG	=	-g -Werror -Wall -Wextra -Wno-unused -MMD -std=c++98

RM		=	rm -rf

all:		${NAME}

-include ${DOBJ}

.cpp.o:
				${PP} ${FLAG} -I -include -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJ} ${INCL}
				${PP} ${FLAG} ${OBJ} -o ${NAME}

clean:	
				${RM} ${OBJ} ${DOBJ}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all .cpp.o clean fclean re