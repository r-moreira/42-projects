/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 21:04:25 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/24 17:40:10 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	opts;

	setup_game(&opts);
	handle_arg(argc, argv, &opts);
	parse_scene(argv[1], &opts);
	start_game_engine(&opts);
	return (EXIT_SUCCESS);
}
