/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:30:08 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/15 02:59:21 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_prompt_user(void)
{
	char	*username;
	char	*tmp;
	char	*ret;

	username = getenv("USER");
	if (username != NULL)
	{
		tmp = ft_strjoin(GREEN, username);
		ret = ft_strjoin(tmp, WHITE);
		free(tmp);
		return (ret);
	}
	return (NULL);
}

char	*get_prompt_cwd(void)
{
	char	*cwd;
	char	*tmp;
	char	*tmp2;
	char	*ret;

	cwd = get_cwd_buffer();
	if (cwd == NULL)
		exit_error(ERROR_CWD);
	tmp = ft_strjoin(PURPLE, cwd);
	tmp2 = ft_strjoin(tmp, WHITE);
	ret = ft_strjoin(tmp2, "$ ");
	free(tmp);
	free(tmp2);
	free(cwd);
	return (ret);
}

char	*create_prompt(void)
{
	char	*cwd;
	char	*username;
	char	*ret;

	username = get_prompt_user();
	cwd = get_prompt_cwd();
	ret = NULL;
	if (username != NULL)
	{
		ret = ft_strjoin(username, cwd);
		free(username);
		free(cwd);
		return (ret);
	}
	return (cwd);
}
