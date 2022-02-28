/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:34:20 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/28 00:04:48 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_bool	is_closed_sglquote(char *input)
{
	int	i;

	i = 0;
	while (input[++i])
		if (input[i] == '\'')
			return (TRUE);
	return (FALSE);
}

char	*get_env_token(char *in)
{
	int		i;
	char	*env_token;

	i = 1;
	while (in[i] && !ft_isspace(in[i]) && in[i] != '$'
		&& in[i] != '"' && in[i] != '\'')
		i++;
	env_token = ft_substr(in, 1, i - 1);
	return (env_token);
}

t_bool	is_status_var(char *line_read, int *i)
{
	if (line_read[(*i) + 1])
		if (line_read[*i] == '$' && line_read[*i + 1] == '?')
			return (TRUE);
	return (FALSE);
}

void	get_env_value(char *line_read, int *i, int *j, char *parsed_line_read)
{
	char	*env_value;
	char	*env_token;
	int		k;

	k = -1;
	env_token = get_env_token(line_read + *i);
	if (ft_strlen(env_token) == 0)
		parsed_line_read[++(*j)] = '$';
	else if (is_status_var(line_read, i))
	{
		env_value = ft_itoa(g_pid_number);
		while (env_value[++k])
			parsed_line_read[++(*j)] = env_value[k];
		free(env_value);
	}
	else
	{
		env_value = getenv(env_token);
		if (env_value != NULL)
			while (env_value[++k])
				parsed_line_read[++(*j)] = env_value[k];
	}
	*i += ft_strlen(env_token);
	free(env_token);
}

char	*parse_env_variables(char *line_read)
{
	int		i;
	int		j;
	char	*parsed_line_read;

	parsed_line_read = (char *)malloc(PARSED_LINE_BUFFER_SIZE);
	i = -1;
	j = -1;
	while (line_read[++i])
	{
		if (line_read[i] == '\'' && is_closed_sglquote(line_read + i))
		{
			parsed_line_read[++j] = line_read[i++];
			while (line_read[i] && line_read[i] != '\'')
				parsed_line_read[++j] = line_read[i++];
			parsed_line_read[++j] = line_read[i];
		}
		else if (line_read[i] == '$')
			get_env_value(line_read, &i, &j, parsed_line_read);
		else
			parsed_line_read[++j] = line_read[i];
	}
	parsed_line_read[++j] = '\0';
	return (parsed_line_read);
}
