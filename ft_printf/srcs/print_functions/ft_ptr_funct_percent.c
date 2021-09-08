/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int				ft_ptr_funct_percent(va_list *args, t_conversion tools)
{
	(void)args;
	if (tools.opts.width > 1 && !tools.flags.minus)
		ft_print_width(tools, 1);
	ft_putchar_fd('%', 1);
	if (tools.opts.width > 1 && tools.flags.minus)
		ft_print_width(tools, 1);
	return (tools.opts.width > 1 ? tools.opts.width : 1);
}
