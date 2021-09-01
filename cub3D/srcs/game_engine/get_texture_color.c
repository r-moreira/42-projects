/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:17:38 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/10 19:18:41 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_texture_color(t_teximg tex, int x, int y)
{
	int		offset;

	offset = (y * tex.size_l + x * (tex.bpp / 8));
	return (*(unsigned int *)(tex.addr + offset + 2) << 16 |
			*(unsigned int *)(tex.addr + offset + 1) << 8 |
			*(unsigned int *)(tex.addr + offset + 0) << 0);
}
