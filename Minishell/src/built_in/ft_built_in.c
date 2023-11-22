/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:38:26 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/26 10:00:02 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minishell.h"

extern int	g_exit_status;

int	ft_sup_int(char *str)
{
	long	res;
	int		sig;
	int		i;

	res = 0;
	sig = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
		if (res > 2147483648)
			return (2);
	}
	res = res * sig;
	if (res > 2147483647)
		return (2);
	return (0);
}

int	ft_non_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			return (2);
		}
		i++;
	}
	return (ft_sup_int(str));
}

int	exit_bltin(char **args, t_command_line **first, pid_t *id)
{
	int	ret;

	ret = 0;
	printf("exit\n");
	if (args[1] != NULL)
	{
		if (args[2] != NULL)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			g_exit_status = 1;
			return (2);
		}
		if (ft_non_int(args[1]))
		{
			ft_clean_env();
			free_all(first);
			free(id);
			exit(255);
		}
		ret = ft_atoi(args[1]);
		free_in_builin(first, id, ret);
	}
	return (free_in_builin(first, id, 0));
}

int	ft_exec_builtin(char *str, char **args, t_command_line **first, pid_t *id)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp("exit", str))
	{
		exit_bltin(args, first, id);
		return (free_in_builin(first, id, 1));
	}
	if (ft_strcmp("cd", str))
		ft_built_in_cd(args);
	else if (ft_strcmp("echo", str))
		ft_built_in_echo(args);
	else if (ft_strcmp("env", str))
		ft_built_in_env(args);
	else if (ft_strcmp("pwd", str))
		ft_built_in_pwd(args);
	else if (ft_strcmp("export", str))
		ft_built_in_export(args);
	else if (ft_strcmp("unset", str))
		ft_built_in_unset(args);
	free(id);
	ft_clean_env();
	free_all(first);
	return (0);
}

int	ft_exec_bd_fd(char *str, char **args, t_command_line **first, pid_t *id)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp("exit", str))
	{
		exit_bltin(args, first, id);
		return (1);
	}
	if (ft_strcmp("cd", str))
		ft_built_in_cd(args);
	else if (ft_strcmp("echo", str))
		ft_built_in_echo_fd(args, (*first)->fd_out);
	else if (ft_strcmp("env", str))
		ft_built_in_env_fd(args, (*first)->fd_out);
	else if (ft_strcmp("pwd", str))
		ft_built_in_pwd_fd(args, (*first)->fd_out);
	else if (ft_strcmp("export", str))
		ft_built_in_export_fd(args, (*first)->fd_out);
	else if (ft_strcmp("unset", str))
		ft_built_in_unset(args);
	return (0);
}
