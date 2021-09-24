/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:39:12 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/24 20:39:13 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_failure(char *info)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(info, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
