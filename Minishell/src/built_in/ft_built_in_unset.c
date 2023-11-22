/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:35:05 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/17 00:16:53 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

int	ft_built_in_unset(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_singletone(str[i], DELETE) == 50)
			return (50);
		i++;
	}
	g_exit_status = 0;
	return (0);
}
