/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:15:20 by amehrotr          #+#    #+#             */
/*   Updated: 2023/09/20 11:34:47 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex_bonus.h"

void	get_here_doc(t_data *data)
{
	char	*line;
	int		fd;
	int		stdin_fd;

	fd = open(".here_doc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	stdin_fd = dup(STDIN_FILENO);
	if (fd == -1)
		print_error(".here_doc.tmp", \
			": ", strerror(errno), 0);
	ft_putstr_fd("> ", 1);
	while (1)
	{
		line = get_next_line(stdin_fd);
		if (!line)
			break ;
		if (((ft_strlen(data->argv[2]) + 1) == ft_strlen(line)) && \
			ft_strncmp(line, data->argv[2], ft_strlen(data->argv[2])) == 0)
			close(stdin_fd);
		else
			ft_put_here_doc(line, fd);
		free_str(line);
	}
	close(fd);
}

void	ft_put_here_doc(char *line, int fd)
{
	ft_putstr_fd(line, fd);
	ft_putstr_fd("> ", 1);
}
