/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/01 16:58:58 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_pid_number;

int	main(int argc, char **argv, char **envp)
{
	t_shell	sh;

	(void)argc;
	(void)argv;
	init_shell(&sh, envp);
	welcome_message();
	while (TRUE)
	{
		run_signals_interactive();
		setup_info(&sh);
		if (take_input(&sh) == SUCCESS)
			if (analyzer(&sh) == SUCCESS)
				if (parser(&sh) == SUCCESS)
					executor(&sh);
	}
	return (EXIT_SUCCESS);
}
