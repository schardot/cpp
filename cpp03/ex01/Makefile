CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS = ScavTest.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)

BCLAP_SRCS = BasicTestsClap.cpp ClapTrap.cpp ScavTrap.cpp
BCLAP_OBJS = $(BCLAP_SRCS:.cpp=.o)

BSCAV_SRCS = BasicTestsScav.cpp ClapTrap.cpp ScavTrap.cpp
BSCAV_OBJS = $(BSCAV_SRCS:.cpp=.o)

MCLAP_SRCS = MemberFunctionsClapTest.cpp ClapTrap.cpp ScavTrap.cpp
MCLAP_OBJS = $(MCLAP_SRCS:.cpp=.o)

MSCAV_SRCS = MemberFunctionsScavTest.cpp ClapTrap.cpp ScavTrap.cpp
MSCAV_OBJS = $(MSCAV_SRCS:.cpp=.o)

NAME = exec

all: $(NAME)

$(NAME): $(BSCAV_OBJS)
	$(CPP) $(BSCAV_OBJS) -o $(NAME)

basicclap: $(BCLAP_OBJS)
	$(CPP) $(BCLAP_OBJS) -o $(NAME)

memberclap: $(MCLAP_OBJS)
	$(CPP) $(MCLAP_OBJS) -o $(NAME)

memberscav: $(MSCAV_OBJS)
	$(CPP) $(MSCAV_OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BCLAP_OBJS) $(BSCAV_OBJS) $(MCLAP_OBJS) $(MSCAV_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re basicclap memberclap memberscav
