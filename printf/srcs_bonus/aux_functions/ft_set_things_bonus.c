/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:10:36 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 17:56:04 by rodrigo          ###   ########.fr       */
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
	tools->flags.minus = false;
	tools->flags.zero = false;
	tools->opts.width = 0;
	tools->opts.precision = -1;
}
