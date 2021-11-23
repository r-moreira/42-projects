/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:09 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/22 21:34:52 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_dir(void)
{
	char	cwd[DIR_MAX_SIZE];

	getcwd(cwd, sizeof(cwd));
	printf("\n%s", cwd);
}
