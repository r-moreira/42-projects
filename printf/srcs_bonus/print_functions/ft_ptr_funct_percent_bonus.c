/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:11 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 14:12:11 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int				ft_ptr_funct_percent(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	ft_putchar_fd('%', 1);
	return (1);
}
