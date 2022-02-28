/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:05:58 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/27 23:22:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_sigint_exec(int sig)
{
	g_pid_number = 130;
	write(1, "\n", 1);
	(void)sig;
}


static void	handle_sigint_interactive(int sig)
{
	g_pid_number = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

static void	handle_sigquit(int sig)
{
	g_pid_number = 131;
	printf("Quit (core dumped)\n");
	(void)sig;
}

void	run_signals_interactive(void)
{
	signal(SIGINT, handle_sigint_interactive);
	signal(SIGQUIT, SIG_IGN);
}

void	run_signals_exec(void)
{
	signal(SIGINT, handle_sigint_exec);
	signal(SIGQUIT, handle_sigquit);
}
