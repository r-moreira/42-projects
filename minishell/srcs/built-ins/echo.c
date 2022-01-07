/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:04:10 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/07 18:41:48 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

static t_bool	has_n_option(t_shell *sh, int cmd_num)
{
	char	*option_arg;
	int		arg_len;

	option_arg = sh->cmds[cmd_num].args[1];
	arg_len = ft_strlen(option_arg);
	if (arg_len <= 0 || arg_len > 2)
		return (FALSE);
	if (ft_strncmp(option_arg, "-n", 2) == 0)
		return (TRUE);
	return (FALSE);
}

t_status	input_echo(t_shell *sh, int cmd_num)
{
	char			*input;
	int				i;

	input = sh->input_string + 4;
	i = 0;
	while (ft_isspace(input[i]))
		i++;
	if (has_n_option(sh, cmd_num))
	{
		i += 2;
		while (ft_isspace(input[i]))
			i++;
		printf("%s", input + i);
	}
	else
		printf("%s\n", input + i);
	return (SUCCESS);
}

//TO-DO
//Adicionar tratamento de flags ao comando (> < | >> <<)
t_status	ft_echo(t_shell *sh, int cmd_num)
{
	if (cmd_num == 0)
		return (input_echo(sh, cmd_num));
	printf("ERROR - ECHO ON CMD 2+ NOT IMPLEMENTED\n");
	return (ERROR);
}
