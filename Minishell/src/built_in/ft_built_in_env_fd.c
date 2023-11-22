/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_env_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:53:13 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/16 15:57:02 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	ft_built_in_env_fd(char	**str, int fd)
{
	t_env	**env;

	if (str == NULL)
		return (0);
	env = get_address_env();
	ft_built_in_show_env_fd(env, fd);
	return (0);
}

void	ft_built_in_show_env_fd(t_env **env, int fd)
{
	t_env	*str;

	str = *env;
	while (str)
	{
		if (ft_is_equal(str->str))
		{
			ft_putstr_fd(str->str, fd);
			ft_putchar_fd('\n', fd);
		}
		str = str->next;
	}
}
