CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =  Zombie.cpp main.cpp zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = horde

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)

re: clean all

phony: all clean fclean re
