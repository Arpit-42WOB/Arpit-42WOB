/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:20:05 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:20:07 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

char	**env_to_tabatb(t_env **envp)
{
	char	**new;
	t_env	*tmp;
	int		i;

	tmp = *envp;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	new = malloc(sizeof(char *) * (i + 1));
	if (new == NULL)
		return (NULL);
	new[i] = NULL;
	tmp = *envp;
	i = 0;
	while (tmp)
	{
		new[i] = tmp->str;
		tmp = tmp->next;
		i++;
	}
	return (new);
}
