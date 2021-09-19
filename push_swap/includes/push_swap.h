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

void exit_failure(char *info);
int	 *handle_args(int argc, char **argv);

#endif
