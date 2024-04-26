NAME = Bureaucrat

SRC = Bureaucrat.cpp Form.cpp main.cpp

OBJ = ${SRC:%.cpp=%.o}

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
		$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
		$(CPP) $(FLAGS) -c $< -o $@

clean :
		rm -f $(OBJ)
		
fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean flean re