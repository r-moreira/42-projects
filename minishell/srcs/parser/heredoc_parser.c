/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:19:59 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/02 23:54:14 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*parse_heredoc_input_end(char *token)
{
	int		i;
	int		j;
	int		len;
	char	*input_end;

	printf("TOKEN = |%s| - |%s|\n\n", token, token + 1);
	i = 0;
	while (ft_isspace(token[i]))
		i++;
	len = ft_strlen(token);
	input_end = (char *)malloc(sizeof(char) * (len - i) + 1);
	j = -1;
	while (i < len && !is_flag(token[i]) && !ft_isspace(token[i]))
		input_end[++j] = token[i++];
	input_end[++j] = '\0';
	return (input_end);
}
