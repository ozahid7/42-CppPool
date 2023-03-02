NAME = MyAwesomePhoneBook

BUILD = build

HEADER = MyAwesomePhoneBook.hpp

C++ = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = MyAwesomePhoneBook.cpp\

OBJ = $(addprefix build/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(C++) $(CPP_FLAGS) $(OBJ) -o $(NAME) 

build/%.o: %.cpp
	@mkdir -p $(@D)
	$(C++) $(CPP_FLAGS) -c $(SRC) -o $(OBJ)
	
clean:
	@rm -rf $(BUILD)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all