/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_set_ptr_functs(t_ptr_functs **ptr)
{
	if (!(*ptr = (t_ptr_functs *)malloc(sizeof(t_ptr_functs))))
		return (0);
	ft_strlcpy((*ptr)->conversions, "cspdiuxX%", 10);
	(*ptr)->functs[0] = ft_ptr_funct_character;
	(*ptr)->functs[1] = ft_ptr_funct_string;
	(*ptr)->functs[2] = ft_ptr_funct_pointer;
	(*ptr)->functs[3] = ft_ptr_funct_integer;
	(*ptr)->functs[4] = ft_ptr_funct_integer;
	(*ptr)->functs[5] = ft_ptr_funct_integer;
	(*ptr)->functs[6] = ft_ptr_funct_hexadecimal;
	(*ptr)->functs[7] = ft_ptr_funct_hexadecimal;
	(*ptr)->functs[8] = ft_ptr_funct_percent;
	return (1);
}

void	ft_set_parse_tools(t_conversion *tools)
{
	tools->flags.minus = 0;
	tools->flags.zero = 0;
	tools->opts.width = 0;
	tools->opts.precision = -1;
	tools->sign = 1;
}
