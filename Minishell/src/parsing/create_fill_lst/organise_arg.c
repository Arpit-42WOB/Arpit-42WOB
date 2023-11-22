/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organise_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:21:20 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:23:28 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

static void	init_arg(t_command_line *new)
{
	t_token	*tmp;
	int		i;

	tmp = new->first_token;
	i = 0;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == BUILTIN)
		{
			new->argv[i] = tmp->str;
			i++;
		}
		tmp = tmp->next;
	}
	new->argv[i] = NULL;
}

static int	nbr_arg_cmd(t_command_line *cmd)
{
	t_token	*tmp;
	int		len;

	len = 0;
	tmp = cmd->first_token;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == BUILTIN)
			len++;
		tmp = tmp->next;
	}
	return (len);
}

int	organise_arg(t_command_line **cmd)
{
	t_command_line	*tmp;
	int				len_arg;
	char			**new;

	tmp = *cmd;
	while (tmp)
	{
		len_arg = nbr_arg_cmd(tmp);
		new = malloc(sizeof(char *) * (len_arg + 1));
		if (new == NULL)
			return (50);
		tmp->argv = new;
		init_arg(tmp);
		tmp = tmp->next;
	}
	return (0);
}
