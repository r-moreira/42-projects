/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:34:20 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/19 00:28:17 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"
#include <stdio.h>

//TO-DO:
static	t_bool is_open_sglquote(char *input)
{
	int	i;

	i = 0;
	while (input[++i])
		if (input[i] == '\'')
			return (i);
	return 0;
}

char	*get_env_token(char *input)
{
	int		i;
	char	*env_token;

	i = 1;
	while (!ft_isspace(input[i]) && input[i] != '$')
		i++;
	env_token = ft_substr(input, 1, i - 1);
	return (env_token);
}

void	get_env_value(char *line_read, int *i, int *j, char *parsed_line_read)
{
	char	*env_value;
	char	*env_token;
	int		k;

	k = -1;
	env_token = get_env_token(line_read + *i);
	env_value = getenv(env_token);
	if (env_value != NULL)
	{
		while (env_value[++k])
			parsed_line_read[++(*j)] = env_value[k];
	}
	else
	{
		parsed_line_read[++(*j)] = '$';
		while (env_token[++k])
			parsed_line_read[++(*j)] = env_token[k];
	}
	*i += ft_strlen(get_env_token(line_read + *i));
}

// TO-DOs
//Handle envvars, ex: $USER aloalo $TERM aaaaaaaaaaa$USER $USER $USR AAAAAAoo $USER$TERM - OK
//Handle quotes and vars, ex: -
char	*handle_env_variables(char *line_read)
{
	int		i;
	int		j;
	char	*parsed_line_read;
	char	*env_value;

	parsed_line_read = (char*)malloc(PARSED_LINE_BUFFER_SIZE);
	i = -1;
	j = -1;
	while (line_read[++i])
	{
		if (line_read[i] == '$')
		{
			get_env_value(line_read, &i, &j, parsed_line_read);
		}
		else
			parsed_line_read[++j] = line_read[i];
	}
	parsed_line_read[++j] = '\0';
	printf("|%s|\n", parsed_line_read);
	return (parsed_line_read);
}
