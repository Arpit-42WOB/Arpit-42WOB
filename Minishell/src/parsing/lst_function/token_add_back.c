/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpit <arpit@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:56:04 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/19 18:13:48 by arpit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

void	token_add_back(t_token **first, t_token *add_back)
{
	t_token	*cur;

	cur = *first;
	if (cur == NULL)
		*first = add_back;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = add_back;
	}
}
