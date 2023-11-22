/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:06:56 by amehrotr          #+#    #+#             */
/*   Updated: 2023/09/20 11:24:44 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/pipex_bonus.h"

char	*get_cmd_path(char *cmd, char **env_path, t_data *data)
{
	int		i;
	char	*cmd_path;

	cmd_path = NULL;
	i = 0;
	while (env_path[i])
	{
		cmd_path = strdup(env_path[i]);
		cmd_path = ft_strjoin(cmd_path, "/");
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (!cmd_path)
		{
			free_str(cmd_path);
			exit_error(print_error(ME, ": ", strerror(errno), 127), data);
			return (NULL);
		}
		if (cmd && access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free_str(cmd_path);
		i++;
	}
	return (NULL);
}

char	*get_cmd(char *cmd, t_data *data)
{
	char	*cmd_path;
	char	**env_path;
	char	*tmp;

	if (cmd && access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	tmp = ft_getenv(data);
	env_path = ft_split(tmp, ':');
	cmd_path = get_cmd_path(cmd, env_path, data);
	if (cmd_path == NULL)
		data->exit_code = print_error(data->argv[data->child + 2], \
			": ", "command not found", 127);
	else
		data->exit_code = 0;
	free_str(tmp);
	free_strs(env_path);
	return (cmd_path);
}

void	ft_split_cmds(char *str, int i, int j, t_data *data)
{
	char	*tmp;

	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			j = i + 1;
			while (str[j] && (str[j] != str[i] || str[j - 1] == '\\'))
				j++;
			if (str[j])
			{
				str[j] = 26;
				str[i] = 26;
				i = j;
			}
		}
		else if (str[i] == ' ')
			str[i] = 26;
		i++;
	}
	tmp = ft_rem_slash(str, ft_strlen(str), 0, 0);
	data->cmd = ft_split(tmp, 26);
	free_str(tmp);
}

int	pipex(t_data *data)
{
	int	exit_code;

	if (pipe(data->pipe) == -1)
		exit_error(print_error(PE, ": ", strerror(errno), 0), data);
	data->child = 0;
	while (data->child < data->n_cmd)
	{
		ft_split_cmds(data->argv[data->child + 2 + data->here_doc], 0, 0, data);
		if (data->cmd == NULL)
			exit_error(print_error(ME, ": ", strerror(errno), 0), data);
		data->cmd_path = get_cmd(data->cmd[0], data);
		if (data->cmd_path)
			ft_execute(data);
		free_str(data->cmd_path);
		free_strs(data->cmd);
		data->child++;
	}
	exit_code = parent(data);
	if (data->here_doc == 1)
		unlink(".here_doc.tmp");
	return (exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		exit_code;

	if (argc < 5)
	{
		if (argc >= 2 && !ft_strncmp("here_doc", argv[1], 9))
			return (print_error("Usage: ", "./pipex here_doc LIMITER cmd1 cmd2 \
.... cmdn output_file.", "", 1));
		else
			return (print_error("Usage: ", "./pipex input_file cmd1 cmd2 \
.... cmdn output_file.", "", 1));
	}
	else if (argc < 6 && !ft_strncmp("here_doc", argv[1], 9))
		return (print_error("Usage: ", "./pipex here_doc LIMITER cmd1 cmd2\
.... cmdn output_file.", "", 1));
	data = init_data(argc, argv, envp);
	exit_code = pipex(&data);
	return (exit_code);
}
