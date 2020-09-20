/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_character.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:11:45 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 19:10:26 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_ptr_funct_character(va_list *args, t_conversion tools)
{
	t_arg_types	type;

	type._char = va_arg(*args, int);
	if (tools.opts.width > 1 && !tools.flags.minus)
		ft_print_width(tools, 1);
	ft_putchar_fd(type._char, 1);
	if (tools.opts.width > 1 && tools.flags.minus)
		ft_print_width(tools, 1);
	return (tools.opts.width ? tools.opts.width : 1);
}
