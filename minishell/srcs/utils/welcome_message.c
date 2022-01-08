/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:11:36 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/07 23:22:06 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	welcome_message(void)
{
	char	*username;

	username = getenv("USER");
	if (username != NULL)
	{
		printf(CLEAR_CLI);
		printf("\n%s===============================================\n", RED);
		printf("\n---- Welcome: %s@%s%s!!\n", WHITE, username, RED);
		printf("\n---- This is %sromoreir%s shell\n", WHITE, RED);
		printf("\n===============================================\n\n%s", WHITE);
	}
	else
	{
		printf(CLEAR_CLI);
		printf("\n%s===============================================\n", RED);
		printf("\n---- Welcome!!\n");
		printf("\n---- This is %sromoreir%s shell\n", WHITE, RED);
		printf("\n===============================================\n\n%s", WHITE);
	}
}
