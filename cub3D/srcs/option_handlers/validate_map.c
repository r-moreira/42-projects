/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	validate_north_walls(t_game *opts)
{
	int		x;
	int		y;
	char	p1;
	char	p2;

	x = 0;
	while (++x < opts->map.columns_len - 1)
	{
		y = 0;
		while (++y < opts->map.rows_len - 1)
		{
			p1 = opts->map.bnormalized[y][x];
			p2 = opts->map.bnormalized[y - 1][x];
			if (p1 == SPACE_C || p1 == ITEM_C)
			{
				if (p2 != WALL_C)
					exit_failure("The north is not closed with walls.", opts);
				else
					break ;
			}
		}
	}
}

static void	validate_south_walls(t_game *opts)
{
	int		x;
	int		y;
	char	p1;
	char	p2;

	x = 0;
	while (++x < opts->map.columns_len - 1)
	{
		y = opts->map.rows_len - 1;
		while (--y > 0)
		{
			p1 = opts->map.bnormalized[y][x];
			p2 = opts->map.bnormalized[y + 1][x];
			if (p1 == SPACE_C || p1 == ITEM_C)
			{
				if (p2 != WALL_C)
					exit_failure("The south is not closed with walls.", opts);
				else
					break ;
			}
		}
	}
}

static void	validate_west_walls(t_game *opts)
{
	int		x;
	int		y;
	char	p1;
	char	p2;

	y = 0;
	while (++y < opts->map.rows_len - 1)
	{
		x = 0;
		while (++x < opts->map.columns_len - 1)
		{
			p1 = opts->map.bnormalized[y][x];
			p2 = opts->map.bnormalized[y][x - 1];
			if (p1 == SPACE_C || p1 == ITEM_C)
			{
				if (p2 != WALL_C)
					exit_failure("The west is not closed with walls.", opts);
				else
					break ;
			}
		}
	}
}

static void	validate_east_walls(t_game *opts)
{
	int		x;
	int		y;
	char	p1;
	char	p2;

	y = opts->map.rows_len - 1;
	while (--y > 0)
	{
		x = opts->map.columns_len - 1;
		while (--x > 0)
		{
			p1 = opts->map.bnormalized[y][x];
			p2 = opts->map.bnormalized[y][x + 1];
			if (p1 == SPACE_C || p1 == ITEM_C)
			{
				if (p2 != WALL_C)
					exit_failure("The east is not closed with walls.", opts);
				else
					break ;
			}
		}
	}
}

void	validate_map(t_game *opts)
{
	int		x;
	int		y;

	validate_west_walls(opts);
	validate_east_walls(opts);
	y = 0;
	while (++y < opts->map.rows_len - 1)
	{
		x = 0;
		while (++x < opts->map.columns_len - 1)
		{
			if (opts->map.bnormalized[y][x] == SPACE_C)
			{
				validate_zeros(opts, opts->map.bnormalized[y + 1][x]);
				validate_zeros(opts, opts->map.bnormalized[y - 1][x]);
				validate_zeros(opts, opts->map.bnormalized[y][x + 1]);
				validate_zeros(opts, opts->map.bnormalized[y][x - 1]);
			}
		}
	}
	validate_north_walls(opts);
	validate_south_walls(opts);
}
