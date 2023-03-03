NAME = MyAwesomePhoneBook

BUILD = build

HEADER = PhoneBook.hpp  Contact.hpp\

C++ = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp PhoneBook.cpp Contact.cpp\

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(C++)  $(OBJ) -o $(NAME) 

build/%.o: %.cpp
	$(C++)  -c $(SRC) -o $(OBJ)
	
clean:
	@rm -rf $(BUILD)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all