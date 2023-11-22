/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:19:01 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:19:04 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	ft_t_envlen(void)
{
	t_env	*env;
	int		i;

	i = 1;
	env = *get_address_env();
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

char	**ft_t_env_to_enp(t_env **envp)
{
	char	**str;
	t_env	*env;
	int		i;
	int		index;

	index = 0;
	i = ft_t_envlen();
	env = *envp;
	str = (char **)malloc(sizeof(char *) * i);
	if (str == NULL)
		return (NULL);
	while (env && index < i)
	{
		str[index] = ft_strdup(env->str);
		if (str[index] == NULL)
			return (NULL);
		env = env->next;
		index++;
	}
	return (str);
}
