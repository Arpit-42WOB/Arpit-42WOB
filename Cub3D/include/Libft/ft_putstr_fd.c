/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpit <arpit@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:22:54 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/18 14:54:56 by arpit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putstr_minus_fd(char *s, int len, int fd)
{
	int	i;

	i = 0;
	while (s && s[i] && i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
