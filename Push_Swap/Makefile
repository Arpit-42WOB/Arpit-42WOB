# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 12:54:37 by amehrotr          #+#    #+#              #
#    Updated: 2023/09/26 14:45:10 by amehrotr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
BONUS_NAME := checker

MANDATORY := push_swap.c \

BONUS := push_swap_bonus.c \

SRC := check_input.c get_next_line.c push_swap_bonus_utils.c push_swap_utils.c  \
		push.c rev_rotate.c rotate.c sort_utils.c split_utils.c  \
		stack_utils.c stack.c swap.c tiny_sort.c utils.c \

OBJ := ${SRC:%.c=%.o}

M_OBJ := ${MANDATORY:%.c=%.o}

B_OBJ := ${BONUS:%.c=%.o}

CC := cc

CFLAGS := -Wall -Wextra -Werror -g

INC := push_swap.h

all: ${NAME}

bonus: ${BONUS_NAME}

both: ${NAME} ${BONUS_NAME}

${NAME} : ${M_OBJ} ${OBJ} ${INC}
		@${CC} ${CFLAGS} ${M_OBJ} ${OBJ} -o ${NAME}

${BONUS_NAME} : ${B_OBJ} ${OBJ} ${INC}
				@${CC} ${CFLAGS} ${B_OBJ} ${OBJ} -o ${BONUS_NAME}

%.o:%.c
		@${CC} ${CFLAGS} -c $< -o $@
		
clean:
		@rm -f ${M_OBJ} ${B_OBJ} ${OBJ}

fclean: clean
		@rm -f ${NAME} ${BONUS_NAME}

re: fclean all

rebonus: fclean bonus

reboth: fclean all bonus

.PHONY: all bonus both clean fclean re rebonus reboth