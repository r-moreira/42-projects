/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/28 01:43:08 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	init_shell(t_shell *sh)
{
	(void)sh;
}

char	*command_tokenizer(char *input)
{
	int		i;
	char	*token;

	token = (char *)malloc(sizeof(char) * (ft_strlen((char *)input) + 1));
	i = -1;
	while (input[++i])
	{
		if (input[i] != '|' && input[i] != '>' && input[i] != '<')
			token[i] = input[i];
		else
		{
			token[i] = input[i];
			if (input[i + 1] == '>' || input[i + 1] == '<')
			{
				i++;
				token[i] = input[i];
			}
			token[++i] = '\0';
			return (token);
		}
	}
	token[i] = '\0';
	input = NULL;
	return (token);
}

void	analyzer(t_shell *sh)
{
	char	*command_tokens[MAX_COMMANDS_NUM];
	int		pointer_position;
	int		i;

	pointer_position = 0;
	i = 0;
	while (pointer_position < ft_strlen(sh->input_string))
	{
		command_tokens[i] = command_tokenizer(sh->input_string + pointer_position);
		pointer_position += ft_strlen(command_tokens[i]);
		printf("%s\n", command_tokens[i]);
		i++;
	}

	while (--i > 0)
		free(command_tokens[i]);
}

int	main(void)
{
	t_shell	sh;

	init_shell(&sh);
	welcome_message();
	while (TRUE)
	{
		print_dir();
		take_input(&sh);
		analyzer(&sh);
	}
	return (EXIT_SUCCESS);
}
