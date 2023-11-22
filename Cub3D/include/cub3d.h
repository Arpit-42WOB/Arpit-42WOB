/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:48:20 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/20 23:21:11 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <sys/time.h>

# define PLAYER_NORTH	'N'
# define PLAYER_SOUTH	'S'
# define PLAYER_EAST	'E'
# define PLAYER_WEST	'W'
# define WALL			'1'
# define FLOOR			'0'
# define SPACE			' '

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

typedef struct s_img
{
	void	*img_ptr;
	int		x;
	int		y;
}			t_img;

typedef struct s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		pos_x;
	double		pos_y;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		cam_x;
	double		ray_dirx;
	double		ray_diry;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
	double		move_speed;
	double		rotation_speed;
	double		old_dir_x;
	double		old_plane_x;
	double		frame_time;
	double		timestamp;
	double		old_timestamp;
	void		*img;
	char		*img_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			texture_num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	uint32_t	colors;
	int			pitch;
}		t_cub;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	char		**map;
	int			**imap;
	int			t_width;
	int			t_height;
	u_int32_t	**tex;
	int			floor_color;
	int			ceiling_color;
	int			player_dir;
	int			line_size;
	t_cub		*cub;
	t_img		north_wall;
	t_img		south_wall;
	t_img		east_wall;
	t_img		west_wall;
	int			mouse_right;
	int			mouse_up;
}				t_win;

// check_utils.c
int				find_max_len(t_win *win);
void			make_map_rectangular(t_win *win);
void			fill_with_ones(t_win *win);

// check.c
int				check_components(t_win *win, char **map, int i);
int				check_walls(char **map);
int				check_empty(char **map);
void			map_check_errors(t_win *win, char **file_content);
void			init_map(t_win *win, char **file_content);

// exit.c
void			free_textures(t_win *win);
void			free_win(t_win	*win);
int				close_game_win(t_win *win);

// init_game_map.c
int				add_color_varialble(int *color, char *rgb);
int				add_path_variable(t_win *win, t_img *img, char *path);
int				pick_variable(t_win *win, char **var);
void			init_map_variables(t_win *win, char **file_content, int i, \
				int var_count);
void			init_map_data(t_win *win, char *path);

// init_game_win.c
void			init_player_dir(t_win *win);
int				init_win(t_win *win);
int				*convert(unsigned char *img_data, int img_w, int img_h);
int				init_textures(t_win *win);

// main.c
void			ft_print_error_and_exit(t_win *win, char *error_msg);
void			fill_map_values(t_win *win);
int				init_map_values(t_win *win);
//int main(int argc, char **argv);

// movement.c
void			key_w(t_win *win);
void			key_s(t_win *win);
void			key_a(t_win *win);
void			key_d(t_win *win);
int				key_press(int key, t_win *win);

//parse_img.c
t_img			read_img(void *mlx, char *file);
void			add_pixel(t_win *win, int x, int y, uint32_t color);
unsigned int	ft_get_time(void);

//parse_map.c
int				check_if_nums(char *num);
size_t			ft_strstr_len(char **str);
char			**ft_strstrdup(char **str, size_t len);
void			ft_strstr_free(char **str);

//read_map.c
char			**get_map(char **file_content);
void			reverse_str(char *str);
int				is_empty_line(char *line);
int				count_lines(int fd);
char			**read_map(t_win *win, char *map);

// rotation.c
void			key_left(t_win	*win);
void			key_right(t_win	*win);

//raycasting_process.c
void			ft_side_distance(t_win *win);
void			ft_raycasting_init(t_win *win, int i);
void			ft_wall_cast(t_win *win);
void			ft_floor_ground(t_win *win);
int				ft_raycasting_process(t_win *win);

//raycasting_texture.c
void			ft_calulate_draw(t_win *win);
void			ft_draw_wall(t_win *win, int i);
void			side_inspect(t_win *win);
void			ft_wall_hit_dda(t_win *win);

//RGB_format.c
int				create_trgb(int t, int r, int g, int b);
int				transperent(int trgb);
int				blue(int trgb);
int				green(int trgb);
int				red(int trgb);

//ft_spliting.c
int				is_space(int n);
char			**ft_spliting(char const *str);

//ft_bonus_minimap.c
void			ft_minimap(t_win *win, int i, int j);

//ft_mouse_hanlde.c
int				mouse_handle(int x, int y, t_win *win);

#endif
