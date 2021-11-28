/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:45:12 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/27 23:33:06 by romoreir         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>

# define MAX_LINE_INPUT 1248
# define MAX_COMMANDS_NUM 136
# define MAX_ARGS_NUM 42
# define DIR_MAX_SIZE 1024

# define CLEAR_CLI "\033[H\033[J"

typedef enum e_bool
{
	FALSE,
	TRUE
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
	char	*name;
	char	*args[MAX_ARGS_NUM];
	e_flags	flag;
}	t_commands;

typedef struct s_minishell
{
	char	input_string[MAX_LINE_INPUT];
	t_commands	commands[MAX_COMMANDS_NUM];
}	t_shell;

//UTILS
void	welcome_message(void);
void	print_dir(void);
int		take_input(t_shell *sh);

#endif
