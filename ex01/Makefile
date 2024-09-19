PROGRAM := phonebook

CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := main.cc contact.cc phonebook.cc \

OBJ := $(SRC:.cc=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(PROGRAM)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(PROGRAM)

re: clean all

fmt:
	$(if $(SRC), clang-format --style=Google -i $(SRC))

.PHONY: all clean fclean re
