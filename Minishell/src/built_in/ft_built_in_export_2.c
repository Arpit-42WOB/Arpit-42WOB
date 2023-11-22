/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_export_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:18:58 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/26 11:37:17 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

t_env	*ft_lstnew_env(char *str, int declar)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->str = str;
	new->declar = declar;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_env(t_env **alst, t_env *new)
{
	t_env	*tmp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_env	*ft_copy_env(t_env *env)
{
	t_env	*new;
	t_env	*tmp;

	new = NULL;
	while (env)
	{
		tmp = ft_lstnew_env(ft_strdup(env->str), env->declar);
		ft_lstadd_back_env(&new, tmp);
		env = env->next;
	}
	return (new);
}
