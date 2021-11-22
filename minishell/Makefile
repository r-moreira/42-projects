NAME				= minishell

#Compiler
CC					= clang
CFLAGS				= -Wextra -Wall -Werror -g -fsanitize=address
LIBFT_DIR 			= libft
LFLAGS 				= -L ./$(LIBFT_DIR) -lft -lreadline

#External Libs
#Objects
OBJS_DIR 			= objs
OBJS				= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

#Sources
SRCS_DIR 			= srcs
SRCS				= $(SRCS_DIR)/minishell.c

all:				$(NAME)

$(NAME): 			libs $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS)  -o ${NAME}

#Compiling external libs
libs:
	$(MAKE) -C $(LIBFT_DIR)

#Compiling main
$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY:	all clean fclean re
