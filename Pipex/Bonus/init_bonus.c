/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:10:18 by amehrotr          #+#    #+#             */
/*   Updated: 2023/09/20 11:34:48 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex_bonus.h"

void	get_input_file(t_data *data)
{
	if (data->here_doc == 1)
	{
		get_here_doc(data);
		data->fd_in = open(".here_doc.tmp", O_RDONLY);
		if (data->fd_in == -1)
			print_error("here_doc", \
				": ", strerror(errno), 0);
	}
	else
	{
		data->fd_in = open(data->argv[1], O_RDONLY, 0644);
		if (data->fd_in == -1)
			print_error(data->argv[1], \
				": ", strerror(errno), 0);
	}
}

void	get_output_file(t_data *data)
{
	if (data->here_doc == 1)
	{
		data->fd_out = open(data->argv[data->argc - 1], \
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
		data->fd_out = open(data->argv[data->argc - 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out == -1)
		print_error(data->argv[data->argc - 1], \
			": ", strerror(errno), 0);
}

t_data	reset_data(void)
{
	t_data	data;

	data.argc = -1;
	data.argv = NULL;
	data.cmd = NULL;
	data.envp = NULL;
	data.fd_in = -1;
	data.fd_out = -1;
	data.cmd_path = NULL;
	data.n_cmd = -1;
	data.pipe = NULL;
	data.pids = NULL;
	data.child = -1;
	data.here_doc = 0;
	data.exit_code = 0;
	data.child_executed = 0;
	return (data);
}

t_data	init_data(int argc, char **argv, char **envp)
{
	t_data	data;

	data = reset_data();
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	if (argv[1] && !ft_strncmp("here_doc", argv[1], 9))
		data.here_doc = 1;
	get_input_file(&data);
	get_output_file(&data);
	data.n_cmd = argc - 3 - data.here_doc;
	data.pipe = malloc(sizeof(data.pipe) * 2 * (data.n_cmd - 1));
	if (data.pipe == NULL)
		exit_error(print_error("Pipe malloc error", \
			": ", strerror(errno), 1), &data);
	data.pids = ft_calloc(data.n_cmd, sizeof(data.pids));
	if (data.pids == NULL)
		exit_error(print_error("Pids malloc error", \
			": ", strerror(errno), 1), &data);
	create_pipes(&data);
	return (data);
}

void	exit_error(int error, t_data *data)
{
	if (data)
	{
		close_fds(data);
		if (data->pipe)
			free(data->pipe);
		if (data->pids)
			free(data->pids);
		if (data->cmd)
			free_strs(data->cmd);
	}
	if (data->here_doc == 1)
		unlink(".here_doc.tmp");
	exit(error);
}
