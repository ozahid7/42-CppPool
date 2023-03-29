NAME = Brain

OBJECTS = objects

HEADERS =  Animal.hpp Brain.hpp Cat.hpp Dog.hpp WrongCat.hpp\
 		WrongAnimal.hpp\

C++ = c++

CPP_FLAGS = #-Wall -Wextra -Werror -std=c++98

SRC =	main.cpp Brain.cpp Animal.cpp Cat.cpp Dog.cpp WrongCat.cpp\
 		WrongAnimal.cpp\

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
