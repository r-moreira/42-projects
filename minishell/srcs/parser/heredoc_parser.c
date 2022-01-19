/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:19:59 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/18 22:17:16 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*parse_heredoc_input_end(char *parsed_line)
{
	int		i;
	int		j;
	int		len;
	char	*input_end;

	i = 1;
	while (TRUE)
	{
		if (parsed_line[i - 1] == '<' && parsed_line[i] == '<')
			break ;
		i++;
	}
	while (ft_isspace(parsed_line[i]))
		i++;
	len = ft_strlen(parsed_line);
	input_end = (char *)malloc(sizeof(char) * (len - i) + 1);
	j = -1;
	while (i++ < len && !is_flag(parsed_line[i]))
		if (!ft_isspace(parsed_line[i]))
			input_end[++j] = parsed_line[i];
	input_end[++j] = '\0';
	return (input_end);
}
