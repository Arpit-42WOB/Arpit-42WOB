/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:25:15 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/07 12:06:51 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

long int	ft_atoi(char *av)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (av[i] == '+')
		i++;
	else if (av[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (is_digit(av[i]))
	{
		num = (num * 10) + (av[i] - '0');
		i++;
	}
	return (num * sign);
}

int	is_digit(char c)
{
	return ((c >= '0' && c <= '9'));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
