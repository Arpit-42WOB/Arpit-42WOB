/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:54:02 by amehrotr          #+#    #+#             */
/*   Updated: 2023/09/20 11:34:35 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	dup_n_check_fds(int input_fd, int output_fd, t_data *data)
{
	if (dup2(input_fd, STDIN_FILENO) == -1 || \
		dup2(output_fd, STDOUT_FILENO) == -1)
		exit_error(1, data);
}

void	ft_execute(t_data *data)
{
	data->child_executed++;
	data->pids[data->child] = fork();
	if (data->pids[data->child] == -1)
		exit_error(print_error(FE, ": ", strerror(errno), 0), data);
	else if (data->pids[data->child] == 0)
		child(data);
}

void	child(t_data *data)
{
	if (data->child == 0)
		dup_n_check_fds(data->fd_in, data->pipe[1], data);
	else if (data->child == data->n_cmd - 1)
		dup_n_check_fds(data->pipe[2 * data->child - 2], data->fd_out, data);
	else
		dup_n_check_fds(data->pipe[2 * data->child - 2], \
			data->pipe[2 * data->child + 1], data);
	close_fds(data);
	if (execve(data->cmd_path, data->cmd, data->envp) == -1)
		data->exit_code = print_error(data->cmd[0], ": ", \
		"command not found", 127);
}

int	parent(t_data *data)
{
	pid_t	w_pid;
	int		status;
	int		exit_code;
	int		f;

	close_fds(data);
	data->child--;
	exit_code = -1;
	f = 0;
	while (data->child >= 0)
	{
		w_pid = waitpid(data->pids[data->child], &status, 0);
		if (WIFEXITED(status) && f == 0 && data->child_executed == data->n_cmd)
		{
			exit_code = WEXITSTATUS(status);
			f = 1;
		}
		data->child--;
	}
	free(data->pids);
	free(data->pipe);
	if (exit_code == -1 || data->exit_code != 0)
		exit_code = data->exit_code;
	return (exit_code);
}
