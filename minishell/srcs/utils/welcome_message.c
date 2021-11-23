/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:11:36 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/22 21:11:46 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	welcome_message(void)
{
	char	*username;

	username = getenv("USER");
	printf(CLEAR_CLI);
	printf("\n===============================================\n");
	printf("\n---- Welcome: @%s!\n", username);
	printf("\n---- This is romoreir shell\n");
	printf("\n===============================================\n");
}
