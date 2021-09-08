/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	free_game_engine(t_game *opts)
{
	if (opts->rays)
		free(opts->rays);
	if (opts->sprites)
		free(opts->sprites);
	if (opts->window.mlx && opts->window.ptr)
		mlx_destroy_window(opts->window.mlx, opts->window.ptr);
}

static void	free_game_map(t_game *opts)
{
	int	i;

	if (opts->map.itens)
		free(opts->map.itens);
	if (ft_strncmp(opts->map.buffer, EMPTY, sizeof(EMPTY)))
		free(opts->map.buffer);
	if (opts->map.bnormalized)
	{
		i = -1;
		while (++i < opts->map.rows_len)
			free(opts->map.bnormalized[i]);
		free(opts->map.bnormalized);
	}
	if (opts->map.matrix)
	{
		i = -1;
		while (++i < opts->map.rows_len)
			free(opts->map.matrix[i]);
		free(opts->map.matrix);
	}
}

static void	free_game_options(t_game *opts)
{
	if (opts->tex.path.no)
		free(opts->tex.path.no);
	if (opts->tex.path.so)
		free(opts->tex.path.so);
	if (opts->tex.path.we)
		free(opts->tex.path.we);
	if (opts->tex.path.ea)
		free(opts->tex.path.ea);
	if (opts->tex.path.s)
		free(opts->tex.path.s);
}

void	exit_failure(char *info, t_game *opts)
{
	free_game_options(opts);
	free_game_map(opts);
	free_game_engine(opts);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno && errno != EXIT_MASK_ERRNO)
		perror(info);
	else
		ft_putstr_fd(info, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	exit_success(t_game *opts)
{
	free_game_options(opts);
	free_game_map(opts);
	free_game_engine(opts);
	ft_putstr_fd("Info\nExit Success", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
