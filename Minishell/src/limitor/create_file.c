/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:19:39 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:19:40 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

int	aleatori_char(void)
{
	char	buff[4];
	int		nbr;
	int		fd;

	fd = open("/dev/random", O_RDONLY);
	if (fd <= -1)
		return (-1);
	read(fd, buff, 4);
	nbr = *(int *)buff;
	if (nbr < 0)
		nbr++;
	if (nbr < 0)
		nbr *= -1;
	return ('a' + (nbr % 26));
}

char	*create_aleatori_name(void)
{
	char	*name_file;
	int		i;

	i = 0;
	name_file = malloc(sizeof(char) * 11);
	if (name_file == NULL)
		return (NULL);
	name_file[10] = '\0';
	while (i < 10)
	{
		name_file[i] = (char)aleatori_char();
		i++;
	}
	return (name_file);
}

void	handle_heredoc_signal(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 2;
		close(STDIN_FILENO);
	}
}

void	signal_check(void)
{
	signal(SIGINT, handle_heredoc_signal);
}
