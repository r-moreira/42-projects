/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:06:02 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/10 19:34:16 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	setup_sprite(t_game *opts)
{
	opts->tex.s.ptr = NULL;
	opts->tex.s.addr = NULL;
	opts->tex.s.ptr = mlx_xpm_file_to_image(opts->window.mlx,
			opts->tex.path.s, &opts->tex.s.width, &opts->tex.s.height);
	if (opts->tex.s.ptr == NULL)
		exit_failure("Fail to load sprite texture", opts);
	opts->tex.s.addr = mlx_get_data_addr(opts->tex.s.ptr,
			&opts->tex.s.bpp, &opts->tex.s.size_l, &opts->tex.s.endian);
	if (opts->tex.s.addr == NULL)
		exit_failure("Fail to load sprite texture", opts);
}
