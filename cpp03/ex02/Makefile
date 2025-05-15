CPP = c++
CFragS = -Wall -Werror -Wextra -std=c++98 -Iinclude -g

SRC_CORE = src/FragTrap.cpp src/ClapTrap.cpp src/ScavTrap.cpp

BCLAP_SRCS = test/BasicTestsClap.cpp $(SRC_CORE)
BSCAV_SRCS = test/BasicTestsScav.cpp $(SRC_CORE)
BFrag_SRCS = test/BasicTestsFrag.cpp $(SRC_CORE)
MCLAP_SRCS = test/MemberFunctionsClapTest.cpp $(SRC_CORE)
MSCAV_SRCS = test/MemberFunctionsScavTest.cpp $(SRC_CORE)
MFrag_SRCS = test/MemberFunctionsFragTest.cpp $(SRC_CORE)

BCLAP_OBJS = $(BCLAP_SRCS:.cpp=.o)
BSCAV_OBJS = $(BSCAV_SRCS:.cpp=.o)
BFrag_OBJS = $(BFrag_SRCS:.cpp=.o)
MCLAP_OBJS = $(MCLAP_SRCS:.cpp=.o)
MSCAV_OBJS = $(MSCAV_SRCS:.cpp=.o)
MFrag_OBJS = $(MFrag_SRCS:.cpp=.o)

NAME = exec

all: $(NAME)

$(NAME): $(BFrag_OBJS)
	$(CPP) $(BFrag_OBJS) -o $(NAME)

basicclap: $(BCLAP_OBJS)
	$(CPP) $(BCLAP_OBJS) -o $(NAME)

basicscav: $(BSCAV_OBJS)
	$(CPP) $(BSCAV_OBJS) -o $(NAME)

memberclap: $(MCLAP_OBJS)
	$(CPP) $(MCLAP_OBJS) -o $(NAME)

memberscav: $(MSCAV_OBJS)
	$(CPP) $(MSCAV_OBJS) -o $(NAME)

memberFrag: $(MFrag_OBJS)
	$(CPP) $(MFrag_OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFragS) -c $< -o $@

clean:
	rm -f $(BCLAP_OBJS) $(BSCAV_OBJS) $(BFrag_OBJS) $(MCLAP_OBJS) $(BFrag_OBJS) $(MFrag_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re basicclap memberclap memberscav
