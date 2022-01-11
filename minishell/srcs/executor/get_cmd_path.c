/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:02:16 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/10 21:31:04 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		return (SUCCESS);
	}
	else
	{
		path_and_cmd_name(sh, num);
		chdir(cwd);
		free(cwd);
		return (SUCCESS);
	}
	return (ERROR);
}
