/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:41:57 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/27 14:15:40 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

void	free_fd_all_exit_malloc_error(t_command_line **first)
{
	close_fd_all(first);
	exit (50);
}

void	free_str_fd_exit_malloc_error(char **str, t_command_line **first)
{
	free(str);
	close_fd_all(first);
	exit (50);
}

void	free_str_exit_fd_error(char **str)
{
	free(str);
	exit (1);
}

void	free_str_fd_all_env_pid_exit(t_command_line **cmd,
									pid_t *pid, char **str)
{
	free_all(cmd);
	ft_clean_env();
	free(pid);
	free(str);
	exit(1);
}
