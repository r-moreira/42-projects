/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:51:47 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/24 17:12:05 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	setup_game_options(t_game *opts)
{
	opts->show_minimap = FALSE;
	opts->window.width = UNDEFINED;
	opts->window.height = UNDEFINED;
	opts->tex.path.no = NULL;
	opts->tex.path.so = NULL;
	opts->tex.path.we = NULL;
	opts->tex.path.ea = NULL;
	opts->tex.path.s = NULL;
	opts->floor.r = UNDEFINED;
	opts->floor.g = UNDEFINED;
	opts->floor.b = UNDEFINED;
	opts->ceil.r = UNDEFINED;
	opts->ceil.g = UNDEFINED;
	opts->ceil.b = UNDEFINED;
	opts->map.buffer = EMPTY;
	opts->map.bnormalized = NULL;
	opts->map.matrix = NULL;
	opts->map.columns_len = 0;
	opts->map.rows_len = 0;
	opts->map.item_count = 0;
	opts->map.itens = NULL;
	opts->utils.is_all_configs_parsed = FALSE;
}

static void	setup_player_data(t_game *opts)
{
	opts->player.start_direction = 0;
	opts->player.rotation_speed = get_rotation_speed();
	opts->player.move_speed = MOVE_SPEED;
}

static void	setup_game_engine(t_game *opts)
{
	opts->window.mlx = NULL;
	opts->window.ptr = NULL;
	opts->image.addr = NULL;
	opts->image.ptr = NULL;
	opts->rays = NULL;
	opts->sprites = NULL;
}

void	setup_game(t_game *opts)
{
	setup_game_options(opts);
	setup_player_data(opts);
	setup_game_engine(opts);
}
