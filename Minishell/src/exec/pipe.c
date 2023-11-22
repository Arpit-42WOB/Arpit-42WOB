/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:19:30 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:19:32 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

void	free_nfd(int **nfd)
{
	int	i;

	i = 0;
	while (nfd[i])
	{
		free(nfd[i]);
		i++;
	}
	free(nfd);
}

void	close_fd_all(t_command_line **cmdline)
{
	t_command_line	*tmp;

	tmp = *cmdline;
	while (tmp)
	{
		if (tmp->fd_in != 0)
			close(tmp->fd_in);
		if (tmp->fd_out != 1)
			close(tmp->fd_out);
		tmp = tmp->next;
	}
}

int	init_pipe(int **nfd, int i, t_command_line *cur)
{
	nfd[i] = malloc(sizeof(int) * 2);
	if (nfd[i] == NULL)
		return (50);
	if (pipe(nfd[i]) == -1)
		return (40);
	if (i == 0)
		cur->fd_in = 0;
	else
		cur->fd_in = nfd[i - 1][0];
	if (cur->next == NULL)
	{
		close(nfd[i][0]);
		close(nfd[i][1]);
		cur->fd_out = 1;
	}
	else
		cur->fd_out = nfd[i][1];
	return (0);
}

int	open_pipe(t_command_line **cmdline)
{
	t_command_line	*cur;
	int				**nfd;
	int				i;
	int				ret;

	cur = *cmdline;
	i = 0;
	nfd = malloc(sizeof(int *) * (len_cmd(cur) + 1));
	if (nfd == NULL)
		return (50);
	nfd[len_cmd(cur)] = NULL;
	while (cur)
	{
		ret = init_pipe(nfd, i, cur);
		if (ret != 0)
		{
			free_nfd(nfd);
			return (ret);
		}
		i++;
		cur = cur->next;
	}
	free_nfd(nfd);
	return (0);
}
