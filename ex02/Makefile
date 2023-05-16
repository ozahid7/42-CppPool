NAME = AForm

OBJECTS = objects

HEADERS = Bureaucrat.hpp Form.hpp

C++ = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp\
 		Bureaucrat.cpp\
		Form.cpp\

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
