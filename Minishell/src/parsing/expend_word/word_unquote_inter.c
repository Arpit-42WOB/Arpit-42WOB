/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_unquote_inter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpit <arpit@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:53:58 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/19 20:06:20 by arpit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

char	*string_env(char *str, char *tmp, int *cur)
{
	char	*tmp2;

	tmp2 = NULL;
	tmp2 = get_env(cur, str);
	if (tmp2 == NULL)
		return (free_str_ret_null(tmp));
	return (tmp2);
}

char	*string_before_env(char *str, char *s1, int *cur, int start)
{
	char	*s2;
	char	*s3;

	s2 = NULL;
	s3 = NULL;
	s2 = malloc(sizeof(char) * ((*cur) - start + 1));
	if (s2 == NULL)
		return (free_str_ret_null(s1));
	s2 = ft_strncpy(s2, str + start, (*cur) - start);
	s3 = ft_joinstr(s1, s2);
	free_both(s1, s2);
	return (s3);
}

char	*end_word_unquote(char *str, char *s1, int *i, int j)
{
	char	*s2;
	char	*s3;

	s2 = NULL;
	s3 = NULL;
	if ((*i) - j == 0)
		return (s1);
	s2 = malloc(sizeof(char) * ((*i) - j + 1));
	if (s2 == NULL)
		return (free_str_ret_null(s1));
	s2 = ft_strncpy(s2, str + j, (*i) - j);
	s3 = ft_joinstr(s1, s2);
	free_both(s1, s2);
	return (s3);
}

char	*free_split_token(char **split, t_token *token)
{
	free_split(split);
	if (token)
	{
		if (token->str)
			free(token->str);
	}
	return (NULL);
}
