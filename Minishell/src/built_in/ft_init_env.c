/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:24:29 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/26 10:17:28 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

void	ft_change_value(t_env **env_list, char *key, char *value)
{
	t_env	*cpy;
	int		len;

	len = ft_get_lenkey(key);
	cpy = *env_list;
	while (cpy)
	{
		if (len == ft_get_lenkey(cpy->str) && !ft_strncmp(cpy->str, key, len))
		{
			free(cpy->str);
			cpy->str = ft_joinstr(key, value);
			return ;
		}
		cpy = cpy->next;
	}
}

char	*ft_get_env_value(t_env **env_list, char *key)
{
	char	*eq_sign;
	t_env	*cpy;

	cpy = *env_list;
	while (cpy)
	{
		if (!ft_strncmp(cpy->str, key, ft_strlen(key)))
		{
			eq_sign = ft_strchr(cpy->str, '=');
			if (eq_sign)
				key = ft_substr(eq_sign, 1, ft_strlen(cpy->str));
			return (key);
		}
		cpy = cpy->next;
	}
	return (NULL);
}

void	update_shlvl(t_env **env_list)
{
	char	*str;
	char	*str2;
	int		i;

	str = ft_get_env_value(env_list, "SHLVL=");
	if (str == NULL)
		return ;
	i = ft_atoi(str);
	free(str);
	i++;
	str2 = ft_itoa(i);
	if (str2 == NULL)
		return ;
	ft_change_value(env_list, "SHLVL=", str2);
	free(str2);
}

int	ft_init_env(t_env **env_list)
{
	char	*str;

	str = ft_joinstr("PWD=", getcwd(NULL, 0));
	if (str == NULL)
		return (50);
	if (ft_push_front("SHLVL=1", env_list, 1) == 50)
	{
		ft_clean_envlist(env_list);
		return (50);
	}
	if (ft_push_front(str, env_list, 1) == 50)
	{
		free(str);
		ft_clean_envlist(env_list);
		return (50);
	}
	free(str);
	if (ft_push_front("OLDPWD", env_list, 1) == 50)
	{
		ft_clean_envlist(env_list);
		return (50);
	}
	return (0);
}
