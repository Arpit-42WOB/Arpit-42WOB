/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:19:39 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/17 00:12:54 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	ft_built_in_env(char **str)
{
	t_env	**env;

	if (*str == NULL)
		return (0);
	env = get_address_env();
	ft_built_in_show_env(env);
	return (0);
}

int	ft_is_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_built_in_show_env(t_env **env)
{
	t_env	*str;

	str = *env;
	while (str)
	{
		if (ft_is_equal(str->str))
		{
			printf("%s\n", str->str);
		}
		str = str->next;
	}
}
