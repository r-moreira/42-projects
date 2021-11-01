NAME				= minishell

#Compiler
CC					= clang
CFLAGS				= -Wextra -Wall -Werror -g -fsanitize=address
IFLAGS 				= -I includes

#External Libs
LIBFT_DIR 			= libft
LIBFT				= ${LIBFT_DIR}/libft.a

#Objects
OBJS_DIR 			= objs
OBJS				= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

#Sources
SRCS_DIR 			= srcs
SRCS				= $(SRCS_DIR)/minishell.c

all:				$(NAME)

$(NAME): 			libs $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(-IFLAGS)  -o ${NAME}

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
