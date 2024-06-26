/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:33:22 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/10 10:23:30 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int ac, char **av)
{
	t_win	win;

	errno = 22;
	if (ac == 2 && check_map_file(av[1]))
	{
		win.map = load_map(av[1]);
		if (!win.map)
			return (0);
		win.mapstr = malloc (sizeof(t_map));
		win.img = malloc (sizeof(t_img));
		if (!win.mapstr || !win.img)
			return (0);
		if (check_errors(&win))
		{
			game_window(&win);
			mlx_hook(win.win_ptr, 17, 0, red_cross, &win);
			mlx_key_hook(win.win_ptr, read_esc, &win);
			mlx_hook(win.win_ptr, 02, (1L << 0), key_hooks, &win);
			mlx_loop(win.mlx_ptr);
			exit_game_after_window(&win);
		}
	}
	else if (ac != 2)
		perror(strerror(errno));
	return (0);
}
