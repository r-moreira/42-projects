/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	draw_minimap_square(t_game *opts, t_color square, t_color border)
{
	int	i;
	int	j;
	int	tile_x;
	int	tile_y;

	tile_x = (opts->image.current_row * TILE_SIZE) * MINIMAP_SCALE;
	tile_y = (opts->image.current_col * TILE_SIZE) * MINIMAP_SCALE;
	i = 0;
	while (i < TILE_SIZE * MINIMAP_SCALE)
	{
		j = 0;
		while (j < TILE_SIZE * MINIMAP_SCALE)
		{
			if (i == 0 || i == (MINIMAP_SCALE - 1)
				|| j == 0 || j == (MINIMAP_SCALE - 1))
				draw_pixel(opts, tile_x + j, tile_y + i, border);
			else
				draw_pixel(opts, tile_x + j, tile_y + i, square);
			j++;
		}
		i++;
	}
}

static void	draw_minimap(t_game *opts)
{
	int	y;
	int	x;

	y = 0;
	while (y < opts->map.rows_len)
	{
		x = 0;
		while (x < opts->map.columns_len)
		{
			opts->image.current_row = x;
			opts->image.current_col = y;
			if (opts->map.matrix[y][x] == WALL_N)
				draw_minimap_square(opts, color_picker(255, 255, 255),
					color_picker(0, 0, 0));
			else
				draw_minimap_square(opts, color_picker(0, 0, 0),
					color_picker(0, 0, 0));
			x++;
		}
		y++;
	}
}

static void	draw_player(t_game *opts, int radius, t_color player)
{
	int	x;
	int	y;
	int	tile_x;
	int	tile_y;

	tile_x = opts->player.x * MINIMAP_SCALE;
	tile_y = opts->player.y * MINIMAP_SCALE;
	x = tile_x - radius;
	y = tile_y - radius;
	while (y <= tile_y + radius)
	{
		while (x <= tile_x + radius)
		{
			if ((pow(x - tile_x, 2) + pow(y - tile_y, 2)) <= pow(radius, 2))
				draw_pixel(opts, x, y, player);
			x++;
		}
		y++;
		x = tile_x - radius;
	}
}

static void	draw_itens(t_game *opts, int radius, t_color itens, int count)
{
	int	x;
	int	y;
	int	tile_x;
	int	tile_y;

	tile_x = (opts->map.itens[count].x * TILE_SIZE * MINIMAP_SCALE);
	tile_y = (opts->map.itens[count].y * TILE_SIZE * MINIMAP_SCALE);
	x = tile_x - radius;
	y = tile_y - radius;
	while (y <= tile_y + radius)
	{
		while (x <= tile_x + radius)
		{
			if ((pow(x - tile_x, 2) + pow(y - tile_y, 2)) <= pow(radius, 2))
				draw_pixel(opts, x, y, itens);
			x++;
		}
		y++;
		x = tile_x - radius;
	}
}

void	render_minimap(t_game *opts)
{
	int	count;

	draw_minimap(opts);
	draw_player(opts, MINIMAP_SCALE * PLAYER_SCALE, color_picker(0, 0, 255));
	render_rays(opts);
	count = -1;
	while (++count < opts->map.item_count)
		draw_itens(opts, MINIMAP_SCALE * ITENS_SCALE,
			color_picker(0, 255, 0), count);
}
