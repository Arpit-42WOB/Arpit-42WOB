/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:28:14 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/20 23:31:24 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_img	read_img(void *mlx, char *file)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(mlx, file, &img.x, &img.y);
	if (img.img_ptr == NULL)
		write(2, "Error\nInvalid texture file\n", 27);
	return (img);
}

void	add_pixel(t_win *win, int x, int y, uint32_t color)
{
	char	*dst;

	dst = win->cub->img_addr + (y * win->cub->line_length + x * \
			(win->cub->bits_per_pixel / 8));
	*(int *)dst = color;
}

unsigned int	ft_get_time(void)
{
	static unsigned int	frame_counter = 1000;

	return (frame_counter += 13);
}
