/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:04:10 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/15 16:07:40 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_bool	has_n_option(t_shell *sh, int num)
{
	char	*option_arg;
	int		arg_len;

	option_arg = sh->cmds[num].args[1];
	arg_len = ft_strlen(option_arg);
	if (arg_len <= 0 || arg_len > 2)
		return (FALSE);
	if (ft_strncmp(option_arg, "-n", 2) == 0)
		return (TRUE);
	return (FALSE);
}

t_status	input_echo(t_shell *sh, int num)
{
	char			*input;
	int				i;

	input = sh->input_string + 4;
	i = 0;
	while (ft_isspace(input[i]))
		i++;
	if (has_n_option(sh, num))
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
//Adicionar in e out fd na struct dependendo da flag;
//No CMD2+ Percorrer input até a flag do comando anterior,
//	ignorando quando tiver entre aspas
t_status	ft_echo(t_shell *sh, int num)
{
	if (num == 0
		&& sh->cmds[num].heredoc == FALSE
		&& sh->cmds[num].redin.len == 0
		&& sh->cmds[num].redout.len == 0
		&& sh->cmds[num].redout_apd.len == 0)
	{
		return (input_echo(sh, num));
	}
	printf("ERROR - ECHO ON CMD 2+ AND FLAG NOT IMPLEMENTED\n");
	return (ERROR);
}
