CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Iinclude -g

SRC = src/Bureaucrat.cpp

TEST_BUREAUCRAT = test/BureaucratTest.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_BUREAUCRAT = $(OBJ) $(TEST_BUREAUCRAT:.cpp=.o)

BIN_BUREAUCRAT = BureaucratTest

.PHONY: all clean fclean re \


all: bureaucrattest

bureaucrattest: $(OBJ_BUREAUCRAT)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BUREAUCRAT)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) \
		$(TEST_BUREAUCRAT:.cpp=.o)

fclean: clean
	rm -f $(BIN_BUREAUCRAT)

re: fclean all
