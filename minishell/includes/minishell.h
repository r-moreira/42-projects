/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:45:12 by romoreir          #+#    #+#             */
/*   Updated: 2021/11/22 20:49:28 by romoreir         ###   ########.fr       */
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


#define MAX_LINE_INPUT 1000
#define MAX_COMANDS_NUM 100
#define CLEAR_CLI "\033[H\033[J"

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

#endif
