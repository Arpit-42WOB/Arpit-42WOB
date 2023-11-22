/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:04:42 by amehrotr          #+#    #+#             */
/*   Updated: 2023/05/25 16:57:57 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pos;
	t_list	*temp;

	if (!lst || !del)
		return ;
	pos = *lst;
	while (pos)
	{
		temp = pos;
		pos = pos ->next;
		del(temp ->content);
		free(temp);
	}
	*lst = NULL;
}
