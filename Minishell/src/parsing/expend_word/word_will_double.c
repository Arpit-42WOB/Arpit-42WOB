/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_will_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:00:40 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/26 17:40:47 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

static char	*if_no_env(char *str, char *s1, int *cur)
{
	char	*new;
	char	*join;
	int		start;

	start = *cur;
	while (str[*cur] && str[*cur] != '"' && str[*cur] != '$')
		(*cur)++;
	new = malloc(sizeof(char) * ((*cur) - start));
	if (new == NULL)
		return (free_str_ret_null(s1));
	new = ft_strncpy(new, str + start, (*cur) - start);
	join = ft_joinstr(s1, new);
	free_both(s1, new);
	return (join);
}

static char	*if_env(char *str, char *s1, int *cur)
{
	char	*env;
	char	*join;

	env = string_env(str, s1, cur);
	if (env == NULL)
		return (free_str_ret_null(s1));
	join = ft_joinstr(s1, env);
	free_both(s1, env);
	return (join);
}

char	*word_will_double(char *str, int *cur, char *s1)
{
	while (str && str[*cur] && str[*cur] != '"')
	{
		if (str[*cur] == '$')
		{
			s1 = if_env(str, s1, cur);
			if (s1 == NULL)
				return (NULL);
		}
		else
		{
			s1 = if_no_env(str, s1, cur);
			if (s1 == NULL)
				return (NULL);
		}
	}
	return (s1);
}
