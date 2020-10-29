/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width_precision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:10:50 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/29 19:43:05 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_print_string_width(t_conversion tools, int len)
{
	int		pad_len;

	pad_len = tools.opts.width - len;
	while (pad_len--)
		ft_putchar_fd(' ', 1);
}

static void	ft_print_number_width(t_conversion tools, int len)
{
	int		pad_len;
	char	pad_char;

	if (tools.opts.width <= tools.opts.precision)
		return ;
	if (tools.opts.precision > len && tools.opts.width > tools.opts.precision)
	{
		pad_len = tools.opts.width - tools.opts.precision;
		if (tools.conv == 'p')
			pad_len -= 2;
	}
	else
		pad_len = tools.opts.width - len;
	if (tools.flags.zero && tools.opts.precision == -1 && !tools.flags.minus)
		pad_char = '0';
	else
		pad_char = ' ';
	if (tools.sign == -1)
		pad_len--;
	if (tools.sign == -1 && tools.flags.zero && tools.opts.precision == -1 &&
	!tools.flags.minus)
		ft_putchar_fd('-', 1);
	while (pad_len--)
		ft_putchar_fd(pad_char, 1);
}

void		ft_print_width(t_conversion tools, int len)
{
	if (tools.conv == 'c' || tools.conv == 's')
		ft_print_string_width(tools, len);
	if (tools.conv == 'd' || tools.conv == 'i' || tools.conv == 'u' ||
		tools.conv == 'x' || tools.conv == 'X' || tools.conv == 'p')
		ft_print_number_width(tools, len);
}

void		ft_print_precision(t_conversion tools, int len)
{
	if (tools.opts.precision <= len && tools.sign == 1)
		return ;
	if (tools.opts.precision > len && tools.sign == -1)
		ft_putchar_fd('-', 1);
	while (tools.opts.precision-- > len)
		ft_putchar_fd('0', 1);
}
