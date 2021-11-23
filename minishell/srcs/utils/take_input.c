/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:24 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/22 21:10:56 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	take_input(t_shell *sh)
{
	char	*buf;

	buf = readline(" $> ");
	if (strlen(buf) != 0)
	{
		add_history(buf);
		ft_strlcpy(sh->input_string, buf, ft_strlen(buf) + 1);
		return (FALSE);
	}
	else
		return (TRUE);
}
