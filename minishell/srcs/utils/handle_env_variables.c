/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:34:20 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/19 00:16:29 by romoreir         ###   ########.fr       */
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

	i = 0;
	while (!ft_isspace(input[i]))
		i++;
	env_token = ft_substr(input, 1, i - 1);
	return (env_token);
}

void	get_env_value(char *env, int *index, char *parsed_line_read)
{
	char	*env_value;
	char	*env_token;
	int		i;

	i = -1;
	env_token = get_env_token(env);
	env_value = getenv(env_token);
	if (env_value != NULL)
	{
		while (env_value[++i])
			parsed_line_read[++(*index)] = env_value[i];
	}
	else
	{
		parsed_line_read[++(*index)] = '$';
		while (env_token[++i])
			parsed_line_read[++(*index)] = env_token[i];
	}
}


//$USER aloalo $TERM aaaaaaaaaaa$USER $USER $USR AAAAAAoo $USER$TERM
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
			get_env_value(line_read + i, &j, parsed_line_read);
			i += ft_strlen(get_env_token(line_read + i));
		}
		else
			parsed_line_read[++j] = line_read[i];
	}
	parsed_line_read[++j] = '\0';
	printf("|%s|\n", parsed_line_read);
	return (parsed_line_read);
}





//loop
//  se $ENV - pegar token
//	se ', verificar se fecha, caso sim, pular até o fechamento

/*
//echo $USER -ok
//echo$USER -corrigir
//echo $USER lalal $TERM -verificar
//echo $USER lalal$TERM oi -verificar
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
		if (i == 0 && line_read[i] == '$'
			|| i >= 1 && line_read[i] == '$' && line_read[i - 1] == ' ')
		{
			printf("OI%c\n", line_read[i]);
			env_value = get_env_value(line_read + i);
			if (env_value != NULL)
			{
				ft_strcat(parsed_line_read, env_value);
				i += ft_strlen(get_env_token(line_read + i));
				j += ft_strlen(env_value);
			}
			else
				parsed_line_read[++j] = line_read[i];
		}
		else
			parsed_line_read[++j] = line_read[i];
	}
	printf("|%s|%s|\n", line_read, parsed_line_read);
	parsed_line_read[++j] = '\0';
	return (parsed_line_read);
}
*/
