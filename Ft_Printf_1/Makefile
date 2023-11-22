# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 12:11:59 by amehrotr          #+#    #+#              #
#    Updated: 2023/06/02 16:44:42 by amehrotr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar.c ft_puthexa_low.c ft_puthexa_up.c ft_putnbr.c \
		ft_putptr.c ft_putstr.c ft_putunbr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o : %.c
		gcc $(C_FLAGS) -c $< -o $@

clean : 
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all