/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:45:12 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/22 21:13:22 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<unistd.h>
# include<sys/types.h>
# include<sys/wait.h>
# include<readline/readline.h>
# include<readline/history.h>

# define MAX_LINE_INPUT 1000
# define MAX_COMANDS_NUM 100
# define MAX_ARGS_NUM 50
# define CLEAR_CLI "\033[H\033[J"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_minishell
{
	char	input_string[MAX_LINE_INPUT];
	char	commands[MAX_COMANDS_NUM][MAX_COMANDS_NUM];
}	t_shell;


//UTILS
void	welcome_message(void);
void	print_dir(void);
int		take_input(t_shell *sh);

#endif
