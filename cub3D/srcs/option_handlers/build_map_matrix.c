/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	malloc_normalized_matrix(t_game *opts)
{
	int	x;
	int	y;
	int	i;

	y = opts->map.rows_len;
	x = opts->map.columns_len;
	opts->map.matrix = (int **)malloc((y * sizeof(int *)) + 1);
	i = -1;
	while (++i < y)
		opts->map.matrix[i] = (int *)malloc((x * sizeof(int *)) + 1);
}

static void	create_map_matrix(t_game *opts)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < opts->map.rows_len)
	{
		j = -1;
		while (++j < opts->map.columns_len)
		{
			c = opts->map.bnormalized[i][j];
			if (c == ' ' || c == '\t')
				c = '1';
			opts->map.matrix[i][j] = c - '0';
		}
	}
}

void	build_map_matrix(t_game *opts)
{
	malloc_normalized_matrix(opts);
	create_map_matrix(opts);
}
