/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:49:33 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/27 13:18:47 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

int	wait_pid(t_command_line **cmdline, pid_t *pid)
{
	t_command_line	*cur;
	int				len;
	int				i;

	i = 0;
	len = 0;
	cur = *cmdline;
	len = len_cmd(cur);
	if (len == 1 && ft_is_builtin((*cmdline)->argv[0]))
		return (0);
	while (i < len)
	{
		waitpid(pid[i], &g_exit_status, 0);
		if (WIFEXITED(g_exit_status))
			g_exit_status = WEXITSTATUS(g_exit_status);
		else if (WIFSIGNALED(g_exit_status))
			g_exit_status = WTERMSIG(g_exit_status);
		i++;
	}
	return (0);
}

int	no_forking(t_command_line **cmdline, pid_t *pid)
{
	if ((*cmdline)->argv == NULL)
		return (0);
	else if (ft_exec_bd_fd((*cmdline)->argv[0],
			(*cmdline)->argv, cmdline, pid) != 0)
		return (0);
	return (0);
}

int	exec_builtin(char **str, t_command_line **cmdline,
					t_command_line **start, pid_t *pid)
{
	if (str)
		free(str);
	if (ft_exec_builtin((*cmdline)->argv[0], (*cmdline)->argv, start, pid) == 2)
		exit(1);
	exit (0);
	return (0);
}

void	signal_cmd_2(int sig)
{
	if (sig == 2)
	{
		g_exit_status = 130;
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
