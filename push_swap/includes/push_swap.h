#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h> //Temporary


typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_node
{
	unsigned int	index;
	struct s_node	*next;
}					t_node;

typedef struct s_stacks
{
	t_node			*top_a;
	t_node			*top_b;
	t_node			*a;
	t_node			*b;
	unsigned int	len;
}			t_stacks;


void			exit_failure(char *info);
int				exit_free(int *numbers, unsigned int *index, t_stacks *stacks);
int				*handle_args(int argc, char **argv);
unsigned int	*create_index(int *numbers, int argc);
void 			setup_stacks(t_stacks *stacks, int argc, unsigned int *index);

#endif
