/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:20:53 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:20:55 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

char	*copy_fake_enc(char *str)
{
	int		i;
	char	*cpy;

	i = len_fake_env(str);
	cpy = malloc(sizeof(char) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strncpy(cpy, str, i);
	return (cpy);
}

char	*fake_env(int *j, int len_str)
{
	char	*new;

	new = NULL;
	*j += len_str + 1;
	new = malloc(sizeof(char));
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	return (new);
}

int	len_fake_env(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
		i++;
	while (str && str[i] && str[i] != '$')
	{
		if (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
			return (i + 1);
		i++;
	}
	if (i == 1)
		return (i + 1);
	return (i);
}
