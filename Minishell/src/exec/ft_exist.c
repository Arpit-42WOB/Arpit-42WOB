/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:19:07 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:19:09 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

char	*write_bad_cmd_free_split(char *str, char **split_path)
{
	free_split(split_path);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (NULL);
}

char	*write_bad_cmd_free(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
	free(str);
	return (NULL);
}

char	*get_access(char *str, char *path)
{
	char	*back_slash;
	char	*tmp;

	back_slash = ft_joinstr(path, "/");
	if (!back_slash)
		return (NULL);
	tmp = ft_joinstr(back_slash, str);
	free(back_slash);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

int	try_access(char *str, char *path)
{
	char	*try;

	try = get_access(str, path);
	if (!try)
		return (50);
	if (access(try, X_OK) == 0)
	{
		free(try);
		return (1);
	}
	free(try);
	return (0);
}

char	*get_bin_argv_zero(char *str, char *path, int i)
{
	int		ret;
	char	**split_path;
	char	*try;

	if (str && (str[0] == '.' || str[0] == '/'))
		return (str);
	split_path = ft_strsplit(path, ':');
	if (!split_path)
		return (write_bad_cmd_free(str));
	while (split_path[i] && str[0] != '\0')
	{
		ret = try_access(str, split_path[i]);
		if (ret == 1)
		{
			try = get_access(str, split_path[i]);
			free_split(split_path);
			return (try);
		}
		if (ret == 50)
			return (free_split_ret_null(split_path));
		i++;
	}
	write_bad_cmd_free_split(str, split_path);
	g_exit_status = 127;
	exit(g_exit_status);
}
