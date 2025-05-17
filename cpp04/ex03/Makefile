CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Iinclude -g

SRC = src/AMateria.cpp src/Character.cpp src/Cure.cpp src/Ice.cpp src/MateriaSource.cpp

TEST_MATERIASOURCE = test/MateriaSourceTest.cpp
TEST_CHARACTER = test/CharacterTest.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_MATERIASOURCE = $(OBJ) $(TEST_MATERIASOURCE:.cpp=.o)
OBJ_CHARACTER = $(OBJ) $(TEST_CHARACTER:.cpp=.o)

BIN_MATERIASOURCE = MateriaSourceTest
BIN_CHARACTER = CharacterTest

.PHONY: all clean fclean re materiasourcetest charactertest

all: materiasourcetest charactertest

materiasourcetest: $(OBJ_MATERIASOURCE)
	$(CPP) $(CFLAGS) $^ -o $(BIN_MATERIASOURCE)

charactertest: $(OBJ_CHARACTER)
	$(CPP) $(CFLAGS) $^ -o $(BIN_CHARACTER)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) \
		$(TEST_MATERIASOURCE:.cpp=.o) \
		$(TEST_CHARACTER:.cpp=.o)

fclean: clean
	rm -f $(BIN_MATERIASOURCE) $(BIN_CHARACTER)

re: fclean all
