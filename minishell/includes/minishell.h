/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:45:12 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/09 03:01:43 by romoreir         ###   ########.fr       */
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

/* ** Set debugger ON/OFF ** */
# define DEBUGGER 1

/* ** Buffers ** */
# define MAX_LINE_INPUT 1248
# define MAX_COMMANDS_NUM 136
# define MAX_COMMAND_NAME 50
# define MAX_ARGS_NUM 42
# define MAX_ARGS_NAME 50
# define MAX_ENVS 256
# define MAX_PATHS 124
# define DIR_MAX_SIZE 1024
# define PARSED_LINE_BUFFER_SIZE 2720
# define HERE_DOCUMENT_BUFFER_SIZE 1732

/* ** Prompt ** */
# define CLEAR_CLI "\033[H\033[J"
# define RED "\033[0;31m"
# define WHITE "\033[0m\002"
# define PURPLE "\033[0;35m"
# define GREEN "\033[1;32m\002"

/* ** Errors messages ** */
# define ERROR_PIPE "minishell: syntax error near unexpected token `|'\n"
# define ERROR_DIR "No such file or directory\n"
# define ERROR_HOME "minishell: cd: HOME not set\n"
# define ERROR_CMD "command not found\n"
# define ERROR_EXPT_START "minishell: export: `"
# define ERROR_EXPT_END "': not a valid identifier\n"


/* ** Global Variables ** */
int	g_pid_number;

/* ** Enums ** */
typedef enum e_status
{
	ERROR,
	SUCCESS,
	NOT_TOKEN,
	NOT_BUILT_IN
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
	REDIRECT_OUT,
	REDIRECT_OUT_APPEND,
	REDIRECT_IN,
	HERE_DOCUMENT
}	e_flags;

/* ** Structs ** */
typedef struct s_commands
{
	char	name[MAX_COMMAND_NAME];
	char	args[MAX_ARGS_NUM][MAX_ARGS_NAME];
	int		args_count;
	e_flags	flag;
}	t_commands;

typedef struct s_counters
{
	int			cmds;
	int			envs;
	int			paths;
}	t_counters;

typedef struct s_fd
{
	int		in;
	int		out;
}	t_fd;

typedef struct s_minishell
{
	char		input_string[MAX_LINE_INPUT];
	t_commands	cmds[MAX_COMMANDS_NUM];
	char		*cmd_tokens[MAX_COMMANDS_NUM];
	char		heredoc_file_buffer[HERE_DOCUMENT_BUFFER_SIZE];
	char		*envs[MAX_ENVS];
	char		*paths[MAX_PATHS];
	t_counters	count;
}	t_shell;

/* ** Functions ** */

//UTILS
void		init_shell(t_shell *sh, char **envp);
t_status	print_error(char *err_message);
void		welcome_message(void);
void		print_prompt(void);
t_status	take_input(t_shell *sh);
t_bool		is_closed_quotes(char c, char *input);
t_status	syntax_error(char *msg);
char		**split_null_end(char *s, char c);
t_bool		is_flag(char c);
char		*get_cwd_buffer(void);
t_bool		is_env_valid(char *env);
char		*get_env_key(char *env);

//PROCESS HANDLERS
void		eof_exit_shell(t_shell *sh);
void		run_signals();

//ANALYZER
t_status	analyzer(t_shell *sh);

//PARSER
char		*parse_env_variables(char *line_read);
t_status	parser(t_shell *sh);
t_status	parse_flag(t_shell *sh, int cmd_num);
t_status	parse_cmd(t_shell *sh, int cmd_num);
char		*parse_env(char *env);

//EXECUTOR
void		executor(t_shell *sh);

//BUILT-INS
t_status	ft_echo(t_shell *sh, int cmd_num);
t_status	ft_cd(t_shell *sh, int cmd_num);
t_status	ft_pwd(t_shell *sh, int cmd_num);
t_status	ft_export(t_shell *sh, int cmd_num);
t_status	ft_unset(t_shell *sh);
t_status	ft_env(t_shell *sh);
void		ft_exit(t_shell *sh);

#endif
