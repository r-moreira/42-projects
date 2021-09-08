/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	validate_arg_length(int argc, t_game *opts)
{
	if (argc > 2 || argc == 1)
		exit_failure("Invalid number of arguments", opts);
}

static void	validate_extension(char *map_path, t_game *opts)
{
	if (ft_strncmp(map_path + (ft_strlen(map_path) - 4), ".cub", 4))
		exit_failure("Invalid scene file extension.", opts);
}

void	handle_arg(int argc, char **argv, t_game *opts)
{
	validate_arg_length(argc, opts);
	validate_extension(argv[1], opts);
}
