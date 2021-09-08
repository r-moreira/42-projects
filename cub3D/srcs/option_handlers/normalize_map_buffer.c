/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	validate_buffer_characters(t_game *opts, char **sb)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < (opts->map.rows_len))
	{
		j = -1;
		while (++j < (int)ft_strlen(sb[i]))
		{
			c = sb[i][j];
			if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '\t'
				&& c != ' ' && c != SPACE_C && c != WALL_C && c != ITEM_C)
				exit_failure(
					"There is duplicated options or forbidden map characteres.",
					opts);
		}
	}
}

static void	push_normalized_data(t_game *opts, char **sb)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (opts->map.rows_len))
	{
		j = -1;
		while (++j < (opts->map.columns_len))
		{
			if (j < (int)ft_strlen(sb[i]))
				opts->map.bnormalized[i][j] = sb[i][j];
			else
				opts->map.bnormalized[i][j] = ' ';
		}
	}
}

static void	handle_itens_info(t_game *opts, char **sb)
{
	int	i;
	int	j;
	int	item_len;

	opts->map.itens
		= (t_item *)malloc(opts->map.item_count * sizeof(t_item) + 1);
	item_len = 0;
	i = -1;
	while (++i < (opts->map.rows_len))
	{
		j = -1;
		while (++j < (int)ft_strlen(sb[i]))
		{
			if (sb[i][j] == ITEM_C)
			{
				opts->map.itens[item_len].code = ITEM_C;
				opts->map.itens[item_len].y = i;
				opts->map.itens[item_len].x = j;
				item_len++;
			}
		}
	}
}

static void	handle_player_info(t_game *opts, char **sb)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (opts->map.rows_len))
	{
		j = -1;
		while (++j < (int)ft_strlen(sb[i]))
		{
			if (sb[i][j] == 'N' || sb[i][j] == 'S'
				|| sb[i][j] == 'E' || sb[i][j] == 'W')
			{
				if (opts->player.start_direction)
					exit_failure("There is more than one player", opts);
				opts->player.start_direction = sb[i][j];
				opts->player.y = i;
				opts->player.x = j;
				sb[i][j] = SPACE_C;
			}
			if (sb[i][j] == ITEM_C)
				opts->map.item_count++;
		}
	}
	opts->player.rotation_angle
		= get_cardinal_direction_angle(opts->player.start_direction);
}

void	normalize_map_buffer(t_game *opts)
{
	int		i;
	char	**splited_buffer;

	if (opts->utils.is_all_configs_parsed == FALSE)
		exit_failure("The .cub file is missing options", opts);
	opts->map.bnormalized
		= (char **)malloc((opts->map.rows_len * sizeof(char *)) + 1);
	i = -1;
	while (++i < opts->map.rows_len)
		opts->map.bnormalized[i]
			= (char *)malloc((opts->map.columns_len * sizeof(char)) + 1);
	splited_buffer = ft_split(opts->map.buffer, '|');
	validate_buffer_characters(opts, splited_buffer);
	handle_player_info(opts, splited_buffer);
	if (!opts->player.start_direction)
		exit_failure("There is not a player in the game map.", opts);
	handle_itens_info(opts, splited_buffer);
	push_normalized_data(opts, splited_buffer);
	i = -1;
	while (splited_buffer[++i])
		free(splited_buffer[i]);
	free(splited_buffer);
}
