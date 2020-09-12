/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testheader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:34:53 by romoreir          #+#    #+#             */
/*   Updated: 2020/03/11 19:23:32 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		main_menu(void);
int		libc_menu(void);
int		additional_functs_menu(void);
int		bonus_functs_menu(void);
int		call_libc_functs(int index);
int		call_additional_functs(int index);
int		call_bonus_functs(int index);
void	libc_functs_info(int index);
void	additional_functs_info(int index);
void	bonus_functs_info(int index);
int		ft_memset_test(void);
int		ft_bzero_test(void);
int		ft_memcpy_test(void);
