/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_to_proj_plane.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:27:37 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/10 18:27:51 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_distance_to_projection_plane(t_game *opts)
{
	double	dist_to_proj_plane;

	dist_to_proj_plane = (opts->window.width / 2) / tan(get_fov_angle() / 2);
	opts->utils.dist_to_proj_plane = dist_to_proj_plane;
}
