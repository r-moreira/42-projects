NAME				=	aux_tests_bonus
CC					=	gcc
FLAGS				=	-Wall -Wextra -Werror
SRCS_DIR			= 	../../srcs_bonus/aux_functions/
INCS_DIR			=	-I ../../includes -I ../../libft
LIBFT				=	../../libft/libft.a

$(info ) $(info ====== RUNNING AUX BONUS FUNCTIONS TESTS ======) $(info )

all:	$(NAME) clean
	$(info )

aux_tests_bonus:	ft_set_things_bonus ft_is_input_valid_bonus ft_conversion_handler_bonus ft_nbr_to_str_bonus

ft_set_things_bonus:	#ft_set_ptr_functs and ft_set_parse_tools tests
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_set_things_bonus.c $(SRCS_DIR)/ft_set_things_bonus.c $(LIBFT) -o bin_TEST_ft_set_things_bonus
	@./bin_TEST_ft_set_things_bonus

ft_is_input_valid_bonus:
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_is_input_valid_bonus.c $(SRCS_DIR)/ft_is_input_valid_bonus.c $(SRCS_DIR)ft_handle_options_bonus.c $(LIBFT) -o bin_TEST_ft_is_input_valid_bonus
	@./bin_TEST_ft_is_input_valid_bonus

ft_conversion_handler_bonus:	ft_define_options_bonus
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_conversion_handler_bonus.c $(SRCS_DIR)/ft_define_options_bonus.c $(SRCS_DIR)ft_set_things_bonus.c $(SRCS_DIR)ft_handle_options_bonus.c $(LIBFT) -o bin_TEST_ft_conversion_handler_bonus
	@./bin_TEST_ft_conversion_handler_bonus

ft_define_options_bonus:	#ft_define_flags, ft_define_width and ft_define_precision tests
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_define_options_bonus.c $(SRCS_DIR)/ft_define_options_bonus.c $(SRCS_DIR)ft_handle_options_bonus.c  $(LIBFT) -o bin_TEST_ft_define_options_bonus
	@./bin_TEST_ft_define_options_bonus

ft_nbr_to_str_bonus:
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_nbr_to_str_bonus.c $(SRCS_DIR)/ft_nbr_to_str_bonus.c $(LIBFT) -o bin_TEST_ft_nbr_to_str_bonus
	@./bin_TEST_ft_nbr_to_str_bonus

clean:
	@rm bin_*
