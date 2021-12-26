/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:30:08 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/26 20:32:19 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void	print_prompt()
{
	char	cwd[DIR_MAX_SIZE];

	getcwd(cwd, sizeof(cwd));
	printf("\n%s", cwd);
	printf(" $> ");
}
