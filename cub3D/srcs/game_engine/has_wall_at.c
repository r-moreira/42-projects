/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:03:36 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/10 20:05:05 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_bool	has_wall_at(t_game *opts, double new_player_x, double new_player_y)
{
	int		map_x;
	int		map_y;

	if (new_player_x < 0 || new_player_x > opts->window.width)
		return (TRUE);
	if (new_player_y < 0 || new_player_y > opts->window.height)
		return (TRUE);
	map_x = floor(new_player_x / TILE_SIZE);
	map_y = floor(new_player_y / TILE_SIZE);
	return (opts->map.matrix[map_y][map_x] != SPACE_N &&
		opts->map.matrix[map_y][map_x] != ITEM_N);
}
