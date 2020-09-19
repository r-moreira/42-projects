NAME				=	aux_tests
CC					=	gcc
FLAGS				=	-Wall -Wextra -Werror
SRCS_DIR			= 	../../srcs/aux_functions/
INCS_DIR			=	-I ../../includes -I ../../libft
LIBFT				=	../../libft/libft.a

$(info ) $(info ====== RUNNING AUX FUNCTIONS TESTS ======) $(info )

all:	$(NAME) clean
	$(info )

aux_tests:	ft_set_things ft_is_input_valid ft_conversion_handler ft_get_output_len ft_nbr_to_str

ft_set_things:	#ft_set_ptr_functs and ft_set_parse_tools tests
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_set_things.c $(SRCS_DIR)/ft_set_things.c $(LIBFT) -o bin_TEST_ft_set_things
	@./bin_TEST_ft_set_things

ft_is_input_valid:
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_is_input_valid.c $(SRCS_DIR)/ft_is_input_valid.c $(LIBFT) -o bin_TEST_ft_is_input_valid
	@./bin_TEST_ft_is_input_valid

ft_conversion_handler:	ft_define_options
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_conversion_handler.c $(SRCS_DIR)/ft_define_options.c $(SRCS_DIR)ft_set_things.c $(LIBFT) -o bin_TEST_ft_conversion_handler
	@./bin_TEST_ft_conversion_handler

ft_define_options:	#ft_define_flags, ft_define_width and ft_define_precision tests
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_define_options.c $(SRCS_DIR)/ft_define_options.c $(LIBFT) -o bin_TEST_ft_define_options
	@./bin_TEST_ft_define_options

ft_get_output_len:
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_get_output_len.c $(SRCS_DIR)/ft_get_output_len.c $(LIBFT) -o bin_TEST_ft_get_output_len
	@./bin_TEST_ft_get_output_len

ft_nbr_to_str: #to do
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_nbr_to_str.c $(SRCS_DIR)/ft_nbr_to_str.c $(LIBFT) -o bin_TEST_ft_nbr_to_str
	@./bin_TEST_ft_nbr_to_str

clean:
	@rm bin_*
