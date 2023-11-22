/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:42:30 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/27 14:23:49 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

void	init_token(t_token	*new)
{
	new->str = NULL;
	new->type = NON;
	new->expanded = false;
	new->next = NULL;
	new->empty_quote = false;
}

void	init_type(t_token *new)
{
	int	len;

	len = 0;
	if (new->str)
		len = ft_strlen(new->str);
	if (len == 1)
	{
		if (new->str[0] == '<')
			new->type = OPEN_FILE;
		else if (new->str[0] == '>')
			new->type = CREATE_FILE;
	}
	if (len == 2)
	{
		if (new->str[0] == '<' && new->str[1] == '<')
			new->type = HERE_DOC;
		if (new->str[0] == '>' && new->str[1] == '>')
			new->type = WRITE_FILE;
	}
	if (ft_is_builtin(new->str))
		new->type = BUILTIN;
	if (new->str && (ft_strcmp(new->str, "\"\"") || ft_strcmp(new->str, "''")))
		new->empty_quote = true;
	if (new->type == NON && len != 0)
		new->type = ARG;
}
