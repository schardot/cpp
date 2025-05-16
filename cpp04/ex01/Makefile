CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Iinclude -g

SRC = src/Animal.cpp src/Cat.cpp src/Dog.cpp src/WrongAnimal.cpp src/WrongCat.cpp src/Brain.cpp

TEST_BANIMAL = test/BasicAnimal.cpp
TEST_BCAT = test/BasicCat.cpp
TEST_BDOG = test/BasicDog.cpp
TEST_INHERITANCE = test/InheritanceTest.cpp
TEST_BRAIN = test/BrainTest.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_BANIMAL = $(OBJ) $(TEST_BANIMAL:.cpp=.o)
OBJ_BCAT = $(OBJ) $(TEST_BCAT:.cpp=.o)
OBJ_BDOG = $(OBJ) $(TEST_BDOG:.cpp=.o)
OBJ_INHERITANCE = $(OBJ) $(TEST_INHERITANCE:.cpp=.o)
OBJ_BRAIN = $(OBJ) $(TEST_BRAIN:.cpp=.o)

BIN_BANIMAL = BasicAnimalTest
BIN_BCAT = BasicCatTest
BIN_BDOG = BasicDogTest
BIN_INHERITANCE = InheritanceTest
BIN_BRAIN = BrainTest

.PHONY: all clean fclean re \
	basicanimal basiccat basicdog inheritancetest braintest

all: basicanimal basiccat basicdog inheritancetest braintest

basicanimal: $(OBJ_BANIMAL)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BANIMAL)

basiccat: $(OBJ_BCAT)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BCAT)

basicdog: $(OBJ_BDOG)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BDOG)

inheritancetest: $(OBJ_INHERITANCE)
	$(CPP) $(CFLAGS) $^ -o $(BIN_INHERITANCE)

braintest: $(OBJ_BRAIN)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BRAIN)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) \
		$(TEST_BANIMAL:.cpp=.o) \
		$(TEST_BCAT:.cpp=.o) \
		$(TEST_BDOG:.cpp=.o) \
		$(TEST_INHERITANCE:.cpp=.o) \
		$(TEST_BRAIN:.cpp=.o)

fclean: clean
	rm -f $(BIN_BANIMAL) $(BIN_BCAT) $(BIN_BDOG) $(BIN_INHERITANCE) $(BIN_BRAIN)

re: fclean all
