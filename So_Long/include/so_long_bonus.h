/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:05:57 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/10 15:53:19 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# include "./Libft/libft.h"
# include "./mlx/mlx.h"

# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_ESC				53

# define TILE_SIZE				64

# define PLAYER					80
# define WALL					49
# define COLLECTIBLE			67
# define EXIT					69
# define FLOOR					48
# define ENEMY					72

# define FLAG					70

# define MIN_MAP_HIEGHT			3
# define MAX_MAP_HIEGHT			21
# define MIN_MAP_WIDTH			3
# define MAX_MAP_WIDTH			40

# define ERROR					"Error "
# define FILE_ERROR				"Unable to Read File Data!! "
# define FILE_NAME_ERROR		"Invalid Map File Format!! " 
# define WIDTH_NOT_SAME			"Width of Map is not Same for all Rows!!\n"
# define MAP_SIZE_ISSUE	"Map is Either too Big or too Small to be Displayed!! "
# define UNKNOWN_CHAR			"Found an Unknown Variable in Map!!\n"
# define FOUR_SIDE_WALL	"Map should be closed with Walls from all 4 sides!!\n"
# define CAN_NOT_COLLECT		"All Collectibles cannot be collected!!\n"
# define EXIT_NOT_REACHABLE		"Player cannot reach Exit!!\n"
# define ZERO_COLLECT			"No. of Collectibles cannot be less than 1\n"
# define ONE_EXIT				"No. of Exits should only be 1\n"
# define ONE_PLAYER				"No. of Players should only be 1\n"
# define PRESSED_ESC			"Ohhh... You Pressed Esc!!\n"
# define RED_CROSS_CLICKED		"Ohhh... You Closed the game Window!!\n"
# define PLAYER_WON				"Yeah... You Won!!\n"
# define PLAYER_LOSE			"Sorry... You Lose!!\n"

typedef struct s_img
{
	void	*wall;
	void	*exit;
	void	*player;
	void	*collect;
	void	*back;
	void	*enemy;
	void	*lock;
	int		h;
	int		w;
}			t_img;

typedef struct s_map
{
	int		h;
	int		w;
	int		exit;
	int		exit_pos;
	int		collect;
	int		player;
}			t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	t_map	*mapstr;
	t_img	*img;
	int		moves;
	char	*put_moves;
	char	*put_collect;
	int		to_collect;
	int		to_exit;
	int		over;
	int		player_x;
	int		player_y;
}			t_win;

// check.c
int		check_errors(t_win *win);
int		check_map_dimensions(t_win *win);
int		count_components(t_win *win, int h, int w);
int		check_components(t_win *win);
int		check_boundary_walls(t_win *win);

// error.c
int		exit_game_before_window(t_win *win);
int		exit_game_after_window(t_win *win);
void	free_map(char **map);
int		read_esc(int key, t_win *win);
int		red_cross(t_win *win);

// exit.c
void	check_exit_pos(t_win *win, int x, int y);
void	check_exit_pos1(t_win *win, int x, int y);
void	init_exit(t_win *win);
void	init_exit1(t_win *win);
void	init_player(t_win *win);

// frame.c
void	update_enemy_n_collecible(t_win *win, size_t t);
void	update_enemy_n_collecible1(t_win *win, size_t t);
void	update_enemy_n_collecible2(t_win *win, size_t t);
void	update_enemy_n_collecible3(t_win *win, size_t t);
void	update_enemy_n_collecible4(t_win *win, size_t t);

// game.c
void	game_window(t_win *win);
void	create_image(t_win *win);
void	display_image(t_win *win, int y, int x);
void	display_exit(t_win *win, int y, int x);
void	game_status(t_win *win);

// move.c
int		key_hooks(int key, t_win *win);
void	move_up(t_win *win);
void	move_down(t_win *win);
void	move_left(t_win *win);
void	move_right(t_win *win);

// read_map.c
int		check_map_file(const char *map);
char	**load_map(char *file);
void	update_player(t_win *win, int move);
int		error_message(int code);
int		check_count_of_components(t_win *win);

// so_long_bonus.c
// main function
int		render_next_frame(t_win *win);

// test_path.c
int		check_path(t_win *win);
void	check_move(char **map_dup, int x, int y, t_win *win);
void	calculate_moves(t_win *win, int x, int y);

#endif