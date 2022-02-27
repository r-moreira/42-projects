/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:05:58 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/26 20:33:43 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_sigint(int sig)
{
	g_pid_number = 130;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

static void	handle_sigquit(int sig)
{
	g_pid_number = 131;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	printf("Quit (core dumped)\n");
	(void)sig;
}

void	run_signals_interactive(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	run_signals_exec(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
