/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/22 20:55:37 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_shell(void)
{
	char	*username;

	username = getenv("USER");
	printf(CLEAR_CLI);
	printf("\n===============================================\n");
	printf("\n---- Welcome: @%s!\n", username);
	printf("\n---- This is romoreir shell\n");
	printf("\n===============================================\n");
}

int	take_input(char *str)
{
	char	*buf;

	buf = readline(" $> ");
	if (strlen(buf) != 0)
	{
		add_history(buf);
		ft_strlcpy(str, buf, ft_strlen(buf) + 1);
		return (FALSE);
	}
	else
		return (TRUE);
}

void	print_dir(void)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("\n%s", cwd);
}

int	main(void)
{
	char	input_string[MAX_LINE_INPUT];

	init_shell();
	while (TRUE)
	{
		print_dir();
		take_input(input_string);
		printf("%s\n", input_string);

	}
	return (EXIT_SUCCESS);
}
