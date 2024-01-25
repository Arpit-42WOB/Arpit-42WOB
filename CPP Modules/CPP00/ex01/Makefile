# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 16:22:18 by amehrotr          #+#    #+#              #
#    Updated: 2024/01/25 10:41:20 by amehrotr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

SRC = Contact.cpp PhoneBook.cpp main.cpp src.cpp

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