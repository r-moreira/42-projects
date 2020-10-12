/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_percent_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:11 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/11 22:21:07 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

int				ft_ptr_funct_percent(va_list *args, t_conversion tools)
{
	(void)args;
	(void)tools;
	ft_putchar_fd('%', 1);
	return (1);
}
