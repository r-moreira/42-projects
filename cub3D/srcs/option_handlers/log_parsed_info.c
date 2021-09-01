/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_parsed_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:07:49 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/10 16:02:06 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	log_map_info(t_game *opts)
{
	int	i;
	int	j;

	printf("\nGame Map\n");
	i = -1;
	while (++i < opts->map.rows_len)
	{
		j = -1;
		while (++j < opts->map.columns_len)
			printf("%d", opts->map.matrix[i][j]);
		printf("\n");
	}
}

static void	log_opts_info(t_game *opts)
{
	int	i;

	printf("Game Options\n");
	printf("floor r = %d | g = %d | b = %d\n", opts->floor.r, opts->floor.g,
		opts->floor.b);
	printf("ceil r = %d | g = %d | b = %d\n", opts->ceil.r, opts->ceil.g,
		opts->ceil.b);
	printf("tex.path.no = %s\n", opts->tex.path.no);
	printf("tex.path.so = %s\n", opts->tex.path.so);
	printf("tex.path.we = %s\n", opts->tex.path.we);
	printf("tex.path.ea = %s\n", opts->tex.path.ea);
	printf("tex.path.s = %s\n", opts->tex.path.s);
	printf("columns_len = %d\n", opts->map.columns_len);
	printf("rows_len = %d\n", opts->map.rows_len);
	printf("player start direction = %c\n", opts->player.start_direction);
	printf("player position: xy = %f-%f\n", opts->player.x, opts->player.y);
	printf("itens count = %d\n", opts->map.item_count);
	i = -1;
	while (++i < opts->map.item_count)
		printf("item %d position: xy = %f-%f\n", i, opts->map.itens[i].x,
			opts->map.itens[i].y);
}

void	log_parsed_info(t_game *opts)
{
	printf("---------------------------------\n");
	log_opts_info(opts);
	log_map_info(opts);
	printf("---------------------------------\n");
}
