/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:30:40 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/17 00:23:46 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

void	ft_clean_env(void)
{
	ft_singletone(NULL, FREE);
}

void	ft_clean_envlist(t_env **env)
{
	t_env	*cpy;
	t_env	*tmp;

	cpy = *env;
	tmp = cpy;
	while (cpy)
	{
		tmp = cpy;
		cpy = cpy->next;
		free(tmp->str);
		free(tmp);
	}
}

void	ft_free_env_elem(t_env *env)
{
	free(env->str);
	free(env);
}
