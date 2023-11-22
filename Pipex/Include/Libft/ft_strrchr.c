/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:17:48 by amehrotr          #+#    #+#             */
/*   Updated: 2023/05/25 17:46:16 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*t;
	char	ch;

	t = NULL;
	ch = (char) c;
	while (*s)
	{
		if (ch == *s)
			t = s;
		s++;
	}
	if (!ch && ch == *s)
		return ((char *)s);
	else if (t != NULL)
		return (t);
	else
		return (NULL);
}
