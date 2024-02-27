# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 16:18:23 by amehrotr          #+#    #+#              #
#    Updated: 2023/07/31 18:03:40 by amehrotr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FLAGS = -Wall -Wextra -Werror -std=c99

SRC = ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_putnbr_fd.c \
			ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			get_next_line.c get_next_line_utils.c ft_putptr.c ft_putstr.c ft_putunbr.c \
			ft_printf.c ft_putchar.c ft_puthexa_low.c ft_puthexa_up.c ft_putnbr.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o : %.c
		cc $(C_FLAGS) -c $< -o $@

clean : 
		rm -f $(OBJ) $(OBJ_B) $(OBJ_GNL)

fclean : clean
		rm -f $(NAME)

re : fclean all