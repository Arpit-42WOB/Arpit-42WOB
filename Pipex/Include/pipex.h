/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:42:58 by amehrotr          #+#    #+#             */
/*   Updated: 2023/09/19 21:35:13 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "Libft/libft.h"

# define PE "Pipe Error"
# define ME	"Malloc Error"
# define FE "Fork Error"

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**cmd;
	char	**envp;
	int		fd_in;
	int		fd_out;
	char	*cmd_path;
	int		n_cmd;
	int		*pipe;
	int		*pids;
	int		child;
	int		exit_code;
	int		child_executed;
}				t_data;

t_data	init_data(int argc, char **argv, char **envp);
t_data	reset_data(void);
void	get_input_file(t_data *data);
void	get_output_file(t_data *data);
void	create_pipes(t_data *data);
void	exit_error(int error, t_data *data);
void	free_strs(char **strs);
void	free_str(char *str);
int		print_error(char *str1, char *str2, char *str3, int erno);
int		pipex(t_data *data);
void	child(t_data *data);
int		parent(t_data *data);
void	close_fds(t_data *data);
void	dup_n_check_fds(int input_fd, int output_fd, t_data *data);
char	*get_cmd(char *cmd, t_data *data);
char	*get_cmd_path(char *cmd, char **env_path, t_data *data);
void	close_pipe_fds(t_data *data);
char	*ft_getenv(t_data *data);
void	ft_split_cmds(char *str, int i, int j, t_data *data);
char	*ft_rem_slash(char *str, int len, int i, int c);
void	ft_execute(t_data *data);

#endif