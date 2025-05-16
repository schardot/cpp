CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Iinclude -g

# Source files for the classes (adjust paths as needed)
SRC = src/Animal.cpp src/Cat.cpp src/Dog.cpp src/WrongAnimal.cpp src/WrongCat.cpp

# Test source files
TEST_BANIMAL = test/BasicAnimal.cpp
TEST_BCAT = test/BasicCat.cpp
TEST_BDOG = test/BasicDog.cpp
TEST_INHERITANCE = test/InheritanceTest.cpp

# Object files for classes
OBJ = $(SRC:.cpp=.o)

# Object files for tests + classes
OBJ_BANIMAL = $(OBJ) $(TEST_BANIMAL:.cpp=.o)
OBJ_BCAT = $(OBJ) $(TEST_BCAT:.cpp=.o)
OBJ_BDOG = $(OBJ) $(TEST_BDOG:.cpp=.o)
OBJ_INHERITANCE = $(OBJ) $(TEST_INHERITANCE:.cpp=.o)

# Executables named after tests
BIN_BANIMAL = BasicAnimalTest
BIN_BCAT = BasicCatTest
BIN_BDOG = BasicDogTest
BIN_INHERITANCE = InheritanceTest

.PHONY: all clean fclean re \
	basicanimal basiccat basicdog inheritancetest

all: basicanimal basiccat basicdog inheritancetest


basicanimal: $(OBJ_BANIMAL)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BANIMAL)

basiccat: $(OBJ_BCAT)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BCAT)

basicdog: $(OBJ_BDOG)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BDOG)

inheritancetest: $(OBJ_INHERITANCE)
	$(CPP) $(CFLAGS) $^ -o $(BIN_INHERITANCE)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) \
		$(TEST_BANIMAL:.cpp=.o) \
		$(TEST_BCAT:.cpp=.o) \
		$(TEST_BDOG:.cpp=.o) \
		$(TEST_INHERITANCE:.cpp=.o)

fclean: clean
	rm -f $(BIN_BANIMAL) $(BIN_BCAT) $(BIN_BDOG) $(BIN_INHERITANCE)

re: fclean all
