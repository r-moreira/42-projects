/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/27 23:21:49 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

////////////////////TO-DOs
// 1) Criar ex8ecução
//
// 2) Iniciar testes
/////////////////////////

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
