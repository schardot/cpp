CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Iinclude -g

SRC = src/Bureaucrat.cpp src/Form.cpp

TEST_BUREAUCRAT = test/BureaucratTest.cpp
TEST_FORM = test/FormTest.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_BUREAUCRAT = $(OBJ) $(TEST_BUREAUCRAT:.cpp=.o)
OBJ_FORM = $(OBJ) $(TEST_FORM:.cpp=.o)


BIN_BUREAUCRAT = BureaucratTest
BIN_FORM = FormTest

.PHONY: all clean fclean re bureaucrattest formtest

all: bureaucrattest formtest

bureaucrattest: $(OBJ_BUREAUCRAT)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BUREAUCRAT)

formtest: $(OBJ_FORM)
	$(CPP) $(CFLAGS) $^ -o $(BIN_FORM)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) \
		$(TEST_BUREAUCRAT:.cpp=.o) \
		$(TEST_FORM:.cpp=.o)

fclean: clean
	rm -f $(BIN_BUREAUCRAT) $(BIN_FORM)

re: fclean all
