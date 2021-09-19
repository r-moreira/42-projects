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

typedef struct s_stack
{
	unsigned int	index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	unsigned int	len;
}			t_stacks;


void			exit_failure(char *info);
int				*handle_args(int argc, char **argv);
unsigned int	*create_index(int *numbers, int argc);
void setup_stacks(t_stacks *stacks, int argc, unsigned int *index);

#endif
