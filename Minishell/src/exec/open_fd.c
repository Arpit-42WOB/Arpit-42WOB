/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:19:20 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:19:22 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

int	redirect_file_in(t_command_line **cmdline, t_token *cur, t_e_token type)
{
	if (type == FILE_IN)
	{
		if ((*cmdline)->fd_in != 0)
			close((*cmdline)->fd_in);
		(*cmdline)->fd_in = open(cur->str, O_RDONLY);
		if ((*cmdline)->fd_in == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(cur->str);
			return (-1);
		}
	}
	else if (type == LIMITOR)
	{
		if ((*cmdline)->fd_in != 0)
			close((*cmdline)->fd_in);
		(*cmdline)->fd_in = create_heredoc_fd(cmdline, &cur);
		if ((*cmdline)->fd_in == -1)
			return (-1);
	}
	return (0);
}

int	redirect_file_out(t_command_line **cmdline, t_token *cur, t_e_token type)
{
	if (type == FILE_OUT)
	{
		if ((*cmdline)->fd_out != 1)
			close((*cmdline)->fd_out);
		(*cmdline)->fd_out = open(cur->str, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if ((*cmdline)->fd_out == -1)
			return (-1);
	}
	else if (type == FILE_OUT_OVER)
	{
		if ((*cmdline)->fd_out != 1)
			close((*cmdline)->fd_out);
		(*cmdline)->fd_out = open(cur->str, O_CREAT | O_RDWR | O_APPEND, 0644);
		if ((*cmdline)->fd_out == -1)
			return (-1);
	}
	return (0);
}

int	open_fd(t_command_line **cmdline)
{
	t_token	*cur;

	cur = (*cmdline)->first_token;
	while (cur)
	{
		if (cur->type == FILE_IN || cur->type == LIMITOR)
			if (redirect_file_in(cmdline, cur, cur->type) == -1)
				return (-1);
		if (cur->type == FILE_OUT || cur->type == FILE_OUT_OVER)
			if (redirect_file_out(cmdline, cur, cur->type) == -1)
				return (-1);
		if (g_exit_status == 2)
			return (1);
		cur = cur->next;
	}
	return (0);
}
