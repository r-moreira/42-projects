/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/12 21:38:57 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	init_shell(t_shell *sh)
{
	sh->cmds_count = 0;
	sh->cmds->args_count = 0;
}

int	main(void)
{
	t_shell	sh;

	init_shell(&sh);
	welcome_message();
	while (TRUE)
	{
		print_dir();
		if (take_input(&sh) == SUCCESS)
			analyzer(&sh);
	}
	return (EXIT_SUCCESS);
}
