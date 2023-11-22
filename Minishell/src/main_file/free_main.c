/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:45:12 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/27 01:53:21 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	print_exit_free_env_all(t_command_line **cmd)
{
	printf("exit\n");
	ft_clean_env();
	return (free_all(cmd));
}

int	free_all_env_str_ret_malloc_error(t_command_line **cmd, char *str)
{
	free(str);
	free_all(cmd);
	ft_clean_env();
	ft_putstr_fd("malloc error\n", 2);
	return (50);
}

int	free_all_error(t_command_line **cmd, char *str, int error)
{
	if (error == 40)
		ft_putstr_fd("pipe fails\n", 2);
	if (error == 50)
		ft_putstr_fd("malloc error\n", 2);
	free(str);
	ft_clean_env();
	free_all(cmd);
	return (1);
}

void	free_end(t_command_line **cmd, char *str)
{
	if (str)
		free(str);
	free_all(cmd);
}

int	free_str_all_ret_malloc_error(t_command_line **cmd, char *str)
{
	free(str);
	free_all(cmd);
	return (50);
}
