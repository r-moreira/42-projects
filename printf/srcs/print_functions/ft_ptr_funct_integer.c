/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:02 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/29 02:11:08 by romoreir         ###   ########.fr       */
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
	return (len);
}

static void	ft_print_integer_arg(char *arg_str, int len, t_conversion tools)
{
	if (len == 0)
		return ;
	else if ((tools.sign == -1 && tools.opts.precision > len) ||
	(tools.flags.zero && !tools.flags.minus && tools.sign == -1))
		ft_putstr_fd((arg_str + 1), 1);
	else
		ft_putstr_fd(arg_str, 1);
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
	if (tools.opts.precision >= len && tools.sign == -1)
		len--;
	if (len == 1 && arg_str[0] == '0' && tools.opts.precision == 0)
		len = 0;
	if (tools.opts.width > (len) && !tools.flags.minus)
		ft_print_width(tools, len);
	ft_print_precision(tools, len);
	ft_print_integer_arg(arg_str, len, tools);
	free(arg_str);
	if (tools.opts.width > (len) && tools.flags.minus)
		ft_print_width(tools, len);
	return (ft_get_ptr_integer_return(len, tools));
}
