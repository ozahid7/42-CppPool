NAME = megaphone

BUILD = build

C++ = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp\

OBJ = $(addprefix build/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME) : $(OBJ)
	$(C++) $(CPP_FLAGS) $(OBJ) -o $(NAME)

build/%.o: %.cpp
	@mkdir -p $(@D)
	$(C++) $(CPP_FLAGS) -c $< -o $@
clean:
	@rm -rf $(BUILD)
	@echo "Cleaned"
fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all