/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/28 03:09:37 by romoreir         ###   ########.fr       */
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



char	*cmd_tokenizer(char *input)
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

////////////TO-DO
// - Adicionar espaços antes e depois de '>' '>>' '<' '<<' '|' para o split funcionar direito
char	*normalize_cmd_token(char *cmd_token)
{
	return (cmd_token);
}

void	create_cmds_struct(t_shell *sh, char **cmd_tokens, int len)
{
	char	**cmd_token_split;
	int		i;
	int		j;

	i = -1;
	while (++i <= len)
	{
		printf("%s\n", cmd_tokens[i]);
		cmd_token_split = ft_split(normalize_cmd_token(cmd_tokens[i]), ' ');
		j = -1;
		while (cmd_token_split[++j])
			if (ft_strncmp(cmd_token_split[j], "", ft_strlen(cmd_token_split[j])))
				printf("%s|", cmd_token_split[j]);
		printf("\n");
		free(cmd_token_split);
	}
}

void	analyzer(t_shell *sh)
{
	char	*cmd_tokens[MAX_COMMANDS_NUM];
	int		pointer_position;
	int		i;

	i = -1;
	pointer_position = 0;
	while (pointer_position < ft_strlen(sh->input_string))
	{
		cmd_tokens[++i] = cmd_tokenizer(sh->input_string + pointer_position);
		pointer_position += ft_strlen(cmd_tokens[i]);
	}

	create_cmds_struct(sh, cmd_tokens, i);

	while (i-- > 0)
		free(cmd_tokens[i]);
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
