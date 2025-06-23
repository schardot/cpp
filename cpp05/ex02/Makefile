CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Iinclude -g

SRC = src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp

TEST_BUREAUCRAT = test/BureaucratTest.cpp
TEST_FORM = test/FormTest.cpp
TEST_SCHRUB = test/ShrubberyTest.cpp
TEST_ROB = test/RobotomyTest.cpp
TEST_PRES = test/PresidentialTest.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_BUREAUCRAT = $(OBJ) $(TEST_BUREAUCRAT:.cpp=.o)
OBJ_FORM = $(OBJ) $(TEST_FORM:.cpp=.o)
OBJ_SCHRUB = $(OBJ) $(TEST_SCHRUB:.cpp=.o)
OBJ_ROB = $(OBJ) $(TEST_ROB:.cpp=.o)
OBJ_PRES = $(OBJ) $(TEST_PRES:.cpp=.o)

BIN_BUREAUCRAT = BureaucratTestBin
BIN_FORM = FormTestBin
BIN_SCHRUB = SchrubTestBin
BIN_ROB = RobotomyTestBin
BIN_PRES = PresidentialTestBin

.PHONY: all clean fclean re bureaucrattest formtest schrubtest robotomytest presidentialtest

all: bureaucrattest formtest schrubtest robotomytest presidentialtest

bureaucrattest: $(OBJ_BUREAUCRAT)
	$(CPP) $(CFLAGS) $^ -o $(BIN_BUREAUCRAT)

formtest: $(OBJ_FORM)
	$(CPP) $(CFLAGS) $^ -o $(BIN_FORM)

schrubtest: $(OBJ_SCHRUB)
	$(CPP) $(CFLAGS) $^ -o $(BIN_SCHRUB)

robotomytest: $(OBJ_ROB)
	$(CPP) $(CFLAGS) $^ -o $(BIN_ROB)

presidentialtest: $(OBJ_PRES)
	$(CPP) $(CFLAGS) $^ -o $(BIN_PRES)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) \
		$(TEST_BUREAUCRAT:.cpp=.o) \
		$(TEST_FORM:.cpp=.o) \
		$(TEST_SCHRUB:.cpp=.o) \
		$(TEST_ROB:.cpp=.o) \
		$(TEST_PRES:.cpp=.o)

fclean: clean
	rm -f $(BIN_BUREAUCRAT) $(BIN_FORM) $(BIN_SCHRUB) $(BIN_ROB) $(BIN_PRES) *_shrubbery

re: fclean all
