/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:45:12 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/22 17:06:57 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

/* ** Set debugger ON/OFF ** */
# define DEBUGGER_EXEC 1

/* ** Helpers ** */
# define FORKED_CHILD 0
# define SIGNALED 130
# define HEREDOC_FILE "/tmp/heredoc"

/* ** Buffers ** */
# define MAX_LINE_INPUT 1248
# define MAX_COMMANDS_NUM 136
# define MAX_COMMAND_NAME 50
# define MAX_ARGS_NUM 42
# define MAX_ARGS_NAME 50
# define MAX_ENVS 256
# define MAX_PATHS 124
# define MAX_PATH_LEN 512
# define MAX_CMD_REDIRECTIONS 20
# define DIR_MAX_SIZE 1024
# define PARSED_LINE_BUFFER_SIZE 2720
# define HERE_DOCUMENT_BUFFER_SIZE 1732
# define HERE_DOCUMENT_INPUT_END_SIZE 120
# define BUILTIN_OUTPUT_BUFFER 4234

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
# define ERROR_UNSET_START "minishell: unset: `"
# define ERROR_UNSET_END "': not a valid identifier\n"
# define ERROR_EXEC "minishell: Failed to execute the command: "
# define ERROR_FORK "minishell: Error on forking process\n"
# define ERROR_PIPE_FD "minishell: Error on creating pipe\n"
# define ERROR_HEREDOC "minishell: Heredoc does not contain an input ending\n"
# define ERROR_DUP "minishell: DUP error"
# define ERROR_OPEN_FILE "minishell: Error opening file"

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

typedef enum e_flag
{
	NONE,
	PIPE,
	REDIRECT_OUT,
	REDIRECT_OUT_APPEND,
	REDIRECT_IN,
	HERE_DOCUMENT
}	t_flag;

typedef enum e_fds
{
	ANY,
	ONE,
	TWO
}	t_fds_num;

typedef enum e_pipe_end
{
	READ_END,
	WRITE_END
}	t_pipe_end;

/* ** Structs ** */
typedef struct s_redir
{
	char	arg[MAX_CMD_REDIRECTIONS][MAX_ARGS_NAME];
	int		len;
}	t_redir;

typedef struct s_exec
{
	t_bool	builtin;
	t_bool	pipe;
	t_bool	redin;
	t_bool	heredoc;
	t_bool	redout;
	t_bool	redout_apd;
	t_flag	last_redout;
	t_flag	last_redin;
}	t_exec;

typedef struct s_commands
{
	char	path[MAX_PATH_LEN];
	char	name[MAX_COMMAND_NAME];
	char	*args[MAX_ARGS_NUM];
	int		args_count;
	t_redir	redin;
	t_redir	redout;
	t_redir	redout_apd;
	t_exec	exec;
}	t_commands;

typedef struct s_counters
{
	int			cmds;
	int			envs;
	int			paths;
}	t_counters;

typedef struct s_fds
{
	int			one[2];
	int			two[2];
	t_bool		rd1;
	t_bool		rd2;
	t_bool		wr1;
	t_bool		rd1wr2;
	t_bool		rd2wr1;
	t_fds_num	open;
	int			redin;
	int			heredoc;
	int			redout;
	int			redout_apd;
}	t_fds;

typedef struct s_dup
{
	t_fds_num	fd;
	t_pipe_end	end;
	int			fileno;
	t_flag		flag;
}	t_dup;

typedef struct s_minishell
{
	char		input_string[MAX_LINE_INPUT];
	t_commands	cmds[MAX_COMMANDS_NUM];
	char		*cmd_tokens[MAX_COMMANDS_NUM];
	char		heredoc_file_buffer[HERE_DOCUMENT_BUFFER_SIZE];
	char		heredoc_input_end[HERE_DOCUMENT_INPUT_END_SIZE];
	char		*envs[MAX_ENVS];
	char		*paths[MAX_PATHS];
	t_fds		fd;
	t_counters	count;
}	t_shell;

/* ** Functions ** */

//UTILS
void		init_shell(t_shell *sh, char **envp);
void		setup_info(t_shell *sh);
void		exit_error(char *err_message);
t_status	syntax_error(char *msg);
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
size_t		strlen_no_spaces(char *s);
void		parsed_info_logger(t_shell *sh);
void		str_close_quotes(char *dest, char *src, int *i, int *j);
char		*str_remove_quotes(char *str);
t_bool		is_quotes(char c);
void		executor_debugger_helper(t_shell *sh);
void		path_debugger_helper(t_shell *sh, int i);
char		*strjoin_newline(char const *s1, char const *s2);
t_bool		is_here_document(char *parsed_line);
char		*get_bool_str(t_bool boolean);
void		setup_flag_info(t_shell *sh, int num);
void		setup_fd_info(t_shell *sh);

//PROCESS HANDLERS
void		eof_exit_shell(t_shell *sh);
void		run_signals_interactive(void);
void		run_signals_exec(void);
void		dup_n_close_pipe(t_shell *sh, t_dup dupinfo);
void		dup_n_close_redir_fd(int redir_fd, t_flag flag);
void		close_fd(t_shell *sh, t_fds_num fd);
void		wait_aux(int pid);
void		handle_dup(t_shell *sh, int redir_fd);
void		handle_pipe(t_shell *sh, int num);
pid_t		handle_fork(void);

//ANALYZER
t_status	analyzer(t_shell *sh);

//PARSER
char		*parse_env_variables(char *line_read);
t_status	parser(t_shell *sh);
t_status	parse_flags(t_shell *sh, int num);
t_status	parse_cmd(t_shell *sh, int num);
char		*parse_env(char *env);
char		*parse_heredoc_input_end(char *parsed_line);

//EXECUTOR
t_status	get_cmd_path(t_shell *sh, int num);
void		executor(t_shell *sh);
void		exec_cmd(t_shell *sh, int num);
void		handle_io(t_shell *sh, int num);
t_status	handle_here_document_input(t_shell *sh);

//BUILT-INS
t_bool		is_builtin(t_shell *sh, int num);
t_bool		has_non_fork_builtins(t_shell *sh, int num);
t_status	call_builtin(t_shell *sh, int num);
void		exec_builtin(t_shell *sh, int num);
t_status	ft_echo(t_shell *sh, int num);
t_status	ft_cd(t_shell *sh, int num);
t_status	ft_pwd(t_shell *sh, int num);
t_status	ft_export(t_shell *sh, int num);
t_status	ft_unset(t_shell *sh, int num);
t_status	ft_env(t_shell *sh);
void		ft_exit(t_shell *sh);

#endif
