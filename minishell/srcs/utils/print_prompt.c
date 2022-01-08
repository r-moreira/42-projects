/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:30:08 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/07 23:22:34 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_prompt(void)
{
	char	*buffer;
	char	*username;
	char	*name;

	username = getenv("USER");
	name = getenv("NAME");
	buffer = get_cwd_buffer();
	if (username != NULL)
		printf("%s%s@", GREEN, username);
	if (name != NULL)
		printf("%s%s%s:", GREEN, name, WHITE);
	printf("%s%s", PURPLE, buffer);
	printf("%s$ ", WHITE);
	free(buffer);
}
