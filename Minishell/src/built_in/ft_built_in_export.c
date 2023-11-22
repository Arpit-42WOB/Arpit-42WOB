/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:26:36 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/23 15:24:19 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

void	ft_built_in_show_export(void)
{
	t_env	*env;

	env = *get_address_env();
	ft_show_export(ft_sort_export(env));
}

int	ft_export_is_incorrect(char *str)
{
	int	i;

	i = 1;
	if ((ft_isalpha(str[0]) && str[0] != '_'))
		return (1);
	while (str[i] && str[i] != '=')
	{
		if ((ft_isalnum(str[i]) && str[i] != '_'))
		{
			if (!(str[i] == '+' && str[i + 1] == '='))
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_built_in_export(char **str)
{
	int	i;

	i = 1;
	g_exit_status = 0;
	if (*(str + 1) == NULL)
	{
		ft_built_in_show_export();
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

void	ft_show_export(t_env	*env)
{
	t_env	*str;
	int		len;

	str = env;
	while (str)
	{
		len = ft_get_lenkey(str->str);
		if (str->declar == 1)
			printf("declare -x %.*s", len, str->str);
		else
			printf("export %.*s", len, str->str);
		if (len < (int)ft_strlen(str->str))
			printf("=\"%s\"", str->str + len + 1);
		printf("\n");
		str = str->next;
	}
}

t_env	*ft_sort_export(t_env *env)
{
	t_env	*str;
	t_env	*tmp;
	char	*tmp_str;

	str = env;
	while (str)
	{
		tmp = str->next;
		while (tmp)
		{
			if (ft_compare_list_str(str->str, tmp->str) > 0)
			{
				tmp_str = str->str;
				str->str = tmp->str;
				tmp->str = tmp_str;
			}
			tmp = tmp->next;
		}
		str = str->next;
	}
	return (env);
}
