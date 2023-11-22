/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_singletone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:40:00 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/23 15:02:07 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	ft_get_lenkey(char *env)
{
	int	i;

	i = 0;
	while (env && env[i] != '\0' && env[i] != '=')
		i++;
	return (i);
}

int	ft_singletone(char *str, int mode)
{
	t_env	**env_list;

	env_list = get_address_env();
	if (mode == DELETE)
	{
		ft_delete_env_call(env_list, str);
		return (0);
	}
	if (mode == FREE)
		ft_clean_envlist(env_list);
	if (mode == ADD)
	{
		if (ft_add_value_to_env(env_list, str, 0) == 50)
		{
			ft_clean_envlist(env_list);
			return (50);
		}
	}
	return (0);
}
