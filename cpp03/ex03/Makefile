CPP = c++
CFragS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Iinclude -g

SRC_CORE = src/DiamondTrap.cpp src/FragTrap.cpp src/ClapTrap.cpp src/ScavTrap.cpp

BCLAP_SRCS = test/BasicTestsClap.cpp $(SRC_CORE)
BSCAV_SRCS = test/BasicTestsScav.cpp $(SRC_CORE)
BFRAG_SRCS = test/BasicTestsFrag.cpp $(SRC_CORE)
BDIAM_SRCS = test/BasicTestsDiamond.cpp $(SRC_CORE)
MCLAP_SRCS = test/MemberFunctionsClapTest.cpp $(SRC_CORE)
MSCAV_SRCS = test/MemberFunctionsScavTest.cpp $(SRC_CORE)
MFRAG_SRCS = test/MemberFunctionsFragTest.cpp $(SRC_CORE)
MDIAM_SRCS = test/MemberFunctionsDiamondTrap.cpp $(SRC_CORE)

BCLAP_OBJS = $(BCLAP_SRCS:.cpp=.o)
BSCAV_OBJS = $(BSCAV_SRCS:.cpp=.o)
BFRAG_OBJS = $(BFRAG_SRCS:.cpp=.o)
BDIAM_OBJS = $(BDIAM_SRCS:.cpp=.o)
MCLAP_OBJS = $(MCLAP_SRCS:.cpp=.o)
MSCAV_OBJS = $(MSCAV_SRCS:.cpp=.o)
MFRAG_OBJS = $(MFRAG_SRCS:.cpp=.o)
MDIAM_OBJS = $(MDIAM_SRCS:.cpp=.o)

NAME = exec

all: $(NAME)

$(NAME): $(BDIAM_OBJS)
	$(CPP) $(BDIAM_OBJS) -o $(NAME)

basicclap: $(BCLAP_OBJS)
	$(CPP) $(BCLAP_OBJS) -o $(NAME)

basicscav: $(BSCAV_OBJS)
	$(CPP) $(BSCAV_OBJS) -o $(NAME)

basicfrag: $(BFRAG_OBJS)
	$(CPP) $(BFRAG_OBJS) -o $(NAME)

memberclap: $(MCLAP_OBJS)
	$(CPP) $(MCLAP_OBJS) -o $(NAME)

memberscav: $(MSCAV_OBJS)
	$(CPP) $(MSCAV_OBJS) -o $(NAME)

memberfrag: $(MFRAG_OBJS)
	$(CPP) $(MFRAG_OBJS) -o $(NAME)

memberdiam: $(MDIAM_OBJS)
	$(CPP) $(MDIAM_OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFragS) -c $< -o $@

clean:
	rm -f $(BCLAP_OBJS) $(BSCAV_OBJS) $(BFRAG_OBJS) $(MCLAP_OBJS) $(BFRAG_OBJS) $(MFRAG_OBJS) $(MDIAM_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re basicclap memberclap memberscav memberfrag memberdiam