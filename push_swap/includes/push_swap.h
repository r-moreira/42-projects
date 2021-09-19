#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h> //APAGAR!


typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_stack
{
	char				*bin;
	int					index;
	struct s_stack		*next;
}						t_stack;

typedef struct s_all
{
	t_stack	*a;
	t_stack	*b;
	int		limit;
	int		len;
}			t_all;


void exit_failure(char *info);
int	 *handle_args(int argc, char **argv);
int *create_index(int *numbers, int argc);

#endif
