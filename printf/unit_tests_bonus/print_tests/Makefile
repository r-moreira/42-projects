NAME				=	print_tests_bonus
CC					=	gcc
FLAGS				=	-w	#Remove this flag "-w" if you want to see gcc warnings
SRCS_DIR			= 	../../srcs_bonus/print_functions/
INCS_DIR			=	-I ../../includes -I ../../libft
LIBFT				=	../../libft/libft.a
LIBFTPRINTF			=	../../libftprintf.a

$(info )
$(info =========== TEST DESCRIPTION ===========)
$(info )
$(info This test will print 2 strings: )
$(info )
$(info * First string  => Original printf output)
$(info * Second string => 42 printf output)
$(info )
$(info The outputs must be equal!)
$(info )
$(info Obs: These tests may have compiler warnings!!)
$(info )
$(info =========== RUNNING BONUS PRINT TESTS ==========)
$(info )

all:	$(NAME) clean
	$(info )

print_tests_bonus:	ft_print_width_precision_bonus no_conversion_test_bonus ft_ptr_funct_character_bonus ft_ptr_funct_string_bonus ft_ptr_funct_integer_bonus ft_ptr_funct_hexadecimal_bonus ft_ptr_funct_pointer_bonus ft_ptr_funct_percent_bonus ft_print_width_precision_bonus ft_print_multiple_conversions_bonus

ft_print_width_precision_bonus: #ft_print_width and ft_print_precision tests
	$(info ) $(info =====> WIDTH AND PRECISION TESTS || File = TEST_ft_print_width_precision_bonus.c <=====) $(info )
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_print_width_precision_bonus.c $(SRCS_DIR)ft_print_width_precision_bonus.c $(LIBFT) -o bin_TEST_ft_print_width_precision_bonus
	@./bin_TEST_ft_print_width_precision_bonus

no_conversion_test_bonus:
	$(info ) $(info =====> NO CONVERSION TESTS || File = TEST_no_conversion_bonus.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_no_conversion_bonus.c $(LIBFTPRINTF) -o bin_TEST_no_conversion_bonus
	@./bin_TEST_no_conversion_bonus

ft_ptr_funct_character_bonus:
	$(info ) $(info =====> CHARACTER CONVERSION TESTS (%c) || File = TEST_ft_ptr_funct_character_bonus.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_character_bonus.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_character_bonus
	@./bin_TEST_ft_ptr_funct_character_bonus

ft_ptr_funct_string_bonus:
	$(info ) $(info =====> STRING CONVERSION TESTS (%s) || File = TEST_ft_ptr_funct_string_bonus.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_string_bonus.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_string_bonus
	@./bin_TEST_ft_ptr_funct_string_bonus

ft_ptr_funct_pointer_bonus:
	$(info ) $(info =====> VOID POINTER CONVERSION TESTS (%d - %i - %u) || File = TEST_ft_ptr_funct_pointer_bonus.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_pointer_bonus.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_pointer_bonus
	@./bin_TEST_ft_ptr_funct_pointer_bonus

ft_ptr_funct_integer_bonus:
	$(info ) $(info =====> INTEGER CONVERSION TESTS (%d - %i - %u) || File = TEST_ft_ptr_funct_integer_bonus.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_integer_bonus.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_integer_bonus
	@./bin_TEST_ft_ptr_funct_integer_bonus

ft_ptr_funct_hexadecimal_bonus:
	$(info ) $(info =====> HEXADECIMAL CONVERSION TESTS (%x - %X) || File = TEST_ft_ptr_funct_hexadecimal_bonus.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_hexadecimal_bonus.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_hexadecimal_bonus
	@./bin_TEST_ft_ptr_funct_hexadecimal_bonus

ft_ptr_funct_percent_bonus:
	$(info ) $(info =====> PERCENT CONVERSION TESTS (%%) || File = TEST_ft_ptr_funct_percent_bonus.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_percent_bonus.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_percent_bonus
	@./bin_TEST_ft_ptr_funct_percent_bonus

ft_print_multiple_conversions_bonus:
	$(info ) $(info =====> PRINT MULTIPLE CONVERSIONS || File = TEST_print_multiple_conversions_bonus.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_print_multiple_conversions_bonus.c $(LIBFTPRINTF) -o bin_TEST_print_multiple_conversions_bonus
	@./bin_TEST_print_multiple_conversions_bonus

clean:
	@rm bin_*
