/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cardinal_direction_angle.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:47:34 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/31 15:53:52 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	get_cardinal_direction_angle(char c)
{
	if (c == 'N')
		return ((3 * PI) / 2);
	else if (c == 'S')
		return (PI / 2);
	else if (c == 'E')
		return (0);
	else if (c == 'W')
		return (PI);
	return (-1);
}
