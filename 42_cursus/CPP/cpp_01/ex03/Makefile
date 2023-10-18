SRC		=	main.cpp \
			HumanA.cpp \
			HumanB.cpp \
			Weapon.cpp

OBJ		=	${SRC:.cpp=.o}

DOBJ	=	${SRC:.cpp=.d}

NAME	=	Fight

# INCL	=	HumanA.h HumanA.hpp HumanB.h HumanB.hpp Weapon.h Weapon.hpp
INCL	=	HumanA.h HumanA.hpp HumanB.h HumanB.hpp Weapon.h Weapon.hpp Makefile

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