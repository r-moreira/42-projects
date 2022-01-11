/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:18:33 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/10 22:29:25 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


static char	*flag_descrpt(t_shell *sh, int num)
{
	char	*flag_descrpt;

	if (sh->cmds[num].flag == 1)
		flag_descrpt = "PIPE";
	else if (sh->cmds[num].flag == 2)
		flag_descrpt = "REDIRECT OUT";
	else if (sh->cmds[num].flag == 3)
		flag_descrpt = "REDIRECT OUT APPEND";
	else if (sh->cmds[num].flag == 4)
		flag_descrpt = "REDIRECT IN";
	else if (sh->cmds[num].flag == 5)
		flag_descrpt = "HERE DOCUMENT";
	else
	flag_descrpt = "NONE";

	return (flag_descrpt);
}

void	parsed_info_logger(t_shell *sh)
{
	int	i;
	int	j;

	printf("\n===== Parsed Info Logger =====\n");
	printf("Input   = [%s]\n", sh->input_string);
	i = -1;
	while (++i < sh->count.cmds)
	{
		printf("\nCommand = |%d|\n", i);
		printf("Name    = |%s|\n", sh->cmds[i].name);
		printf("Path    = |%s|\n", sh->cmds[i].path);
		printf("Args    =");
		j = -1;
		while (++j < sh->cmds[i].args_count)
			printf(" |%s|", sh->cmds[i].args[j]);
		printf("\n");
		printf("Flag    = |%s|\n", flag_descrpt(sh, i));
	}
	printf("==============================\n\n");
}
