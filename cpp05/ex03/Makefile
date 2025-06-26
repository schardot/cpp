CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Iinclude -g

SRC = src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp src/Intern.cpp

TEST_BUREAUCRAT = test/BureaucratTest.cpp
TEST_SCHRUB = test/ShrubberyTest.cpp
TEST_ROB = test/RobotomyTest.cpp
TEST_PRES = test/PresidentialTest.cpp
TEST_INT = test/InternTest.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_BUREAUCRAT = $(OBJ) $(TEST_BUREAUCRAT:.cpp=.o)
OBJ_SCHRUB = $(OBJ) $(TEST_SCHRUB:.cpp=.o)
OBJ_ROB = $(OBJ) $(TEST_ROB:.cpp=.o)
OBJ_PRES = $(OBJ) $(TEST_PRES:.cpp=.o)
OBJ_INT = $(OBJ) $(TEST_INT:.cpp=.o)

BIN_BUREAUCRAT = BureaucratTestBin
BIN_SCHRUB = SchrubTestBin
BIN_ROB = RobotomyTestBin
BIN_PRES = PresidentialTestBin
BIN_INT = InternTestBin

.PHONY: all clean fclean re bureaucrattest schrubtest robotomytest presidentialtest interntest

all: bureaucrattest schrubtest robotomytest presidentialtest interntest

bureaucrattest: $(OBJ_BUREAUCRAT)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BUREAUCRAT)

schrubtest: $(OBJ_SCHRUB)
	$(CPP) $(CFLAGS) $^ -o $(BIN_SCHRUB)

robotomytest: $(OBJ_ROB)
	$(CPP) $(CFLAGS) $^ -o $(BIN_ROB)

presidentialtest: $(OBJ_PRES)
	$(CPP) $(CFLAGS) $^ -o $(BIN_PRES)

interntest: $(OBJ_INT)
	$(CPP) $(CFLAGS) $^ -o $(BIN_INT)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) \
		$(TEST_BUREAUCRAT:.cpp=.o) \
		$(TEST_SCHRUB:.cpp=.o) \
		$(TEST_ROB:.cpp=.o) \
		$(TEST_PRES:.cpp=.o) \
		$(TEST_INT:.cpp=.o)

fclean: clean
	rm -f $(BIN_BUREAUCRAT) $(BIN_SCHRUB) $(BIN_ROB) $(BIN_PRES) $(BIN_INT) *_shrubbery

re: fclean all
