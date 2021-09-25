#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_node
{
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
	int		len;
}			t_stacks;

void	exit_failure(char *info);
int		exit_free(int *numbers, int *index, t_stacks *stacks);
int		*handle_args(int argc, char **argv);
int		*create_index(int *numbers, int argc);
void	setup_stacks(t_stacks *stacks, int argc, int *index);
void	ra(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	sort_big_stack(t_stacks *stacks);
void	sort_small_stack(t_stacks *stacks);

#endif
