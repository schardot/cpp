CPP = c++
CFLAGS = -Wall -std=c++11 -g

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = phonebook

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean: rm -f $(NAME) $(OBJS)

cleanf: clean
	rm -f $(OBJS)

re: clean all

phony: clean cleanf re all