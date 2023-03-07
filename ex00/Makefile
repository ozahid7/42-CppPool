NAME = BraiiiiiiinnnzzzZ

OBJECTS = objects

HEADERS = Zombie.hpp  

C++ = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp\
 		newZombie.cpp randomChump.cpp Zombie.cpp\

OBJ =  $(addprefix build/, $(SRC:.cpp=.o))

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
