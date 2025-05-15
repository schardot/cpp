CPP = c++
CFragS = -Wall -Werror -Wextra -std=c++98 -Iinclude -g

SRC_CORE = src/ClapTrap.cpp src/ScavTrap.cpp

BCLAP_SRCS = test/BasicTestsClap.cpp $(SRC_CORE)
BSCAV_SRCS = test/BasicTestsScav.cpp $(SRC_CORE)
MCLAP_SRCS = test/MemberFunctionsClapTest.cpp $(SRC_CORE)
MSCAV_SRCS = test/MemberFunctionsScavTest.cpp $(SRC_CORE)

BCLAP_OBJS = $(BCLAP_SRCS:.cpp=.o)
BSCAV_OBJS = $(BSCAV_SRCS:.cpp=.o)
MCLAP_OBJS = $(MCLAP_SRCS:.cpp=.o)
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
	$(CPP) $(CFragS) -c $< -o $@

clean:
	rm -f $(BCLAP_OBJS) $(BSCAV_OBJS) $(MCLAP_OBJS) $(MSCAV_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re basicclap memberclap memberscav
