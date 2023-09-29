# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 16:00:03 by amehrotr          #+#    #+#              #
#    Updated: 2023/08/09 19:42:45 by amehrotr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRC = so_long.c Mandatory_Utils/read_map.c Mandatory_Utils/game.c Mandatory_Utils/check.c Mandatory_Utils/error.c \
			Mandatory_Utils/move.c Mandatory_Utils/test_path.c Mandatory_Utils/exit.c \

OBJ = ${SRC:%.c=%.o}

BONUS_SRC = so_long_bonus.c Bonus_Utils/read_map.c Bonus_Utils/game.c Bonus_Utils/check.c Bonus_Utils/error.c \
			Bonus_Utils/move.c Bonus_Utils/test_path.c Bonus_Utils/exit.c Bonus_Utils/frame.c \

BONUS_OBJ = ${BONUS_SRC:%.c=%.o}

LIBFTFOLDER = include/Libft

LIBFT = $(LIBFTFOLDER)/libft.a

FLAGS = -Wall -Wextra -Werror -g -I include

all : library $(NAME)

bonus : library $(NAME_BONUS)

norm :
		norminette *.c ./include/Libft/*.c ./include/*.h ./Bonus_Utils/*.c ./Mandatory_Utils/*.c

library :
		make -C $(LIBFTFOLDER)

$(NAME) : $(LIBFT) $(OBJ)
		gcc $(FLAGS) $(SRC) $(LIBFT) -o $(NAME) -L include/mlx -lmlx -framework OpenGL -framework Appkit

$(NAME_BONUS) : $(LIBFT) $(BONUS_OBJ)
		gcc $(FLAGS) $(BONUS_SRC) $(LIBFT) -o $(NAME_BONUS) -L include/mlx -lmlx -framework OpenGL -framework Appkit

%.o : %.c
		@${CC} ${FLAGS} -c $< -o $@

clean :
		@rm -f $(OBJ) $(BONUS_OBJ)
		make clean -C $(LIBFTFOLDER)

fclean : clean
		@rm -f $(NAME) $(NAME_BONUS) $(LIBFT)

re : fclean all

rebonus : fclean bonus

.PHONY : all bonus norm library clean fclean re