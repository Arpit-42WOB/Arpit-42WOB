# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:35:03 by ahsalam           #+#    #+#              #
#    Updated: 2023/10/27 14:28:17 by amehrotr         ###   ########.fr        #
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

NAME = minishell

LIBFT = ./include/Libft/libft.a

FLAGS = -Wall -Wextra -Werror -I include -I include/Libft -g

LIB = -L/usr/include -lreadline

SRC =	src/main_file/main.c								\
		src/main_file/free_main.c							\
		src/main_file/free_end_stc.c						\
		src/main_file/special_char.c						\
		src/parsing/ft_is_builtin.c							\
		src/parsing/create_fill_lst/get_cmd_line.c			\
		src/parsing/lst_function/cmdl_add_back.c			\
		src/parsing/lst_function/len_cmd.c					\
		src/parsing/parsing_utils.c							\
		src/parsing/free_utils.c							\
		src/parsing/free_utils_2.c							\
		src/parsing/create_fill_lst/split_arg.c				\
		src/parsing/lst_function/init_token.c				\
		src/parsing/expend_word/expend_word.c				\
		src/parsing/expend_word/expend_word_utils.c			\
		src/parsing/expend_word/expend_word_utils1.c		\
		src/parsing/expend_word/develope_limitor.c			\
		src/parsing/expend_word/word_will_single.c			\
		src/parsing/expend_word/word_will_double.c			\
		src/parsing/expend_word/word_will_unquote.c			\
		src/parsing/get_env.c								\
		src/parsing/expend_word/fake_env.c					\
		src/parsing/expend_word/word_unquote_inter.c		\
		src/parsing/create_fill_lst/organise_arg.c			\
		src/parsing/lst_function/token_add_back.c			\
		src/exec/ft_exec.c									\
		src/exec/ft_exist.c									\
		src/exec/ft_lst_to_str.c							\
		src/exec/pipe.c										\
		src/exec/open_fd.c									\
		src/exec/utils.c									\
		src/exec/exec_free_utils.c							\
		src/exec/exec_free_utils1.c						\
		src/exec/exec_utils.c								\
		src/built_in/ft_add_value.c							\
		src/built_in/ft_built_in_export_fd.c				\
		src/built_in/ft_get_value.c							\
		src/built_in/ft_env_singletone.c					\
		src/built_in/ft_built_in.c							\
		src/built_in/ft_built_in_env_fd.c					\
		src/built_in/ft_built_in_echo.c						\
		src/built_in/ft_free_env.c							\
		src/built_in/ft_built_in_export.c					\
		src/built_in/ft_built_in_pwd.c						\
		src/built_in/ft_built_in_unset.c					\
		src/built_in/ft_built_in_cd.c						\
		src/built_in/ft_built_in_env.c						\
		src/built_in/ft_init_env.c							\
		src/built_in/ft_delete_key.c						\
		src/built_in/ft_gestion_error.c						\
		src/built_in/ft_built_in_pwd_fd.c					\
		src/built_in/ft_push_front.c						\
		src/built_in/ft_built_in_echo_fd.c					\
		src/built_in/builtin_free.c							\
		src/built_in/ft_built_in_export_2.c					\
		src/limitor/create_file.c							\
		src/limitor/open_heredoc.c							\

OBJ = ${SRC:.c=.o}

all: library $(NAME)

library:
	@if [ ! -f $(LIBFT) ]; then \
		echo "${YELLOW}\n🚀 Start of program compilation 🚀\n${ENDCOLOR}"; \
		make -C include/Libft; \
	fi

$(NAME): $(OBJ)
	@cc $(FLAGS) $(OBJ) $(LIB) $(LIBFT) -o $(NAME)
	@echo "${GREEN}✅ $(NAME) Compilation completed successfully! ✅${ENDCOLOR}"

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@echo "${RED}🧹 Cleaning objects... 🧹${ENDCOLOR}"
	@rm -f $(OBJ)
	@make -C include/Libft clean
	@echo "${CYAN}✅ Simple clean completed! ✨${ENDCOLOR}"

fclean: clean
	@echo "${RED}🧹 Cleaning program... 🧹${ENDCOLOR}"
	@rm -f $(NAME)
	@make -C include/Libft fclean
	@echo "${MAGENTA}✅ Deep clean completed! ✨${ENDCOLOR}"

re: fclean all

.PHONY: all clean fclean re
