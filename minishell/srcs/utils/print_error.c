/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:07:04 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/12 21:55:39 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>
#include <unistd.h>

t_status	print_error(char *err_message)
{
	ft_putstr_fd("ERROR: ", STDOUT_FILENO);
	ft_putstr_fd(err_message, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (ERROR);
}
