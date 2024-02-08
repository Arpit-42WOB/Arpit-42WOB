# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 14:28:20 by amehrotr          #+#    #+#              #
#    Updated: 2024/02/06 14:29:03 by amehrotr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = clapTrap

SRC = clapTrap.cpp main.cpp

OBJ = ${SRC:%.cpp=%.o}

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

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