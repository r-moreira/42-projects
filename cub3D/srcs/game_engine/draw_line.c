/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	clean_line_struct(t_game *opts)
{
	opts->line.x0 = 0;
	opts->line.y0 = 0;
	opts->line.x1 = 0;
	opts->line.y1 = 0;
	opts->line.delta_x = 0;
	opts->line.delta_y = 0;
	opts->line.x_increment = 0;
	opts->line.y_increment = 0;
	opts->line.color = 0;
}

void	draw_line(t_game *opts)
{
	double	longest_side_len;
	double	current_x;
	double	current_y;
	int		i;

	opts->line.delta_x = opts->line.x1 - opts->line.x0;
	opts->line.delta_y = opts->line.y1 - opts->line.y0;
	if (abs(opts->line.delta_x) >= abs(opts->line.delta_y))
		longest_side_len = abs(opts->line.delta_x);
	else
		longest_side_len = abs(opts->line.delta_y);
	opts->line.x_increment = opts->line.delta_x / (float)longest_side_len;
	opts->line.y_increment = opts->line.delta_y / (float)longest_side_len;
	current_x = opts->line.x0;
	current_y = opts->line.y0;
	i = -1;
	while (++i < longest_side_len)
	{
		draw_pixel(opts, round(current_x), round(current_y),
			opts->line.color);
		current_x += opts->line.x_increment;
		current_y += opts->line.y_increment;
	}
	clean_line_struct(opts);
}
