CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS = test/BasicTests.cpp src/ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)

MEMBER_SRCS = test/MemberFunctionsTests.cpp src/ClapTrap.cpp
MEMBER_OBJS = $(MEMBER_SRCS:.cpp=.o)

NAME = exec

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

clap: $(MEMBER_OBJS)
	$(CPP) $(MEMBER_OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(MEMBER_OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

phony: all clean fclean re clap
