NAME = ortodox

BUILD = build

HEADERS = Fixed.hpp\

C++ = c++

CPP_FLAGS = #-Wall -Wextra -Werror -std=c++98

SRC =	main.cpp Fixed.cpp\

OBJ =  $(addprefix build/, $(SRC:.cpp=.o))

all: $(NAME)
$(NAME) : $(OBJ)
	$(C++) $(CPP_FLAGS) $(OBJ) -o $(NAME) 

$(BUILD)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(C++) $(CPP_FLAGS) -c $< -o $@
	
clean:
	@rm -rf $(BUILD)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all