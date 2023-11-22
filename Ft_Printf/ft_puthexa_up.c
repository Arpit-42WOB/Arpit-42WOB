/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:27:24 by amehrotr          #+#    #+#             */
/*   Updated: 2023/06/06 18:18:08 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexachar(unsigned int num)
{
	if (num < 10)
		return (ft_putchar(num + '0'));
	else
		return (ft_putchar(num + 55));
}

int	ft_puthexa_up(unsigned int num)
{
	int	i;
	int	f;

	i = 0;
	if (num < 16)
		return (ft_puthexachar(num));
	else
	{
		f = ft_puthexa_up(num / 16);
		if (f == -1)
			return (-1);
		i = i + f;
		f = ft_puthexachar(num % 16);
		if (f == -1)
			return (-1);
		i = i + f;
	}
	return (i);
}
