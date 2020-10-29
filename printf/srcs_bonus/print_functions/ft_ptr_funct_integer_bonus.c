/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_integer_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:02 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/29 05:28:15 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static  int	ft_get_ptr_integer_return(int len, t_conversion tools)
{
	if (tools.opts.width > tools.opts.precision && tools.opts.width > len)
		return (tools.opts.width);
	else if (tools.opts.precision > len)
	{
		if (tools.opts.precision >= len && tools.sign == -1)
			return (tools.opts.precision + 1);
		else
			return (tools.opts.precision);
	}
	else if (tools.sign == -1)
		return (len + 1);
	return (len);
}

static int	ft_print_integer_arg(char *arg_str, int len, t_conversion tools)
{
	if (len == 0)
		return (0);
	if (tools.sign == -1)
		arg_str++;
	if ((tools.sign == -1 && !tools.flags.zero && !tools.opts.width &&
	tools.opts.precision <= len) ||
	(tools.sign == -1 && tools.flags.zero && !tools.opts.width &&
	tools.opts.precision <= len) ||
	(tools.sign == -1 && tools.opts.width > 0 && tools.opts.width <= len &&
	tools.opts.precision <= len) ||
	(tools.sign == -1 && tools.opts.width > len &&
	tools.opts.precision == -1 && !tools.flags.zero) ||
	(tools.sign == -1 && tools.flags.minus && tools.flags.zero &&
	tools.opts.precision == -1))
		ft_putchar_fd('-', 1);
	ft_putstr_fd(arg_str, 1);
	return (len);
}

int			ft_ptr_funct_integer(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	char		*arg_str;
	int			len;

	if (tools.conv == 'd' || tools.conv == 'i')
		type.u_int = va_arg(*args, int);
	else
		type.u_uint = va_arg(*args, unsigned int);
	arg_str = ft_nbr_to_str(DECIMAL, type, &tools);
	len = ft_strlen(arg_str);
	if (len == 1 && arg_str[0] == '0' && tools.opts.precision == 0)
		len = 0;
	if (tools.sign == -1)
		len--;
	if (tools.opts.width > (len) && !tools.flags.minus)
		ft_print_width(tools, len);
	ft_print_precision(tools, len);
	len = ft_print_integer_arg(arg_str, len, tools);
	free(arg_str);
	if (tools.opts.width > (len) && tools.flags.minus)
		ft_print_width(tools, len);
	return (ft_get_ptr_integer_return(len, tools));
}
