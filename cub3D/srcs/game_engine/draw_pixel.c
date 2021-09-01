/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:49:40 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/27 17:38:19 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_pixel(t_game *opts, int x, int y, t_color color)
{
	char	*pixel;

	pixel = opts->image.addr + (y * opts->image.line_len + x
			* (opts->image.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
