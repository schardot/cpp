CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =  main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = replace

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) *.replace

fclean: clean
	rm -f $(NAME) $(OBJS)

re: clean all

phony: all clean fclean re
