SRC		=	main.cpp \
			Base.cpp \
			# Identify.cpp

OBJ		=	${SRC:.cpp=.o}

DOBJ	=	${SRC:.cpp=.d}

NAME	=	Identifier

INCL	=	A.hpp \
			B.hpp \
			C.hpp \
			Base.hpp \
			# Identify.h

PP		=	c++

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