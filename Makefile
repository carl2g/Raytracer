CC		=	g++ -g3 -O3

RM		=	rm -rvf

NAME		=	raytracer

SRCS		=	src/main.cpp 		\
			src/SDLWin.cpp		\
			src/Camera.cpp 		\
			src/Sphere.cpp 		\
			src/Plane.cpp 		\
			src/Triangle.cpp	\
			src/ObjectManager.cpp 	\
			src/ObjParser.cpp 	\
			src/Obj.cpp

CFLAGS 		= 	-lSDL2 -lpthread -lm

OBJS		=	$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re

