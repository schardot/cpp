CPP = c++

NAME = phonebook
SRCS = contact.cpp main.cpp phonebook.cpp
CFLAGS = -Wall -std=c++11 -g

all: $(NAME)

$(NAME):
	$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all