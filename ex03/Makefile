CC = c++
FLAGS =  -Wall -Wextra -Werror
SRCS = main.cpp Coordinate.cpp

OBJ = $(SRCS:.cpp=.o)
RM = rm -f
NAME = gcode

%.o: %.cpp 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) Coordinate.hpp
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME) $(OBJ)

re: fclean all
