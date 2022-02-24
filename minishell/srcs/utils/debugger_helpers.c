/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:45:04 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/23 22:25:39 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_bool_str(t_bool boolean)
{
	if (boolean == TRUE)
		return ("TRUE");
	else if (boolean == FALSE)
		return ("FALSE");
	return ("NOT BOOLEAN");
}

char	*get_flags_str(t_flag flag)
{
	if (flag == NONE)
		return ("NONE");
	else if (flag == PIPE)
		return ("PIPE");
	else if (flag == REDIRECT_OUT)
		return ("REDIRECT_OUT");
	else if (flag == REDIRECT_OUT_APPEND)
		return ("REDIRECT_OUT_APPEND");
	else if (flag == REDIRECT_IN)
		return ("REDIRECT_IN");
	else if (flag == HERE_DOCUMENT)
		return ("HERE_DOCUMENT");
	return ("NOT FLAG");
}

void	executor_debugger_helper(t_shell *sh)
{
	parsed_info_logger(sh);
	printf("======= Start Execution =======\n");
}

void	path_debugger_helper(t_shell *sh, int i)
{
	printf("Command    = |%d|\n", i);
	printf("Path       = |%s|\n", sh->cmds[i].path);
}
