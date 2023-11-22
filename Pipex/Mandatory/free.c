/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:54:49 by amehrotr          #+#    #+#             */
/*   Updated: 2023/09/20 11:34:15 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	close_pipe_fds(t_data *data)
{
	int	i;

	i = 0;
	while (i < ((data->n_cmd - 1) * 2))
	{
		close(data->pipe[i]);
		i++;
	}
}

void	close_fds(t_data *data)
{
	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);
	close_pipe_fds(data);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

void	free_str(char *str)
{
	if (str)
		free(str);
}
