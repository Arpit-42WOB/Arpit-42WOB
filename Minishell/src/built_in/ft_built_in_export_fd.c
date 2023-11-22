/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_export_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:06:19 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/26 11:37:22 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

int	ft_built_in_export_fd(char **str, int fd)
{
	int	i;

	i = 1;
	g_exit_status = 0;
	if (*(str + 1) == NULL)
	{
		ft_built_in_show_export_fd(fd);
		return (0);
	}
	while (str[i] != NULL)
	{
		if (ft_export_is_incorrect(str[i]))
		{
			g_exit_status = 1;
			printf("minishell: export: '%s': not a valid identifier\n", str[i]);
		}
		else if (ft_singletone(str[i], ADD) == 50)
			return (50);
		i++;
	}
	return (0);
}

void	print_export(char *str, int len, int fd)
{
	ft_putchar_fd('=', fd);
	ft_putchar_fd('"', fd);
	ft_putstr_fd(str + len + 1, fd);
	ft_putchar_fd('"', fd);
}

void	ft_show_export_fd(t_env *env, int fd, int len)
{
	t_env	*cur;

	cur = env;
	while (cur)
	{
		len = ft_get_lenkey(cur->str);
		if (cur->str[0] == '_' && cur->str[1] == '=')
		{
			cur = cur->next;
			continue ;
		}
		if (cur->declar == 0)
			ft_putstr_fd("declare -x ", fd);
		else
			ft_putstr_fd("export ", fd);
		ft_putstr_minus_fd(cur->str, len, fd);
		if (len < (int)ft_strlen(cur->str))
		{
			print_export(cur->str, len, fd);
		}
		ft_putchar_fd('\n', fd);
		cur = cur->next;
	}
	ft_clean_envlist(&env);
}

void	ft_built_in_show_export_fd(int fd)
{
	t_env	*env;

	env = *get_address_env();
	ft_show_export_fd(ft_sort_export(ft_copy_env(env)), fd, 0);
}

int	ft_compare_list_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
