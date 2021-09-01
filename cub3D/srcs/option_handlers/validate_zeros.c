/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_zeros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:27:40 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/27 16:12:41 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	validate_zeros(t_game *opts, char c)
{
	if (c == ' ' || c == '\t')
		exit_failure("There is whitespaces around zeros.", opts);
}
