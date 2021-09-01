/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:02:35 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/27 16:12:54 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_window(t_game *opts)
{
	mlx_destroy_window(opts->window.mlx, opts->window.ptr);
	opts->window.ptr = NULL;
	exit_success(opts);
	return (EXIT_SUCCESS);
}
