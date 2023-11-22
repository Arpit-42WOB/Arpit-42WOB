/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:56:44 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/31 18:07:59 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putneg(int nb)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (nb == -2147483648)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		i = 11;
	}
	else
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i++;
		f = ft_putnbr(-nb);
		if (f == -1)
			return (-1);
		i = i + f;
	}
	return (i);
}

static int	ft_putpos(int nb)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (nb > 9)
	{
		f = ft_putpos(nb / 10);
		if (f == -1)
			return (-1);
		i = i + f;
		f = ft_putpos(nb % 10);
		if (f == -1)
			return (-1);
		i = i + f;
	}
	else
	{
		if (ft_putchar(nb + '0') == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (nb < 0)
	{
		f = ft_putneg(nb);
		if (f == -1)
			return (-1);
		i = i + f;
	}
	else
	{
		f = ft_putpos(nb);
		if (f == -1)
			return (-1);
		i = i + f;
	}
	return (i);
}
