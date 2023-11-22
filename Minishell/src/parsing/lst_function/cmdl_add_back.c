/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdl_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpit <arpit@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:38:24 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/19 18:05:22 by arpit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

void	cmdl_add_back(t_command_line **first, t_command_line *add_back)
{
	t_command_line	*cur;

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
