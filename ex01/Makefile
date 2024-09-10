PROGRAM := phonebook

CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := main.cpp
OBJ := $(SRC:.cpp=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(PROGRAM)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(PROGRAM)

re: clean all

.PHONY: all clean fclean re
