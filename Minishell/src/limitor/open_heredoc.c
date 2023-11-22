/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:21:09 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:21:11 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern int	g_exit_status;

static char	*if_no_env(char *str, char *s1, int *cur)
{
	char	*new;
	char	*join;
	int		start;

	start = *cur;
	while (str[*cur] && str[*cur] != '$')
		(*cur)++;
	new = malloc(sizeof(char) * (*cur - start) + 1);
	if (new == NULL)
		return (free_str_ret_null(s1));
	new = ft_strncpy(new, str + start, *cur - start + 1);
	join = ft_joinstr(s1, new);
	free_both(s1, new);
	return (join);
}

static char	*if_env(char *str, char *s1, int *cur)
{
	char	*new;
	char	*join;

	new = string_env(str, s1, cur);
	if (new == NULL)
		return (free_str_ret_null(s1));
	join = ft_joinstr(s1, new);
	free_both(s1, new);
	return (join);
}

static char	*expanded_str(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	while (str[i])
	{
		if (str[i] == '$')
			new = if_env(str, new, &i);
		else
			new = if_no_env(str, new, &i);
		if (new == NULL)
			return (NULL);
	}
	free(str);
	return (new);
}

int	write_in_fd(int fd, char *limitor, bool expanded)
{
	char	*str;

	while (1)
	{
		str = readline("> ");
		if (str == NULL)
			return (45);
		if (ft_strcmp(str, limitor) == 1)
			break ;
		if (str[0] != '\0')
		{
			if (expanded == 0)
			{
				str = expanded_str(str);
				if (str == NULL)
					return (50);
			}
		}
		ft_putstr_fd(str, fd);
		ft_putstr_fd("\n", fd);
		free(str);
	}
	return (0);
}

int	create_heredoc_fd(t_command_line **cmdline, t_token **cur)
{
	int		fd;
	char	*name_file;

	name_file = NULL;
	fd = -1;
	while (fd == -1)
	{
		if (name_file != NULL)
			free(name_file);
		name_file = create_aleatori_name();
		fd = open(name_file, O_CREAT | O_EXCL | O_RDWR, 0644);
	}
	signal_check();
	write_in_fd(fd, (*cur)->str, (*cur)->expanded);
	fd = open(name_file, O_RDONLY);
	(*cmdline)->fd_in = fd;
	if ((*cmdline)->name_file != NULL)
	{
		unlink((*cmdline)->name_file);
		free((*cmdline)->name_file);
	}
	(*cmdline)->name_file = name_file;
	return (fd);
}
