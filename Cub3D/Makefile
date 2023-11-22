# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 12:44:14 by amehrotr          #+#    #+#              #
#    Updated: 2023/11/21 00:17:52 by ahsalam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

SRC =	srcs/mandatory/main.c srcs/mandatory/check.c srcs/mandatory/exit.c srcs/mandatory/movement.c \
		srcs/mandatory/check_utils.c srcs/mandatory/ft_spliting.c srcs/mandatory/init_game_map.c srcs/mandatory/init_game_win.c \
		srcs/mandatory/parse_img.c srcs/mandatory/parse_map.c srcs/mandatory/read_map.c srcs/mandatory/RGB_format.c srcs/mandatory/rotation.c \
		srcs/mandatory/raycasting_process.c srcs/mandatory/raycasting_texture.c

BONUS_SRC =	srcs/bonus/main.c srcs/bonus/check.c srcs/bonus/exit.c srcs/bonus/movement.c \
		srcs/bonus/check_utils.c srcs/bonus/ft_spliting.c srcs/bonus/init_game_map.c srcs/bonus/init_game_win.c \
		srcs/bonus/parse_img.c srcs/bonus/parse_map.c srcs/bonus/read_map.c srcs/bonus/RGB_format.c srcs/bonus/rotation.c \
		srcs/bonus/raycasting_process.c srcs/bonus/raycasting_texture.c srcs/bonus/minimap_bonus.c srcs/bonus/mouse_bonus.c \

OBJ = ${SRC:%.c=%.o}

BONUS_OBJ = ${BONUS_SRC:%.c=%.o}

LIBFTFOLDER = include/Libft

LIBFT = $(LIBFTFOLDER)/libft.a

FLAGS = -Wall -Wextra -Werror -I include

all : library $(NAME)

bonus : library $(NAME_BONUS)


library :
		@if [ ! -f $(LIBFT) ]; then \
		echo "\n🚀 Start of program compilation 🚀\n"; \
		make -C $(LIBFTFOLDER); \
		fi

$(NAME) : $(LIBFT) $(OBJ)
		@gcc $(FLAGS) $(SRC) $(LIBFT) -o $(NAME) -L include/mlx -lmlx -framework OpenGL -framework Appkit

$(NAME_BONUS) : $(LIBFT) $(BONUS_OBJ)
		@gcc $(FLAGS) $(BONUS_SRC) $(LIBFT) -o $(NAME_BONUS) -L include/mlx -lmlx -framework OpenGL -framework Appkit

%.o : %.c
		@${CC} ${FLAGS} -c $< -o $@

clean :
		@rm -f $(OBJ) $(BONUS_OBJ)
		@make clean -C $(LIBFTFOLDER)
		@echo "✅ Simple clean completed!"


fclean : clean
		@rm -f $(NAME) $(NAME_BONUS) $(LIBFT)
		@echo "✅ Deep clean completed!"

re : fclean all

rebonus : fclean bonus

.PHONY : all bonus norm library clean fclean re