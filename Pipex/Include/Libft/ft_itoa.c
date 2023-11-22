/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:29:41 by amehrotr          #+#    #+#             */
/*   Updated: 2023/05/25 17:02:43 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_str(long nbr, size_t i)
{
	char	*str;

	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (nbr > 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (i == 0 && str[1] == '\0')
		str[i] = '0';
	else if (i == 0 && str[1] != '\0')
		str[i] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	i;
	long	nbr;
	char	*str;

	nbr = n;
	i = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	str = ft_create_str(nbr, i);
	return (str);
}
