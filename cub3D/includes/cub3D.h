/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../srcs/get_next_line/get_next_line.h"

# include <math.h>
# include <float.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

# define UNDEFINED -1
# define EMPTY ""
# define ERROR -1
# define SPACE_C '0'
# define WALL_C '1'
# define ITEM_C '2'
# define SPACE_N 0
# define WALL_N 1
# define ITEM_N 2
# define TEXTURE_ID_LEN 2
# define SPRITE_ID_LEN 1
# define PI 3.1415926535
# define TWO_PI 6.28318530718
# define TILE_SIZE 64
# define FOV_ANGLE 60
# define TEX_NUM 4
# define WALL_STRIP_WIDTH 1
# define WALL_SHADOW_INTENSITY 1
# define ROTATION_SPEED 3
# define MOVE_SPEED 7
# define MINIMAP_SCALE 0.25
# define PLAYER_SCALE 20
# define ITENS_SCALE 20
# define SPRITE_VIEW_MARGIN 0.2
# define EXIT_MASK_ERRNO 11
# define X_EVENT_EXIT 17
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define RIGHT_ARROW_KEY 65363
# define LEFT_ARROW_KEY 65361
# define M_KEY 109

typedef unsigned int	t_color;

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef enum e_directions
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_directions;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_line
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	delta_x;
	double	delta_y;
	double	x_increment;
	double	y_increment;
	t_color	color;
}	t_line;

typedef struct s_item
{
	int			code;
	double		x;
	double		y;
}	t_item;

typedef struct s_player
{
	char	start_direction;
	double	x;
	double	y;
	int		walk_direction;
	int		strafe_direction;
	int		turn_direction;
	float	rotation_angle;
	float	rotation_speed;
	float	move_speed;
}	t_player;

typedef struct s_texpaths
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
}	t_texpaths;

typedef struct s_teximg
{
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_l;
	int		endian;
}	t_teximg;

typedef struct s_sprite
{
	float	x;
	float	y;
	float	distance;
	float	angle;
}	t_sprite;

typedef struct s_sprite_utils
{
	double		height;
	double		width;
	int			top_y;
	int			bottom_y;
	double		angle;
	double		screen_pos_x;
	double		left_x;
	double		right_x;
	double		perpendicular_dist;
	int			offset_x;
	int			offset_y;
	int			dist;
	int			count;
}	t_sprite_utils;

typedef struct s_textures
{
	t_texpaths	path;
	t_teximg	no;
	t_teximg	so;
	t_teximg	we;
	t_teximg	ea;
	t_teximg	s;
}	t_textures;

typedef struct s_wall
{
	int		strip_height;
	int		bottom_y;
	int		top_y;
	int		texture_offset_x;
	int		texture_offset_y;
	int		distance_from_top;

}	t_wall;

typedef struct s_map
{
	char			*buffer;
	char			**bnormalized;
	int				**matrix;
	int				columns_len;
	int				rows_len;
	int				item_count;
	t_item			*itens;
}	t_map;

typedef struct s_rayface
{
	t_bool	up;
	t_bool	down;
	t_bool	left;
	t_bool	right;
}	t_rayface;

typedef struct s_rays
{
	float		ray_angle;
	double		wall_hit_x;
	double		wall_hit_y;
	double		distance;
	t_rayface	face;
	t_bool		was_hit_vertical;
	t_bool		was_hit_horizontal;
}	t_ray;

typedef struct s_raycasting
{
	double		xintercept;
	double		yintercept;
	double		xstep;
	double		ystep;
	double		next_touch_x;
	double		next_touch_y;
	double		x_to_check;
	double		y_to_check;
	double		wall_hit_x;
	double		wall_hit_y;
	double		wall_hit_content;
	double		hit_distance;
	t_rayface	face;
	t_bool		found_wall_hit;
}	t_raycasting;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		minimap_size;
	int		current_row;
	int		current_col;
}				t_image;

typedef struct s_window
{
	void	*mlx;
	void	*ptr;
	int		width;
	int		height;
}	t_window;

typedef struct s_utils
{
	t_bool			is_all_configs_parsed;
	int				num_rays;
	t_color			tex_color;
	double			dist_to_proj_plane;
}	t_utils;

typedef struct s_game
{
	t_bool			show_minimap;
	t_textures		tex;
	t_rgb			floor;
	t_rgb			ceil;
	t_map			map;
	t_player		player;
	t_window		window;
	t_image			image;
	t_line			line;
	t_wall			wall;
	t_ray			*rays;
	t_sprite		*sprites;
	t_utils			utils;
}	t_game;

t_color		color_picker(t_color red, t_color green, t_color blue);
void		change_color_intensity(t_color *color, float factor);
void		free_and_null(void *thing);
void		handle_arg(int argc, char **argv, t_game *opts);
void		setup_game(t_game *flags);
void		parse_scene(char *path, t_game *flags);
void		get_rgb(t_game *opts, char *line);
void		get_path(t_game *opts, char *line, char *identifier);
void		create_map_buffer(t_game *opts, char *line);
double		get_cardinal_direction_angle(char c);
void		normalize_map_buffer(t_game *opts);
void		validate_map(t_game *opts);
void		validate_zeros(t_game *opts, char c);
void		build_map_matrix(t_game *opts);
void		log_parsed_info(t_game *opts);
void		exit_failure(char *info, t_game *opts);
void		exit_success(t_game *opts);
void		start_game_engine(t_game *opts);
void		setup_textures(t_game *opts, t_directions direction);
void		setup_sprite(t_game *opts);
int			close_window(t_game *opts);
int			game_loop(t_game *opts);
void		update_player(t_game *opts);
void		draw_pixel(t_game *opts, int x, int y, t_color color);
void		draw_line(t_game *opts);
void		draw_rect(t_game *opts);
void		render_ceil_and_floor(t_game *opts, t_color ceil, t_color floor);
void		render_minimap(t_game *opts);
void		render_rays(t_game *opts);
void		get_distance_to_projection_plane(t_game *opts);
void		render_wall_projection(t_game *opts);
void		render_sprite_projection(t_game *opts);
int			handle_keypress_event(int keycode, t_game *opts);
int			handle_keyrelease_event(int keycode, t_game *opts);
void		cast_all_rays(t_game *opts);
double		get_fov_angle(void);
double		get_rotation_speed(void);
double		distance_between_points(double x1, double y1, double x2, double y2);
double		normalize_angle(double angle);
int			get_texture_color(t_teximg tex, int x, int y);
t_bool		has_wall_at(t_game *opts, double new_player_x, double new_player_y);
int			handle_wall_texture_color(t_game *opts, int index, int offset_x,
				int offset_y);
void		handle_horz_intercept(t_game *opts, t_raycasting *horz,
				t_rayface ray_facing, double ray_angle);
void		handle_vert_intercept(t_game *opts, t_raycasting *vert,
				t_rayface ray_facing, double ray_angle);
#endif
