/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/18 11:56:52 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

////////////////////TO-DOs
// Redirections/Pipe Fix
//		- Redir in + Redir out
// Lidar com signals - BUG printando 2 prompts em CTRL+C no exec.
// Fix memory leak e crash $HOME - env variables
// Garantir o retorno do PID para: "$?"
// Ajustar o signal CTRL + C para o heredoc
/////////////////////////
int	main(int argc, char **argv, char **envp)
{
	t_shell	sh;

	(void)argc;
	(void)argv;
	init_shell(&sh, envp);
	run_signals();
	welcome_message();
	while (TRUE)
	{
		print_prompt(); //Se o último processo foi cancelado com CTRL+C, não printar prompt
		if (take_input(&sh) == SUCCESS)
			if (analyzer(&sh) == SUCCESS)
				if (parser(&sh) == SUCCESS)
					executor(&sh);
	}
	return (EXIT_SUCCESS);
}
