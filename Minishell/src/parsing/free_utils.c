/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:20:12 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:20:13 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	free_cmdl_ret_malloc_error(t_command_line *cmdline)
{
	if (cmdline)
		free(cmdline);
	return (50);
}

int	free_token_ret_malloc_error(t_token *token)
{
	if (token)
		free(token);
	return (50);
}

char	*free_str_ret_null(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

void	free_both(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
	}
	if (split)
		free(split);
}
