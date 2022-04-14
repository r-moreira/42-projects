/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:18:15 by romoreir          #+#    #+#             */
/*   Updated: 2022/04/14 19:50:41 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("Hello World! at: %ld\n", get_current_time());
	printf("is_digit = %d | atoi = %d\n", ft_isdigit('4'), ft_atoi("4321"));
	return (EXIT_SUCCESS);
}
