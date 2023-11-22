/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:13 by amehrotr          #+#    #+#             */
/*   Updated: 2023/06/06 18:54:21 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (nb > 9)
	{
		f = ft_putnbr(nb / 10);
		if (f == -1)
			return (-1);
		i = i + f;
		f = ft_putnbr(nb % 10);
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
