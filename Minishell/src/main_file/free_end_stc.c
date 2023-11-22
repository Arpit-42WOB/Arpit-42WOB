/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end_stc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:39:12 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/27 02:27:49 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

void	free_token(t_command_line **cmd_line)
{
	t_token	*tok;

	while ((*cmd_line)->first_token)
	{
		tok = (*cmd_line)->first_token->next;
		if ((*cmd_line)->first_token->str)
			free((*cmd_line)->first_token->str);
		free((*cmd_line)->first_token);
		(*cmd_line)->first_token = tok;
	}
}

int	free_all(t_command_line **cmd_line)
{
	t_command_line	*tmp;

	if (cmd_line)
	{
		while (*cmd_line)
		{
			tmp = (*cmd_line)->next;
			if ((*cmd_line)->string)
				free((*cmd_line)->string);
			if ((*cmd_line)->argv)
				free((*cmd_line)->argv);
			if ((*cmd_line)->first_token)
				free_token(cmd_line);
			if ((*cmd_line)->name_file)
			{
				unlink((*cmd_line)->name_file);
				free((*cmd_line)->name_file);
			}
			free((*cmd_line));
			*cmd_line = tmp;
		}
	}
	return (1);
}

void	error_str(void)
{
	g_exit_status = 258;
}

void	handle_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_cmd;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	rl_catch_signals = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGTSTP, &sa, NULL);
}
