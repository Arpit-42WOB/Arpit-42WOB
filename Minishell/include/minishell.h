/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:37:13 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/27 11:59:53 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "Libft/libft.h"
# include <signal.h>
# include <stdbool.h>
# include <string.h> 
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h> 
# include "struct.h"

/*     ****main_file****    */
int			print_exit_free_env_all(t_command_line **cmd);
int			free_all_env_str_ret_malloc_error(t_command_line **cmd, char *str);
int			free_all_error(t_command_line **cmd, char *str, int error);
void		free_end(t_command_line **cmd, char *str);
int			free_str_all_ret_malloc_error(t_command_line **cmd, char *str);
void		free_token(t_command_line **cmd_line);
int			free_all(t_command_line **cmd_line);
void		error_str(void);
void		signal_cmd(int sig);
void		handle_signals(void);
int			print_error_msg_pipe(char *str);
int			print_error_msg_ampresent(char *str);
int			print_error_msg_closing_brace(char *str);
int			print_error_msg_closing_square(char *str);
int			print_error_msg_closing_curly(char *str);
void		handle_signals(void);
/*     ****limitor****    */
int			aleatori_char(void);
char		*create_aleatori_name(void);
void		handle_heredoc_signal(int sig);
void		signal_check(void);
void		handle_heredoc_signal(int sig);
//problem
int			write_in_fd(int fd, char *limitor, bool expanded);
int			create_heredoc_fd(t_command_line **cmdline, t_token **cur);
/*     ****exec****    */
void		free_fd_all_exit_malloc_error(t_command_line **first);
void		free_str_fd_exit_malloc_error(char **str, t_command_line **first);
void		free_str_fd_all_env_pid_exit(t_command_line **cmd,
				pid_t *pid, char **str);
char		*free_split_ret_null(char **str);
void		free_file_name(char *file_name);
int			wait_pid(t_command_line **cmdline, pid_t *pid);
int			no_forking(t_command_line **cmdline, pid_t *pid);
int			exec_builtin(char **str, t_command_line **cmdline,
				t_command_line **start, pid_t *pid);
void		signal_cmd_2(int sig);
int			ft_exec_cmd(t_command_line **cmdline, t_command_line **start,
				char **str, pid_t *pid);
int			ft_execve_fct(t_command_line **cmdline,
				t_command_line **start, pid_t *pid);
int			multi_fork(pid_t *pid, int i, t_command_line **cmdline,
				t_command_line **cur);
int			forking(t_command_line **cmdline, pid_t *pid, int i, int len);
int			ft_exec(t_command_line **cmdline);
char		*write_bad_cmd_free_split(char *str,
				char **split_path);
char		*write_bad_cmd_free(char *str);
char		*get_access(char *str, char *path);
int			try_access(char *str, char *path);
char		*get_bin_argv_zero(char *str, char *path, int i);
int			ft_t_envlen(void);
char		**ft_t_env_to_enp(t_env **envp);
int			redirect_file_in(t_command_line **cmdline, t_token *cur,
				t_e_token type);
int			redirect_file_out(t_command_line **cmdline, t_token *cur,
				t_e_token type);
int			open_fd(t_command_line **cmdline);
void		free_nfd(int **nfd);
void		close_fd_all(t_command_line **cmdline);
int			init_pipe(int **nfd, int i, t_command_line *cur);
int			open_pipe(t_command_line **cmdline);
char		**env_to_tabatb(t_env **envp);
/*     ****built_in****    */
int			free_in_builin(t_command_line **str, pid_t *id, int ret);
int			ft_add_env(char *str);
char		*ft_final_add(char *env);
int			ft_special_lenkey(char *str);
int			ft_add_value_to_env(t_env **env_list, char *env, int declar);
int			ft_equal(char *str);
char		*ft_get_home(void);
int			ft_pwd(char *str);
int			ft_built_in_cd(char **str);
int			ft_built_in_echo_fd(char **str, int fd);
int			ft_check_n(char **str);
int			ft_built_in_echo(char **str);
int			ft_built_in_env_fd(char	**str, int fd);
void		ft_built_in_show_env_fd(t_env **env, int fd);
int			ft_built_in_env(char **str);
int			ft_is_equal(char *str);
void		ft_built_in_show_env(t_env **env);

int			ft_compare_list_str(char *s1, char *s2);
t_env		*ft_sort_export(t_env *env);
t_env		*ft_copy_env(t_env *env);
t_env		*ft_lstnew_env(char *str, int declar);
void		ft_lstadd_back_env(t_env **alst, t_env *new);

