NAME = MyAwesomePhoneBook

BUILD = build

HEADERS = PhoneBook.hpp  Contact.hpp

C++ = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp\
 		PhoneBook.cpp Contact.cpp\

OBJ =  $(addprefix build/, $(SRC:.cpp=.o))

all: $(NAME)
$(NAME) : $(OBJ)
	$(C++)  $(OBJ) -o $(NAME) 

$(BUILD)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(C++) -c $< -o $@
	
clean:
	@rm -rf $(BUILD)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all