/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:45:12 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/01 01:49:01 by romoreir         ###   ########.fr       */
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

# define SIGQUIT_NUM 10554
# define MAX_LINE_INPUT 1248
# define MAX_COMMANDS_NUM 136
# define MAX_COMMAND_NAME 50
# define MAX_ARGS_NUM 42
# define MAX_ARGS_NAME 50
# define DIR_MAX_SIZE 1024
# define PARSED_LINE_BUFFER_SIZE 2720
# define HERE_DOCUMENT_BUFFER_SIZE 1732

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
	NONE, //0
	PIPE, //1
	REDIRECT_OUT, //2
	REDIRECT_OUT_APPEND, //3
	REDIRECT_IN, //4
	HERE_DOCUMENT //5
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
	char		heredoc_file_buffer[HERE_DOCUMENT_BUFFER_SIZE];
	int			cmds_count;
}	t_shell;

//UTILS
t_status	print_error(char *err_message);
void		welcome_message(void);
void		print_prompt(void);
t_status	take_input(t_shell *sh);
t_bool		is_closed_quotes(char c, char *input);
t_status	syntax_error(char *msg);
char		**split_null_end(char const *s, char c);
t_bool		is_flag(char c);
//PROCESS HANDLERS
void		eof_exit_shell(t_shell *sh);
void		run_signals();

//ANALYZER
t_status		analyzer(t_shell *sh);

//PARSER
char		*parse_env_variables(char *line_read);
t_status	parser(t_shell *sh);
t_status	parse_flag(t_shell *sh, int cmd_num);
t_status	parse_cmd(t_shell *sh, int cmd_num);

#endif
