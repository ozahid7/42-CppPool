NAME =  Sed
OBJECTS = objects

C++ = c++

HEADERS = Change.hpp Read.hpp sed.hpp\

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp Read.cpp Change.cpp Write.cpp\

OBJ =  $(addprefix objects/, $(SRC:.cpp=.o))

all: $(NAME)
$(NAME) : $(OBJ)
	$(C++) $(CPP_FLAGS) $(OBJ) -o $(NAME) 

$(OBJECTS)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(C++) $(CPP_FLAGS) -c $< -o $@
	
clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all
