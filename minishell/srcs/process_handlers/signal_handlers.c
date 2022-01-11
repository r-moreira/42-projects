/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:05:58 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/07 22:25:47 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_sigint(int sig)
{
	g_pid_number = 130;
	printf("\n");
	print_prompt();
	(void)sig;
}

static void	handle_sigquit(int sig)
{
	g_pid_number = 131;
	printf("Quit (core dumped)\n");
	(void)sig;
}

void	run_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}