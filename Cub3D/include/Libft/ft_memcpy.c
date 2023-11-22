/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:17:08 by amehrotr          #+#    #+#             */
/*   Updated: 2023/05/25 17:02:27 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;
	size_t		l;

	if (n == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	d = dst;
	s = src;
	i = d - s;
	l = 0;
	while (s[l] != 0)
		l++;
	if ((l <= n) && ((i <= l) || (i < n)))
		return (NULL);
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return (dst);
}
