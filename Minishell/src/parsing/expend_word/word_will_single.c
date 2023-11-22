/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_will_single.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpit <arpit@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:08:04 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/19 12:01:01 by arpit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

char	*word_will_single(char *str, int *cur, char *s1)
{
	char	*s2;
	char	*s3;
	int		j;

	s2 = NULL;
	s3 = NULL;
	j = *cur;
	while (str && str[*cur] && str[*cur] != '\'')
		(*cur)++;
	s2 = malloc(sizeof(char) * ((*cur) - j + 1));
	if (s2 == NULL)
		return (free_str_ret_null(s1));
	s2 = ft_strncpy(s2, str + j, (*cur) - j);
	s3 = ft_joinstr(s1, s2);
	free_both(s1, s2);
	return (s3);
}
