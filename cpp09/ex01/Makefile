CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Iinclude -g

NAME = RPN
SRC = src/main.cpp src/RPN.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
