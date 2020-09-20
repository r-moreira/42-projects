/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:10:29 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 14:10:29 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		ft_print_precision(t_conversion tools, int len)
{
	if (tools.opts.precision <= len)
		return ;
	while (tools.opts.precision-- > len)
		ft_putchar_fd('0', 1);
}
