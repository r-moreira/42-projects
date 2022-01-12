/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:02:16 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/12 11:11:10 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	debug_helper(t_shell *sh, int i)
{
	printf("\nCommand = |%d|\n", i);
	printf("Path    = |%s|\n", sh->cmds[i].path);
}

static void	cmd_name_on_path(t_shell *sh, int num)
{
	ft_strlcpy(sh->cmds[num].path, sh->cmds[num].name,
		ft_strlen(sh->cmds[num].name) + 1);
}

static void	path_and_cmd_name(t_shell *sh, int num)
{
	char		*cmd_path;
	int			path_len;
	int			total_len;
	int			i;
	struct stat	verify;

	cmd_path = NULL;
	i = -1;
	while (sh->paths[++i] != NULL)
	{
		chdir(sh->paths[i]);
		if (stat(sh->cmds[num].name, &verify) == 0)
		{
			path_len = ft_strlen(sh->paths[i]);
			total_len = path_len + 1 + ft_strlen(sh->cmds[num].name);
			cmd_path = malloc(sizeof(char *) * total_len + 1);
			ft_strlcpy(cmd_path, sh->paths[i], path_len + 1);
			ft_strcat(cmd_path, "/");
			ft_strcat(cmd_path, sh->cmds[num].name);
			break ;
		}
	}
	if (cmd_path != NULL)
		ft_strlcpy(sh->cmds[num].path, cmd_path, ft_strlen(cmd_path) + 1);
	free(cmd_path);
}

t_status	get_cmd_path(t_shell *sh, int num)
{
	char	*cwd;

	cwd = get_cwd_buffer();
	if (sh->cmds[num].name[0] == '/' || sh->cmds[num].name[0] == '.')
	{
		free(cwd);
		cmd_name_on_path(sh, num);
		if (DEBUGGER_EXEC)
			debug_helper(sh, num);
		return (SUCCESS);
	}
	else
	{
		path_and_cmd_name(sh, num);
		chdir(cwd);
		free(cwd);
		if (DEBUGGER_EXEC)
			debug_helper(sh, num);
		return (SUCCESS);
	}
	return (ERROR);
}
