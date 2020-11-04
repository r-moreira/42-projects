/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:11 by romoreir          #+#    #+#             */
/*   Updated: 2020/11/03 22:11:20 by rodrigo          ###   ########.fr       */
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
