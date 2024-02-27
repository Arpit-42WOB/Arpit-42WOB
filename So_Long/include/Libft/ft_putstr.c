/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:24:24 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/31 18:08:45 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (i);
// 	while (s[i] != 0)
// 		i++;
// 	return (i);
// }

int	ft_putstr(char *s)
{
	int	l;

	l = ft_strlen(s);
	if (!s)
		return (write(1, "(null)", 6));
	else
	{
		return (write(1, s, l));
	}
}
