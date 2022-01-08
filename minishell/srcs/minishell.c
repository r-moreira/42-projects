/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/07 23:12:38 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdlib.h>

void	init_shell(t_shell *sh)
{
	(void)sh;
}

// TO-DO -> "$?"
// TO-DO - ENV/EXPORT se for att USER NAME OU HOME, chamar getEnv novamente
int	main(void)
{
	t_shell	sh;

	init_shell(&sh);
	run_signals();
	welcome_message();
	while (TRUE)
	{
		print_prompt();
		if (take_input(&sh) == SUCCESS)
			if (analyzer(&sh) == SUCCESS)
				if (parser(&sh) == SUCCESS)
					executor(&sh);
	}
	return (EXIT_SUCCESS);
}
