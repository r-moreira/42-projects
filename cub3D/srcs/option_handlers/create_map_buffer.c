/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:45:57 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/02 15:03:43 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static char	*update_buffer(char *buffer, char *piped_line)
{
	size_t	total_size;
	size_t	i;
	size_t	j;
	char	*new_buffer;

	total_size = ft_strlen((char *)buffer) + ft_strlen((char *)piped_line);
	new_buffer = (char *)malloc((sizeof(char) * total_size) + 1);
	i = -1;
	while (buffer[++i])
		new_buffer[i] = buffer[i];
	j = -1;
	while (piped_line[++j])
	{
		new_buffer[i] = piped_line[j];
		i++;
	}
	new_buffer[i] = '\0';
	if (ft_strncmp(buffer, EMPTY, sizeof(buffer)))
		free(buffer);
	free(piped_line);
	return (new_buffer);
}

void	create_map_buffer(t_game *opts, char *line)
{
	int		len;

	if (!ft_strncmp(line, EMPTY, ft_strlen(line)))
		return ;
	len = (int)ft_strlen(line);
	opts->map.buffer = update_buffer(opts->map.buffer,
			ft_strjoin(line, "|"));
	opts->map.rows_len++;
	if (opts->map.columns_len < len)
		opts->map.columns_len = len;
}
