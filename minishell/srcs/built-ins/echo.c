/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:04:10 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/18 21:35:26 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_bool	has_n_option(t_shell *sh, int num)
{
	char	*option_arg;
	int		arg_len;

	option_arg = sh->cmds[num].args[1];
	if (!option_arg)
		return (FALSE);
	arg_len = ft_strlen(option_arg);
	if (arg_len <= 0 || arg_len > 2)
		return (FALSE);
	if (ft_strncmp(option_arg, "-n", 2) == 0)
		return (TRUE);
	return (FALSE);
}

static void	get_echo_str(char *input, t_bool n_opt)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * ft_strlen(input) + 1);
	i = 0;
	while (input[i] && !is_flag(input[i]))
	{
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	if (i > 0 && str[i - 1])
		if (is_flag(input[i]) && ft_isspace(str[i - 1]))
			str[i - 1] = '\0';
	if (n_opt)
		printf("%s", str);
	else
		printf("%s\n", str);
	free(str);
}

t_status	ft_echo(t_shell *sh, int num)
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
		get_echo_str(input + i, TRUE);
	}
	else
		get_echo_str(input + i, FALSE);
	return (SUCCESS);
}
