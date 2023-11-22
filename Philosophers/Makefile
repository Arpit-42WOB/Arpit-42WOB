# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 15:38:47 by amehrotr          #+#    #+#              #
#    Updated: 2023/11/06 19:17:25 by amehrotr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m
ENDCOLOR		= \033[0m

NAME = philo

FLAGS = -Wall -Wextra -Werror -I include -g #-fsanitize=thread

SRC =	srcs/main.c srcs/init.c srcs/check_input.c \
		srcs/time_and_exit.c srcs/threads.c \

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@cc $(FLAGS) $(OBJ) -o $(NAME)
	@echo "${GREEN}✅ $(NAME) Compilation completed successfully! ✅${ENDCOLOR}"

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@echo "${RED}🧹 Cleaning objects... 🧹${ENDCOLOR}"
	@rm -f $(OBJ)
	@echo "${CYAN}✅ Simple clean completed! ✨${ENDCOLOR}"

fclean: clean
	@echo "${RED}🧹 Cleaning program... 🧹${ENDCOLOR}"
	@rm -f $(NAME)
	@echo "${MAGENTA}✅ Deep clean completed! ✨${ENDCOLOR}"

re: fclean all

.PHONY: all clean fclean re
