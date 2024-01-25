# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 13:27:28 by amehrotr          #+#    #+#              #
#    Updated: 2024/01/25 10:32:51 by amehrotr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp

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