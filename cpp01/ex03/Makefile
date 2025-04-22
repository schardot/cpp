CPP = c++
CFLAGS = -Wall -std=c++11 -g

SRCS =  main.cpp  Weapon.cpp  HumanA.cpp  HumanB.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = violence

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJS)

fclean: clean
	rm -f $(OBJS)

re: clean all

phony: all clean fclean re