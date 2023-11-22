/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:20:30 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:20:32 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

static int	create_add_back_token(int cur, int start, char *str,
			t_command_line **stc)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		return (50);
	init_token(new);
	new->str = malloc(sizeof(char) * (cur - start + 1));
	if (new->str == NULL)
		return (free_token_ret_malloc_error(new));
	new->str = ft_strncpy(new->str, str + start, cur - start);
	init_type(new);
	token_add_back(&((*stc)->first_token), new);
	return (0);
}

static void	iter_to_end_or_redirection(char *str, int *cur)
{
	char	c;

	c = str[*cur];
	while (str[*cur] && str[*cur] == c)
		(*cur)++;
}

int	iter_to_end_arg(int *cur, char *str)
{
	t_quote	quote;

	quote = NONE;
	while (str[*cur])
	{
		quote = update_quote_status(str[*cur], quote);
		if (is_seprator(str[*cur]) == 1 && quote == NONE)
			break ;
		(*cur)++;
	}
	return (0);
}

static int	split_string_cur_cmdl(t_command_line **stc)
{
	int	cur;
	int	start;
	int	len;

	cur = 0;
	len = 0;
	if ((*stc)->string != NULL)
		len = ft_strlen((*stc)->string);
	while (cur < len)
	{
		while (cur < len && (*stc)->string[cur] == ' ')
			cur++;
		start = cur;
		if ((*stc)->string[cur] && is_redirection((*stc)->string[cur]))
			iter_to_end_or_redirection((*stc)->string, &cur);
		else
		{
			iter_to_end_arg(&cur, (*stc)->string);
		}
		if (create_add_back_token(cur, start, (*stc)->string, stc) > 0)
			return (50);
	}
	return (0);
}

int	split_all_cmdl_string_to_token(t_command_line **start)
{
	t_command_line	*tmp;

	tmp = *start;
	while (tmp)
	{
		if (split_string_cur_cmdl(&tmp) > 0)
			return (50);
		tmp = tmp->next;
	}
	return (0);
}
