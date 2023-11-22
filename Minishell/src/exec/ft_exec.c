/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:19:13 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:19:15 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

int	ft_exec_cmd(t_command_line **cmdline, t_command_line **start,
			char **str, pid_t *pid)
{
	struct stat	buff;

	execve((*cmdline)->argv[0], (*cmdline)->argv, str);
	stat((*cmdline)->argv[0], &buff);
	if ((buff.st_mode & S_IFMT) == S_IFDIR)
		printf("minishell: %s: is a directory\n", (*cmdline)->argv[0]);
	free_all(start);
	free(str);
	free(pid);
	ft_clean_env();
	g_exit_status = 126;
	exit(g_exit_status);
	return (0);
}

int	ft_execve_fct(t_command_line **cmdline, t_command_line **start, pid_t *pid)
{
	char	**str;

	dup2((*cmdline)->fd_in, STDIN_FILENO);
	dup2((*cmdline)->fd_out, STDOUT_FILENO);
	close_fd_all(start);
	str = env_to_tabatb(get_address_env());
	if (str == NULL)
		free_fd_all_exit_malloc_error(start);
	if (ft_is_builtin((*cmdline)->argv[0]) == 0)
	{
		if ((*cmdline)->argv[0] == NULL)
			free_str_fd_all_env_pid_exit(start, pid, str);
		(*cmdline)->argv[0] = get_bin_argv_zero((*cmdline)->argv[0],
				ft_get_env("PATH"), 0);
	}
	if ((*cmdline)->argv[0] == NULL)
		free_str_fd_exit_malloc_error(str, start);
	free_file_name((*cmdline)->name_file);
	if ((*cmdline)->fd_in < 0 || (*cmdline)->fd_out < 0)
		free_str_fd_all_env_pid_exit(start, pid, str);
	if (ft_is_builtin((*cmdline)->argv[0]))
		exec_builtin(str, cmdline, start, pid);
	else
		ft_exec_cmd(cmdline, start, str, pid);
	return (0);
}

int	multi_fork(pid_t *pid, int i, t_command_line **cmdline,
			t_command_line **cur)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid[i] = fork();
	if (pid[i] == -1)
		exit(1);
	if (pid[i] == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		ft_execve_fct(cur, cmdline, pid);
	}
	if ((*cur)->fd_in != 0)
		close((*cur)->fd_in);
	if ((*cur)->fd_out != 1)
		close((*cur)->fd_out);
	return (0);
}

int	forking(t_command_line **cmdline, pid_t *pid, int i, int len)
{
	t_command_line	*cur;
	int				t_fd;

	cur = *cmdline;
	len = len_cmd(cur);
	t_fd = dup(STDIN_FILENO);
	while (cur)
	{
		if (open_fd(&cur))
		{
			g_exit_status = 1;
			return (dup2(t_fd, STDIN_FILENO), 1);
		}
		cur = cur->next;
	}
	dup2(t_fd, STDIN_FILENO);
	cur = *cmdline;
	if (len == 1 && ft_is_builtin(cur->argv[0]))
		return (no_forking(cmdline, pid));
	while (++i < len)
	{
		multi_fork(pid, i, cmdline, &cur);
		cur = cur->next;
	}
	return (0);
}

int	ft_exec(t_command_line **cmdline)
{
	t_command_line	*cur;
	pid_t			*pid;
	int				ret;

	cur = *cmdline;
	ret = open_pipe(cmdline);
	if (ret != 0)
		return (ret);
	pid = malloc(sizeof(pid_t) * len_cmd(cur));
	if (pid == NULL)
		return (50);
	forking(cmdline, pid, -1, 0);
	signal(SIGINT, signal_cmd_2);
	signal(SIGQUIT, SIG_IGN);
	wait_pid(cmdline, pid);
	signal(SIGINT, signal_cmd);
	signal(SIGQUIT, SIG_IGN);
	free(pid);
	return (0);
}
