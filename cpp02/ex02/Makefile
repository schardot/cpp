CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

MANDATORY_SRCS = Mandatory.cpp Fixed.cpp
MANDATORY_OBJS = $(MANDATORY_SRCS:.cpp=.o)

NAME = fixed

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

mandatory: $(MANDATORY_OBJS)
	$(CPP) $(MANDATORY_OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(MANDATORY_OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)

re: clean all

phony: all clean fclean re mandatory
