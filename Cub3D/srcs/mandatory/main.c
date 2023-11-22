/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:53:24 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/21 18:19:47 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_print_error_and_exit(t_win *win, char *error_msg)
{
	if (win)
		free_win(win);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	exit(EXIT_FAILURE);
}

void	fill_map_values(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->map[i])
	{
		win->imap[i] = malloc(sizeof(int) * ft_strlen(win->map[i]));
		if (!win->imap[i])
		{
			perror("Malloc int map failed");
			close_game_win(win);
		}
		j = 0;
		while (win->map[i][j] != '\0' && win->map[i][j] != '\n')
		{
			win->imap[i][j] = win->map[i][j] - '0';
			j++;
		}
		i++;
	}
}

int	init_map_values(t_win *win)
{
	int	i;

	i = 0;
	while (win->map[i])
		i++;
	win->imap = malloc(sizeof(int *) * i);
	if (!win->imap)
	{
		perror("Malloc int map failed");
		close_game_win(win);
		return (0);
	}
	fill_map_values(win);
	return (1);
}

int	main(int argc, char **argv)
{
	t_win	*win;

	win = ft_calloc(1, sizeof(t_win));
	if (!win)
		ft_print_error_and_exit(win, "Malloc failed\n");
	if (argc != 2)
		ft_print_error_and_exit(win, "Wrong number of arguments\n");
	if (!init_win(win))
		ft_print_error_and_exit(win, "Window init failed\n");
	init_map_data(win, argv[1]);
	init_player_dir(win);
	if (!init_textures(win))
		ft_print_error_and_exit(win, "Texture init failed\n");
	if (!init_map_values(win))
		return (0);
	mlx_hook(win->win_ptr, 17, 1L << 0, close_game_win, win);
	mlx_key_hook(win->win_ptr, key_press, win);
	mlx_loop_hook(win->mlx_ptr, ft_raycasting_process, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