int			ft_built_in_export_fd(char **str, int fd);
void		ft_show_export_fd(t_env *env, int fd, int len);
void		ft_built_in_show_export_fd(int fd);
void		ft_built_in_show_export(void);
int			ft_export_is_incorrect(char *str);
int			ft_built_in_export(char **str);
void		ft_show_export(t_env *env);
int			ft_built_in_pwd_fd(char **str, int fd);
int			ft_built_in_pwd(char **str);
int			ft_built_in_unset(char **str);
int			ft_sup_int(char *str);
int			ft_non_int(char *str);
int			exit_bltin(char **args, t_command_line **first, pid_t *id);
int			ft_exec_builtin(char *str, char **args, t_command_line **first,
				pid_t *id);
int			ft_exec_bd_fd(char *str, char **args, t_command_line **first,
				pid_t *id);
int			ft_delete_env(char *str);
void		ft_delete_env_call(t_env **env, char *key);
int			ft_get_lenkey(char *env);
int			ft_singletone(char *str, int mode);
void		ft_clean_env(void);
void		ft_clean_envlist(t_env **env);
void		ft_free_env_elem(t_env *env);
int			ft_print_error(char *str1, char *str2);
char		*ft_get_str(char *str);
char		*ft_get_str_of_env(t_env **env, char *str);
char		*ft_get_env(char *str);
char		*ft_get_value_of_env(t_env **env, char *str);
t_env		**get_address_env(void);
void		ft_change_value(t_env **env_list, char *key, char *value);
void		update_shlvl(t_env **env_list);
int			ft_init_env(t_env **env_list);
char		*ft_get_env_value(t_env **env_list, char *key);

int			ft_init_t_env(char	**env);
int			ft_push_front(char *env, t_env **begin_lst, int declare);
/*     ****parsing****    */
int			free_str_ret_malloc_error(char *str);
int			free_cmdl_ret_malloc_error(t_command_line *cmdline);
int			free_token_ret_malloc_error(t_token *token);
char		*free_str_ret_null(char *str);
void		free_both(char *s1, char *s2);
void		free_split(char **split);
int			ft_is_builtin(char *str);
int			get_len_env_var(char *str);
int			is_env(char *str, char *env, int len);
char		*alloc_dollar(int *cur);
char		*get_envp(char *str, int *cur);
char		*get_env(int *cur, char *str);
int			is_seprator(char c);
int			is_redirection(char c);
t_quote		update_quote_status(char c, t_quote quote);
t_quote		update_quote_success(t_token *stc, int *i,
				t_quote quote, char **s1);
int			unclose_quote(char *str);
/*     ****parsing/lst_function****    */
void		cmdl_add_back(t_command_line **first, t_command_line *add_back);
void		init_token(t_token	*new);
void		init_type(t_token *new);
int			len_cmd(t_command_line *cmd);
void		token_add_back(t_token **first, t_token *add_back);
/*     ****parsing/expend_word****    */
int			move_to(char *str, int *i, t_quote quote);
char		*limitor_unquote(char *str, int *i, char *s1, t_quote quote);
char		*expand_full_quote_str(void);
char		*develope_limitor(t_token *stc, char *str, int i);
int			limitor(t_token *stc, char *str);
char		*init_str(char **str, char *duplica, int *cur, char **s1);
int			end_modif_two(char *str, t_token **stc, char *s1);
int			is_type_file(t_e_token type);
int			ret_file_without_obj(t_e_token type);
t_e_token	cp_type_change_file(t_e_token type, int *file);
int			ret_error_file_without_file(t_command_line *temp);
t_e_token	change_type_file(t_e_token type, int *file);
int			word_modif_two(t_token **stc, char *duplica, t_quote quote,
				t_quote prec);
int			word_modif(t_token **stc, char *str, t_e_token token);
int			edit_type(t_command_line **block, int limitor);
int			check_open_fil(t_command_line **block);
int			expend_words(t_command_line **block, int res);
char		*copy_fake_enc(char *str);
char		*fake_env(int *j, int len_str);
int			len_fake_env(char *str);
char		*string_env(char *str, char *tmp, int *cur);
char		*string_before_env(char *str, char *s1, int *cur, int start);
char		*end_word_unquote(char *str, char *s1, int *i, int j);
char		*free_split_token(char **split, t_token *token);
char		*word_will_double(char *str, int *cur, char *s1);
char		*word_will_single(char *str, int *cur, char *s1);
char		*free_split_ret_str(char **split, char *str);
char		*new_token_env(t_token **stc, char **split, int i);
char		*word_will_unquote(t_token **stc, char *str, int *cur, char *s1);
/*     ****parsing/create_fill_lst****    */
int			get_cmd_line(char *line, t_command_line **first);
int			organise_arg(t_command_line **cmd);
int			iter_to_end_arg(int *cur, char *str);
int			split_all_cmdl_string_to_token(t_command_line **start);

#endif