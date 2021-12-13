NAME				= minishell

#Compiler
CC					= clang
CFLAGS				= #-Wextra -Wall -Werror -g #-fsanitize=address
LIBFT_DIR 			= libft
LIBFT 				= -L ./$(LIBFT_DIR) -lft
LIBREADLINE			= -lreadline

#External Libs
#Objects
OBJS_DIR 			= objs
MAIN_OBJ			= $(patsubst $(MAIN_DIR)/%.c, $(OBJS_DIR)/%.o, $(MAIN_SRCS))
UTILS_OBJS			= $(patsubst $(UTILS_DIR)/%.c, $(OBJS_DIR)/%.o, $(UTILS_SRCS))
ANALYZER_OBJS		= $(patsubst $(UTILS_DIR)/%.c, $(OBJS_DIR)/%.o, $(ANALYZER_SRCS))

#Sources
MAIN_DIR 			= srcs
MAIN_SRCS			= $(MAIN_DIR)/minishell.c

#Utils
UTILS_DIR			= $(MAIN_DIR)/utils
UTILS_SRCS			= $(UTILS_DIR)/print_dir.c \
					  $(UTILS_DIR)/print_error.c \
					  $(UTILS_DIR)/take_input.c \
					  $(UTILS_DIR)/welcome_message.c

#Analyzer
ANALYZER_DIR		= $(MAIN_DIR)/analyzer
ANALYZER_SRCS		= $(ANALYZER_DIR)/analyzer.c

all:				$(NAME)

$(NAME): 			libft $(MAIN_OBJ) $(UTILS_OBJS) $(ANALYZER_OBJS)
	$(CC) $(MAIN_OBJ) $(UTILS_OBJS) $(ANALYZER_OBJS) $(CFLAGS) $(LIBFT) $(LIBREADLINE) -o ${NAME}

#Compiling external libs
libft:
	$(MAKE) -C $(LIBFT_DIR)

#Compiling main
$(OBJS_DIR)/%.o:	$(MAIN_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#Compiling auxiliary functions
$(OBJS_DIR)/%.o:	$(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#Compiling analyzer functions
$(OBJS_DIR)/%.o:	$(ANALYZER_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(MAIN_OBJ) $(UTILS_OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY:	all clean fclean re
