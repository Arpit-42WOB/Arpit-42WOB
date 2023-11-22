/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:43:22 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/23 12:38:26 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

int	ft_check_n(char **str)
{
	int	i;
	int	y;
	int	cpt;

	cpt = 0;
	y = 0;
	i = 0;
	while (str[i] && ft_strlen(str[i]) >= 2)
	{
		if (str[i][y] == '-' && str[i][y + 1] == 'n')
		{
			y++;
			while (str[i][y] == 'n')
				y++;
			if (y == (int)ft_strlen(str[i]))
				cpt++;
		}
		else
			return (cpt);
		i++;
		y = 0;
	}
	return (cpt);
}

int	ft_built_in_echo(char **str)
{
	int	i;
	int	y;

	str++;
	y = 0;
	i = ft_check_n(str);
	if (i > 0)
		y++;
	while (str[i])
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1])
			printf(" ");
		i++;
	}
	if (y == 0)
		printf("\n");
	g_exit_status = 0;
	return (0);
}
