/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:18:33 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/22 11:02:44 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	flag_descrpt(t_shell *sh, int num)
{
	int	i;

	i = 0;
	printf("Flags   = > [%d] >> [%d] < [%d] << [%d] | [%d]\n",
		sh->cmds[num].redout.len,
		sh->cmds[num].redout_apd.len,
		sh->cmds[num].redin.len,
		sh->cmds[num].exec.heredoc,
		sh->cmds[num].exec.pipe);
	i = -1;
	while (++i < sh->cmds[num].redout.len)
		printf("          > arg[%d] = [%s]\n", i, sh->cmds[num].redout.arg[i]);
	i = -1;
	while (++i < sh->cmds[num].redout_apd.len)
		printf("          >> arg[%d] = [%s]\n", i,
			sh->cmds[num].redout_apd.arg[i]);
	i = -1;
	while (++i < sh->cmds[num].redin.len)
		printf("          < arg[%d] = [%s]\n", i, sh->cmds[num].redin.arg[i]);
	if (sh->cmds->exec.heredoc)
		printf("          << doc:\n|%s|\n", sh->heredoc_file_buffer);
}

void	parsed_info_logger(t_shell *sh)
{
	int	i;
	int	j;

	printf("===== Parsed Info Logger =====\n");
	printf("Input   = [%s]\n", sh->input_string);
	i = -1;
	while (++i < sh->count.cmds)
	{
		printf("Command = |%d|\n", i);
		printf("Name    = |%s|\n", sh->cmds[i].name);
		printf("Args    =");
		j = -1;
		while (++j < sh->cmds[i].args_count)
			printf(" |%s|", sh->cmds[i].args[j]);
		printf("\n");
		flag_descrpt(sh, i);
	}
}
