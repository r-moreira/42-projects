NAME				= minishell

#Compiler
CC					= clang
CFLAGS				= -Wextra -Wall -Werror -g -fsanitize=address
LIBFT_DIR 			= libft
LIBFT 				= -L ./$(LIBFT_DIR) -lft
LIBREADLINE			= -lreadline

#Objects
OBJS_DIR 			= objs
MAIN_OBJ			= $(patsubst $(MAIN_DIR)/%.c, $(OBJS_DIR)/%.o, $(MAIN_SRCS))
UTILS_OBJS			= $(patsubst $(UTILS_DIR)/%.c, $(OBJS_DIR)/%.o, $(UTILS_SRCS))
PARSER_OBJS			= $(patsubst $(PARSER_DIR)/%.c, $(OBJS_DIR)/%.o, $(PARSER_SRCS))
ANALYZER_OBJS		= $(patsubst $(ANALYZER_DIR)/%.c, $(OBJS_DIR)/%.o, $(ANALYZER_SRCS))
EXECUTOR_OBJS		= $(patsubst $(EXECUTOR_DIR)/%.c, $(OBJS_DIR)/%.o, $(EXECUTOR_SRCS))
PHANDLERS_OBJS		= $(patsubst $(PHANDLERS_DIR)/%.c, $(OBJS_DIR)/%.o, $(PHANDLERS_SRCS))
BUILTINS_OBJS		= $(patsubst $(BUILTINS_DIR)/%.c, $(OBJS_DIR)/%.o, $(BUILTINS_SRCS))

#Sources
MAIN_DIR 			= srcs
MAIN_SRCS			= $(MAIN_DIR)/minishell.c

#Utils
UTILS_DIR			= $(MAIN_DIR)/utils
UTILS_SRCS			= $(UTILS_DIR)/print_prompt.c \
					  $(UTILS_DIR)/init_shell.c \
					  $(UTILS_DIR)/take_input.c \
					  $(UTILS_DIR)/welcome_message.c \
					  $(UTILS_DIR)/syntax_error.c \
					  $(UTILS_DIR)/exit_error.c \
					  $(UTILS_DIR)/is_closed_quotes.c \
					  $(UTILS_DIR)/split_null_end.c \
					  $(UTILS_DIR)/is_flag.c \
					  $(UTILS_DIR)/get_cwd_buffer.c \
					  $(UTILS_DIR)/is_env_valid.c \
					  $(UTILS_DIR)/get_env_key.c \
					  $(UTILS_DIR)/strlen_no_spaces.c \
					  $(UTILS_DIR)/parsed_info_logger.c \
					  $(UTILS_DIR)/str_close_quotes.c \
					  $(UTILS_DIR)/str_remove_quotes.c \
					  $(UTILS_DIR)/is_quotes.c \
  					  $(UTILS_DIR)/debugger_helpers.c \
					  $(UTILS_DIR)/strjoin_newline.c \
					  $(UTILS_DIR)/is_here_document.c

#Parser
PARSER_DIR			= $(MAIN_DIR)/parser
PARSER_SRCS			= $(PARSER_DIR)/env_variables_parser.c \
					  $(PARSER_DIR)/executor_parser.c \
					  $(PARSER_DIR)/flags_parser.c \
					  $(PARSER_DIR)/cmd_parser.c \
					  $(PARSER_DIR)/env_parser.c \
					  $(PARSER_DIR)/heredoc_parser.c

#Analyzer
ANALYZER_DIR		= $(MAIN_DIR)/analyzer
ANALYZER_SRCS		= $(ANALYZER_DIR)/analyzer.c

#Executor
EXECUTOR_DIR		= $(MAIN_DIR)/executor
EXECUTOR_SRCS		= $(EXECUTOR_DIR)/executor.c \
					  $(EXECUTOR_DIR)/get_cmd_path.c \
					  $(EXECUTOR_DIR)/clear_execution.c \
					  $(EXECUTOR_DIR)/exec_cmd.c \
					  $(EXECUTOR_DIR)/heredoc_handlers.c

#Process Handlers
PHANDLERS_DIR		= $(MAIN_DIR)/process_handlers
PHANDLERS_SRCS		= $(PHANDLERS_DIR)/eof_handler.c \
					  $(PHANDLERS_DIR)/dup_n_close.c \
					  $(PHANDLERS_DIR)/close_fd.c \
					  $(PHANDLERS_DIR)/signal_handlers.c \
					  $(PHANDLERS_DIR)/wait_aux.c \
					  $(PHANDLERS_DIR)/pipe_handler.c \
					  $(PHANDLERS_DIR)/fork_handler.c \
					  $(PHANDLERS_DIR)/dup_handler.c

#Built-ins functions
BUILTINS_DIR		= $(MAIN_DIR)/built-ins
BUILTINS_SRCS		= $(BUILTINS_DIR)/echo.c \
					  $(BUILTINS_DIR)/cd.c \
					  $(BUILTINS_DIR)/pwd.c \
					  $(BUILTINS_DIR)/export.c \
					  $(BUILTINS_DIR)/unset.c \
					  $(BUILTINS_DIR)/env.c \
					  $(BUILTINS_DIR)/exit.c \
					  $(BUILTINS_DIR)/handle_builtin.c

all:				$(NAME)

$(NAME): 			libft $(MAIN_OBJ) $(UTILS_OBJS) $(PHANDLERS_OBJS) $(PARSER_OBJS) $(ANALYZER_OBJS) $(EXECUTOR_OBJS) $(BUILTINS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) && $(CC) $(MAIN_OBJ) $(UTILS_OBJS) $(PHANDLERS_OBJS) $(PARSER_OBJS) $(ANALYZER_OBJS) $(EXECUTOR_OBJS) $(BUILTINS_OBJS) $(CFLAGS) $(LIBFT) $(LIBREADLINE) -o ${NAME}

#Compiling main
$(OBJS_DIR)/%.o:	$(MAIN_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#Compiling auxiliary functions
$(OBJS_DIR)/%.o:	$(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


#Compiling process handlers functions
$(OBJS_DIR)/%.o:	$(PHANDLERS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#Compiling parser functions
$(OBJS_DIR)/%.o:	$(PARSER_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#Compiling analyzer functions
$(OBJS_DIR)/%.o:	$(ANALYZER_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#Compiling executor functions
$(OBJS_DIR)/%.o:	$(EXECUTOR_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#Compiling built-ins functions
$(OBJS_DIR)/%.o:	$(BUILTINS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(MAIN_OBJ) $(UTILS_OBJS) $(PHANDLERS_OBJS) $(PARSER_OBJS) $(ANALYZER_OBJS) $(EXECUTOR_OBJS) $(BUILTINS_OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT_DIR)/libft.a

re: fclean all

.PHONY:	all clean fclean re
