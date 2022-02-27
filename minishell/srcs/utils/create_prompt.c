/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:30:08 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/26 21:08:01 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_prompt_user(void)
{
	char	*username;
	char	*tmp;
	char	*ret;
	char	*p;

	ret = ft_strdup("");
	username = getenv("USER");
	if (username != NULL)
	{
		tmp = ft_strjoin(GREEN, username);
		p = tmp;
		tmp = ft_strjoin(tmp, "@");
		free(p);
		ft_strlcpy(ret, tmp, ft_strlen(tmp) + 1);
		free(tmp);
	}
	return (ret);
}

char	*get_prompt_sysname(void)
{
	char	*sysname;
	char	*tmp;
	char	*ret;
	char	*p;

	ret = ft_strdup("");
	sysname = getenv("NAME");
	if (sysname != NULL)
	{
		tmp = ft_strjoin("", sysname);
		p = tmp;
		tmp = ft_strjoin(tmp, WHITE);
		free(p);
		p = tmp;
		tmp = ft_strjoin(tmp, ":");
		free(p);
		ft_strlcpy(ret, tmp, ft_strlen(tmp) + 1);
		free(tmp);
	}
	return (ret);
}

char	*get_prompt_cwd(void)
{
	char	*cwd;
	char	*tmp;
	char	*ret;
	char	*p;

	cwd = get_cwd_buffer();
	ret = ft_strdup("");
	tmp = ft_strjoin("", PURPLE);
	p = tmp;
	tmp = ft_strjoin(tmp, cwd);
	free(p);
	p = tmp;
	tmp = ft_strjoin(tmp, WHITE);
	free(p);
	p = tmp;
	tmp = ft_strjoin(tmp, "$ ");
	free(p);
	ft_strlcpy(ret, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	free(cwd);
	return (ret);
}

char	*create_prompt(void)
{
	char	*cwd;
	char	*username;
	char	*sysname;
	char	*prompt;
	char	*p;

	username = get_prompt_user();
	sysname = get_prompt_sysname();
	cwd = get_prompt_cwd();
	prompt = ft_strjoin("", username);
	p = prompt;
	prompt = ft_strjoin(prompt, sysname);
	free(p);
	p = prompt;
	prompt = ft_strjoin(prompt, cwd);
	free(p);
	free(username);
	free(sysname);
	free(cwd);
	return (prompt);
}
