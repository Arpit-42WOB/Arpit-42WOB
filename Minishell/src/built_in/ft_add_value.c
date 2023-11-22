/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:06:16 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/23 15:29:07 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	ft_add_env(char *str)
{
	return (ft_singletone(str, ADD));
}

char	*ft_final_add(char *env)
{
	int		len;
	char	*str;
	int		i;
	int		y;

	y = 0;
	i = 0;
	len = ft_get_lenkey(env) - 1;
	if (env[ft_get_lenkey(env) - 1] != '+')
		return (ft_strdup(env));
	str = malloc(sizeof(char) * ft_strlen(env));
	if (str == NULL)
		return (NULL);
	while (env[y])
	{
		str[i] = env[y];
		i++;
		y++;
		if (y == len)
			y++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_special_lenkey(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=' && str[i] != '+')
		i++;
	return (i);
}

int	ft_add_value_to_env(t_env **env_list, char *env, int declare)
{
	int		len;
	t_env	*cpy;

	cpy = *env_list;
	len = ft_special_lenkey(env);
	while (cpy)
	{
		declare = cpy->declar;
		if (len == ft_get_lenkey(cpy->str) && !ft_strncmp(env, cpy->str, len))
		{
			if (ft_equal(cpy->str) && !ft_equal(env))
				return (0);
			free(cpy->str);
			cpy->str = ft_final_add(env);
			if (cpy->str == NULL)
			{
				ft_clean_envlist(get_address_env());
				return (50);
			}
			return (0);
		}
		cpy = cpy->next;
	}
	return (ft_push_front(env, env_list, declare));
}
