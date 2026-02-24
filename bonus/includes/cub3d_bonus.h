/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:57:34 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/21 10:41:37 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../../cub/includes/libft/libft.h"
# include "../../cub/includes/minilibx-linux_copy/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <errno.h>

# define WIDTH 1280
# define HEIGHT 720
# define MINIMAP_SCALE 8
# define TILE_SIZE 128
# define FOV_ANGLE 0.66

typedef struct s_fov
{
	double	start_angle;
	double	end_angle;
	double	angle;
	double	step;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
}			t_fov;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}			t_keys;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b; 
}			t_rgb;

typedef struct s_camera
{
	double	camera_x; 
	double	ray_dir_x; 
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	void	*tex;
	char	*data;
	int		tex_bpp; 
	int		tex_size_line; 
	int		tex_endian;
	double	wall_x;
	int		tex_width;
	int		tex_x;
	int		tex_y;
	int		tex_height;
	int		is_door;
}			t_camera;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	player_start_view;
	int		prev_mouse_x;
}			t_player;

// path codes: 0 = no, 1 = so, 2 = we, 3 = ea, 4 = doors, 5 = NULL
// color codes: 0 = floor, 1 = ceiling
typedef struct s_textures
{
	char	*paths[6];
	int		colors[2];
	void	*no[3];
	void	*so[3];
	void	*we[3];
	void	*ea[3];
	void	*dor;
}	t_textures;

typedef struct s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		**config_lines;
	char		**map;
	char		**padded;
	char		**file_content;
	int			error;
	int			map_fd;
	int			map_rows;
	int			map_cols;
	int			width;
	int			height;
	int			file_line_count;
	int			texture_count;
	int			color_count;
	int			player_count;
	char		*img_data;
	int			size_line;
	int			bpp;
	int			endian;
	int			doors_open;
	int			anim_active;
	int			anim_frame;
	int			anim_frame_delay;
	t_textures	textures;
	t_keys		keys;
	t_player	*player;
}				t_cub;

// initialization functions
// initializes the cub structure
void	ft_init_cub(t_cub *cub);

// map functions
// takes a filename and check name rules and reads the map
int		ft_get_map(char *filename, t_cub *cub);
// checks if map is starting
int		ft_is_map_line(char *line);
// counts map rows without empty lines at the end
int		ft_count_rows(t_cub *cub);
// saves file content in cub
void	ft_fill_file_content(t_cub *cub, char *filename);
// splits config lines from map lines and saves them in different arrays
void	ft_config_and_split_map(t_cub *cub);

// fills the map structure with the content of the file
void	ft_fill_map_content(t_cub *cub, char *filename);

// CONFIG FUNCTIONS
// starts and checks configuration
void	ft_get_config(t_cub *cub);
// gets texture lines
int		ft_get_texture(t_cub *cub, char *conf_line);
// returns the code "no" = 0, "so" = 1, "we" = 2, "ea" = 3;
int		ft_is_texture_code(char *line, int pos);
// checks extension and if texture exists
int		ft_find_texture(t_cub *cub, char *conf_line, int pos, int code);
// returns 1 if texture has .xmp extension
int		ft_has_xpm_extension(char *path);
// gets color lines
int		ft_get_color(t_cub *cub, char *conf_line);
// returns the code "F" = 0, "C" = 1;
int		ft_is_area_code(char *line, int pos);
// checks if color exists
int		ft_find_color(t_cub *cub, char *conf_line, int pos, int code);
// turns line into r, g, and b ints
int		ft_parse_rgb(const char *line, int *r, int *g, int *b);
// returns the hexadecimal code for the rgb
int		ft_create_rgb(int r, int g, int b);

// CHECK FUNCTIONS
// checks if line is empty
int		ft_is_empty_line(char *line);
// function starting a bunch of checks
void	ft_check_map(t_cub *cub);
// prepares to check all walls
int		ft_check_walls(t_cub *cub);
// checks if any invalid lines after map
int		ft_check_map_lines(t_cub *cub);
// checks for valid map values 
int		ft_check_map_chars(t_cub *cub);
// checks a line for a valid map value and for player and saves player view
void	ft_check_line_for_player(t_cub *cub, char *line);

// creates map for flood fill
char	**ft_create_visited(t_cub *cub, int max_len);
// creates map that is a rectangle with all lines having the same 
//length (filled up with spaces)
void	ft_create_padded_map(t_cub *cub, int max_len);
// preparing flood_fill
void	ft_prep_flood_fill(t_cub *cub, char **visited);
// flood_fill from the outside, that marks reachable spaces in visited
void	ft_flood_fill(t_cub *cub, char **visited, int x, int y);
// checks visited against padded to find irregularities
int		ft_check_visited(t_cub *cub, char **padded, char **visited);
//
int		ft_check_internal_holes(t_cub *cub);
// checks if the filename ends with .cub
int		ft_check_filename(char	*filename);

// 2D graphic functions
// starts load_assets
void	ft_open_images(t_cub *cub);
// loads each texture as img into cub->textures.no, .so, .we, .ea
int		ft_load_assets_as_img(t_cub *cub);

// free functions
void	ft_free_map(t_cub *cub);
void	ft_free_array(char **array);
void	ft_free_textures(char **array);

// error handling
void	ft_error(char *message, t_cub *cub);
void	ft_free_and_exit(char *message, t_cub *cub, char **array);

//game
void	init_game(t_cub **cub);
int		render_scene(t_cub *cub);
// void	move_player(int keycode, t_cub *cub);
void	move_player(t_cub *cub);

int		ft_close_window(t_cub *cub);
int		ft_key_hook(int keycode, t_cub *cub);
void	init_player(t_cub *cub);
void	player_west(t_player *player);
void	player_south(t_player *player);
void	player_east(t_player *player);
void	player_nord(t_player *player);
void	move_forward(t_cub *cub, double mv_s);
void	move_backward(t_cub *cub, double mv_s);
void	move_right(t_cub *cub, double mv_s);
void	move_left(t_cub *cub, double mv_s);
int		floor_alt(double x);
void	draw_floor_and_ceiling(t_cub *cub);
void	init_cam_position(t_cub *cub, t_camera *cam, int x);
void	perform_dda(t_cub *cub, t_camera *cam);
void	find_and_draw_wall(t_cub *cub, t_camera *cam, int x);
void	player_turn(t_player *pl, int keycode);

// helpers
int		ft_is_whitespace(char c);
int		ft_is_readable_file(char *path, t_cub *cub);
int		ft_is_dir(char	*path);
void	ft_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int		load_sprites(t_cub *cub);

//bonus
void	draw_map(t_cub *cub);
int		mouse_move_hook(int button, int x, int y, t_cub *cub);
void	door_opener(t_cub *cub);
void	draw_player_fov(t_cub *cub);

#endif