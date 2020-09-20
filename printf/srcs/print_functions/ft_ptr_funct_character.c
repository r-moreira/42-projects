/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_character.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:11:45 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 14:11:45 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_ptr_funct_character(va_list *args, t_conversion tools)
{
	t_arg_types	type;

	type._char = va_arg(*args, int);
	if (PAD_LEFT(1))
		ft_print_width(tools, 1);
	ft_putchar_fd(type._char, 1);
	if (PAD_RIGTH(1))
		ft_print_width(tools, 1);
	return (tools.opts.width ? tools.opts.width : 1);
}
