/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:19:07 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/05 23:23:32 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	ft_unset(t_shell *sh)
{
	printf("Calling unset...\n");
	(void)sh;
	return (SUCCESS);
}
