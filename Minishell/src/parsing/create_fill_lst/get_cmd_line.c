/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:20:19 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:20:21 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

static void	init_cmdl(t_command_line *new)
{
	new->string = NULL;
	new->first_token = NULL;
	new->argv = NULL;
	new->name_file = NULL;
	new->next = NULL;
}

static void	go_to_the_pipe(int *i, char *line)
{
	t_quote	quote;

	quote = NONE;
	while (line[*i])
	{
		quote = update_quote_status(line[*i], quote);
		if (line[*i] == '|' && quote == NONE)
			return ;
		(*i)++;
	}
	return ;
}

static int	create_and_fill_cmd(char *str, int cur, int start,
			t_command_line **first)
{
	t_command_line	*new;

	new = malloc(sizeof(t_command_line));
	if (new == NULL)
		return (50);
	init_cmdl(new);
	new->string = malloc(sizeof(char) * (cur - start + 1));
	if (new->string == NULL)
		return (free_cmdl_ret_malloc_error(new));
	new->string = ft_strncpy(new->string, str + start, cur - start);
	cmdl_add_back(first, new);
	return (0);
}

int	get_cmd_line(char *line, t_command_line **first)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (line[i])
	{
		if (i != 0)
		{
			i++;
			start++;
		}
		go_to_the_pipe(&i, line);
		if (create_and_fill_cmd(line, i, start, first) > 0)
			return (50);
		start = i;
		if (i == 0)
		{
			i++;
			start++;
		}
	}
	return (0);
}
