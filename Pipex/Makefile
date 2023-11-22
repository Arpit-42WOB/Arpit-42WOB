# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 15:57:09 by amehrotr          #+#    #+#              #
#    Updated: 2023/09/20 11:36:01 by amehrotr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ORANGE		= 	\033[0;33m
GREEN		=	\033[0;32m
BLUE		=	\033[0;34m
YELLOW		=	\033[1;32m
RED			=	\033[0;31m
PURPLE		=	\033[0;35m
RESET		=	\033[0m
BOLD		= 	$(shell tput bold)

PROGRESS_WIDTH = 20
CURRENT_PROGRESS = 0
TOTAL_PROGRESS = $(words $(OBJ))
OS = Mac
PROGRESS_DONE_CHAR = 🟦
PROGRESS_TODO_CHAR = ⬛️

NAME = pipex

BONUS = pipex_bonus

SRC = pipex.c Mandatory/free.c Mandatory/init.c Mandatory/process.c Mandatory/utils.c \

BONUS_SRC = pipex_bonus.c Bonus/free_bonus.c Bonus/here_doc_bonus.c Bonus/init_bonus.c Bonus/process_bonus.c Bonus/utils_bonus.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT = Include/Libft/libft.a

FLAGS = -Wall -Wextra -Werror -g -I Include 

all: library $(NAME)
		@echo "$(YELLOW)--- $(NAME) Created Successfully ---$(RESET)"

bonus: library $(BONUS)
		@echo "$(YELLOW)--- $(NAME) Created Successfully ---$(RESET)"

library:
	@make -C Include/Libft

$(NAME): $(OBJ)
	@echo "$(BLUE)--- All Objects Created ---$(RESET)"
	@echo "$(YELLOW)--- Final Compilation Starts ---$(RESET)"
	@gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) -L Include

$(BONUS):$(BONUS_OBJ)
	@echo "$(BLUE)--- All Objects for Bonus Created ---$(RESET)"
	@echo "$(YELLOW)--- Final Compilation for Bonus Starts ---$(RESET)"
	@gcc $(FLAGS) $(BONUS_OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	@echo "$(BLUE)--- Compiling $@ ---$(RESET)"
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo "$(RED) $(BOLD)--- Cleaning Starts ---$(RESET)"
	@rm -f $(OBJ)
	@echo "$(RED)--- Objects Deleted ---$(RESET)"
	@rm -f $(BONUS_OBJ)
	@echo "$(RED)--- Bonus Objects Deleted ---$(RESET)"
	@make clean -C Include/Libft
	@echo "$(RED)--- LIBFT Objects Deleted ---$(RESET)"

fclean: clean
	@echo "$(PURPLE) $(BOLD)--- Full Cleaning Starts ---$(RESET)"
	@rm -f $(NAME)
	@make fclean -C Include/Libft
	@echo "$(PURPLE)--- All Object & Executable files Deleted ---$(RESET)"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus bonus library