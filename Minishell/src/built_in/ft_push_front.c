/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:21:40 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/26 02:23:02 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	ft_push_front(char *env, t_env **begin_lst, int declare)
{
	t_env	*env_alt;

	env_alt = malloc(sizeof(t_env));
	if (env_alt == NULL)
		return (50);
	env_alt->str = ft_final_add(env);
	env_alt->declar = declare;
	if (env_alt->str == NULL)
		return (50);
	env_alt->next = *begin_lst;
	*begin_lst = env_alt;
	return (0);
}

t_env	**get_address_env(void)
{
	static t_env	*new = NULL;

	return (&new);
}

int	ft_init_t_env(char	**env)
{
	t_env	**env_list;
	int		i;

	env_list = get_address_env();
	i = 0;
	while (env[i])
		i++;
	if (i == 0)
		if (ft_init_env(env_list) == 50)
			return (50);
	i--;
	while (i >= 0)
	{
		if (ft_push_front(env[i], env_list, 0) == 50)
		{
			ft_clean_envlist(env_list);
			return (50);
		}
		i--;
	}
	update_shlvl(env_list);
	return (0);
}
