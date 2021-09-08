/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_character.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_ptr_funct_character(va_list *args, t_conversion tools)
{
	t_arg_types	type;

	type.u_char = va_arg(*args, int);
	if (tools.opts.width > 1 && !tools.flags.minus)
		ft_print_width(tools, 1);
	ft_putchar_fd(type.u_char, 1);
	if (tools.opts.width > 1 && tools.flags.minus)
		ft_print_width(tools, 1);
	return (tools.opts.width ? tools.opts.width : 1);
}
