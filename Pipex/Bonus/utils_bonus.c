/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:46:39 by amehrotr          #+#    #+#             */
/*   Updated: 2023/09/20 11:34:53 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex_bonus.h"

void	create_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->n_cmd - 1))
	{
		if (pipe(data->pipe + 2 * i) == -1)
			exit_error(print_error(PE, ": ", strerror(errno), 1), data);
		i++;
	}
}

int	print_error(char *str1, char *str2, char *str3, int erno)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putendl_fd(str3, 2);
	return (erno);
}

char	*ft_getenv(t_data *data)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	path = NULL;
	tmp = NULL;
	while (data->envp[i] != NULL && data->envp[i][0] != '\0')
	{
		tmp = ft_strnstr(data->envp[i], "PATH=", 5);
		if (tmp)
		{
			path = ft_substr(tmp, 5, ft_strlen(data->envp[i]));
			break ;
		}
		i++;
	}
	return (path);
}

char	*ft_rem_slash(char *str, int len, int i, int c)
{
	char	*tmp;

	while (i < len)
	{
		if (str[i] == '\\')
			c++;
		i++;
	}
	tmp = (char *)malloc(sizeof(char) * (i - c + 1));
	i = 0;
	c = 0;
	while (i < len)
	{
		if (str[i] != '\\')
		{
			tmp[c] = str[i];
			c++;
		}
		i++;
	}
	tmp[c] = '\0';
	return (tmp);
}
