/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:45:12 by romoreir          #+#    #+#             */
/*   Updated: 2021/12/30 14:27:36 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define MAX_LINE_INPUT 1248
# define MAX_COMMANDS_NUM 136
# define MAX_COMMAND_NAME 50
# define MAX_ARGS_NUM 42
# define MAX_ARGS_NAME 50
# define DIR_MAX_SIZE 1024
# define PARSED_LINE_BUFFER_SIZE 3672
# define HERE_DOCUMENT_BUFFER_SIZE 1248

# define CLEAR_CLI "\033[H\033[J"

int	g_pid_number;

typedef enum e_status
{
	ERROR,
	SUCCESS
}	t_status;

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum e_flags
{
	NONE,
	PIPE,
	HERE_DOCUMENT,
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_OUT_APPEND
}	e_flags;

typedef struct s_commands
{
	char	name[MAX_COMMAND_NAME];
	char	args[MAX_ARGS_NUM][MAX_ARGS_NAME];
	int		args_count;
	e_flags	flag;
}	t_commands;

typedef struct s_minishell
{
	char		input_string[MAX_LINE_INPUT];
	t_commands	cmds[MAX_COMMANDS_NUM];
	char		*cmd_tokens[MAX_COMMANDS_NUM];
	char		*heredoc_file_buffer;
	int			cmds_count;
}	t_shell;

//UTILS
t_status	print_error(char *err_message);
void		welcome_message(void);
void		print_prompt(void);
t_status	take_input(t_shell *sh);

//PROCESS HANDLERS
void		eof_exit_shell(t_shell *sh);
void		run_signals();

//ANALYZER
t_status		analyzer(t_shell *sh);

//PARSER
char		*parse_env_variables(char *line_read);
t_status	parser(t_shell *sh);

#endif
