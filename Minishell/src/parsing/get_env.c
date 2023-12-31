/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:21:40 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:21:42 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

int	get_len_env_var(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '$')
		str++;
	if (str[0] && str[0] == '?')
		return (1);
	while (str[i] && ((ft_isalnum(str[i]) == 0) || str[i] == '_'))
		i++;
	return (i);
}

int	is_env(char *str, char *env, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == '\0' || env[i] == '\0')
			return (-1);
		if (str[i] != env[i])
			return (-1);
		i++;
	}
	if (env[i] && env[i] == '=')
		return (0);
	return (-1);
}

char	*alloc_dollar(int *cur)
{
	char	*new;

	*cur += 1;
	new = malloc(sizeof(char) * 2);
	if (new)
	{
		new[0] = '$';
		new[1] = '\0';
		return (new);
	}
	return (NULL);
}

char	*get_envp(char *str, int *cur)
{
	int		len_str;
	char	*cpy;
	char	*env;

	cpy = NULL;
	len_str = get_len_env_var(str);
	if (len_str == 0)
		return (alloc_dollar(cur));
	if (len_str == 1 && str[1] == '?')
	{
		*cur += 2;
		return (ft_itoa(g_exit_status));
	}
	cpy = malloc(sizeof(char) * (len_str + 1));
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strncpy(cpy, str + 1, len_str);
	env = ft_get_env(cpy);
	free(cpy);
	if (env == NULL)
		return (fake_env(cur, len_str));
	*cur += len_str + 1;
	cpy = ft_strdup(env);
	return (cpy);
}

char	*get_env(int *cur, char *str)
{
	char	*temp;

	temp = get_envp(str + *cur, cur);
	if (temp == NULL)
		return (NULL);
	return (temp);
}
