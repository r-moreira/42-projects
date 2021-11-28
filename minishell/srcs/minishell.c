/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/28 00:31:59 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"
#include <stdio.h>

void	init_shell(t_shell *sh)
{
	(void)sh;
}

char	*command_tokenizer(char *input)
{
	int i;
	char *token;

	token = (char *)malloc(sizeof(char) * (ft_strlen((char *)input) + 1));
	i = -1;
	while (input[++i])
	{
		if (input[i] != '|' && input[i] != '>' && input[i] != '<')
			token[i] = input[i];
		else {
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

//void	create_command_struct(t_shell *sh)
//{
//	sh->commands[0].name = ft_strdup("ls");
//	sh->commands[0].args[0] = ft_strdup("-l");
//	sh->commands[0].args[1] = ft_strdup("-a");
//	sh->commands[0].args[2] = NULL;
//	sh->commands->flag = PIPE;
//}

void	analyzer(t_shell *sh)
{
	char *input;
	char *command_token;

	input = ft_strdup("");
	ft_strlcpy(input, sh->input_string, sizeof(sh->input_string));
	command_token = command_tokenizer(input);

	printf("%s\n", command_token);
	printf("%s\n", input + ft_strlen(command_token));

	free(command_token);
	free(input);
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
