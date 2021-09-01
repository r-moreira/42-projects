/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:02:08 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/11 10:14:59 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	texture_and_sprite_images_init(t_game *opts)
{
	setup_textures(opts, NORTH);
	setup_textures(opts, SOUTH);
	setup_textures(opts, WEST);
	setup_textures(opts, EAST);
	setup_sprite(opts);
}

static void	game_window_init(t_game *opts)
{
	opts->window.mlx = mlx_init();
	if (opts->window.mlx == NULL)
		exit_failure("Cannot initialize minilibX", opts);
	opts->window.ptr = mlx_new_window(opts->window.mlx, opts->window.width,
			opts->window.height, "Cub3D");
	if (opts->window.ptr == NULL)
		exit_failure("Cannot initialize the game window", opts);
}

static void	game_image_init(t_game *opts)
{
	opts->image.ptr = mlx_new_image(opts->window.mlx, opts->window.width,
			opts->window.height);
	if (opts->image.ptr == NULL)
		exit_failure("Cannot initialize game image", opts);
	opts->image.addr = mlx_get_data_addr(opts->image.ptr,
			&opts->image.bits_per_pixel,
			&opts->image.line_len,
			&opts->image.endian);
	if (opts->image.addr == NULL
		|| opts->image.endian == UNDEFINED
		|| opts->image.line_len == UNDEFINED
		|| opts->image.endian == UNDEFINED)
	{
		mlx_destroy_window(opts->window.mlx, opts->window.ptr);
		opts->window.ptr = NULL;
		exit_failure("Cannot get the game image data", opts);
	}
}

void	setup_engine(t_game *opts)
{
	int		i;

	opts->player.x = opts->player.x * TILE_SIZE;
	opts->player.y = opts->player.y * TILE_SIZE;
	opts->window.width = opts->map.columns_len * TILE_SIZE;
	opts->window.height = opts->map.rows_len * TILE_SIZE;
	opts->utils.num_rays = opts->window.width / WALL_STRIP_WIDTH;
	opts->rays = (t_ray *)malloc((sizeof(t_ray) * opts->utils.num_rays) + 1);
	opts->sprites = (t_sprite *)malloc(sizeof(t_sprite)
			* opts->map.item_count + 1);
	i = -1;
	while (++i < opts->map.item_count)
	{
		opts->sprites[i].x = opts->map.itens[i].x * TILE_SIZE;
		opts->sprites[i].y = opts->map.itens[i].y * TILE_SIZE;
	}
	get_distance_to_projection_plane(opts);
}

void	start_game_engine(t_game *opts)
{
	setup_engine(opts);
	game_window_init(opts);
	game_image_init(opts);
	texture_and_sprite_images_init(opts);
	mlx_hook(opts->window.ptr, X_EVENT_EXIT, 0, close_window, opts);
	mlx_hook(opts->window.ptr, X_EVENT_KEY_PRESS, 1L << 0,
		handle_keypress_event, opts);
	mlx_hook(opts->window.ptr, X_EVENT_KEY_RELEASE, 1L << 1,
		handle_keyrelease_event, opts);
	mlx_loop_hook(opts->window.mlx, game_loop, opts);
	mlx_loop(opts->window.mlx);
}
