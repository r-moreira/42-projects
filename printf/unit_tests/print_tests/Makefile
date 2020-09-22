NAME				=	print_tests
CC					=	gcc
FLAGS				=	-w	#Remove this flag "-w" if you want to see gcc warnings
SRCS_DIR			= 	../../srcs/print_functions/
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
$(info =========== RUNNING PRINT TESTS ==========)
$(info )

all:	$(NAME) clean
	$(info )

print_tests:	ft_print_width_precision no_conversion_test ft_ptr_funct_character ft_ptr_funct_string ft_ptr_funct_integer ft_ptr_funct_hexadecimal ft_ptr_funct_pointer ft_ptr_funct_percent ft_print_width_precision ft_print_multiple_conversions

ft_print_width_precision: #ft_print_width and ft_print_precision tests
	$(info ) $(info =====> WIDTH AND PRECISION TESTS || File = TEST_ft_print_width_precision.c <=====) $(info )
	@$(CC) $(FLAGS) $(INCS_DIR) TEST_ft_print_width_precision.c $(SRCS_DIR)ft_print_width_precision.c $(LIBFT) -o bin_TEST_ft_print_width_precision
	@./bin_TEST_ft_print_width_precision

no_conversion_test:
	$(info ) $(info =====> NO CONVERSION TESTS || File = TEST_no_conversion.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_no_conversion.c $(LIBFTPRINTF) -o bin_TEST_no_conversion
	@./bin_TEST_no_conversion

ft_ptr_funct_character:
	$(info ) $(info =====> CHARACTER CONVERSION TESTS (%c) || File = TEST_ft_ptr_funct_character.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_character.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_character
	@./bin_TEST_ft_ptr_funct_character

ft_ptr_funct_string:
	$(info ) $(info =====> STRING CONVERSION TESTS (%s) || File = TEST_ft_ptr_funct_string.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_string.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_string
	@./bin_TEST_ft_ptr_funct_string

ft_ptr_funct_pointer:
	$(info ) $(info =====> VOID POINTER CONVERSION TESTS (%d - %i - %u) || File = TEST_ft_ptr_funct_pointer.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_pointer.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_pointer
	@./bin_TEST_ft_ptr_funct_pointer

ft_ptr_funct_integer:
	$(info ) $(info =====> INTEGER CONVERSION TESTS (%d - %i - %u) || File = TEST_ft_ptr_funct_integer.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_integer.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_integer
	@./bin_TEST_ft_ptr_funct_integer

ft_ptr_funct_hexadecimal:
	$(info ) $(info =====> HEXADECIMAL CONVERSION TESTS (%x - %X) || File = TEST_ft_ptr_funct_hexadecimal.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_hexadecimal.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_hexadecimal
	@./bin_TEST_ft_ptr_funct_hexadecimal

ft_ptr_funct_percent:
	$(info ) $(info =====> PERCENT CONVERSION TESTS (%%) || File = TEST_ft_ptr_funct_percent.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_ptr_funct_percent.c $(LIBFTPRINTF) -o bin_TEST_ft_ptr_funct_percent
	@./bin_TEST_ft_ptr_funct_percent

ft_print_multiple_conversions: #to do
	$(info ) $(info =====> PRINT MULTIPLE CONVERSIONS || File = TEST_print_multiple_conversions.c <=====) $(info )
	@$(CC) $(FLAGS) TEST_ft_print_multiple_conversions.c $(LIBFTPRINTF) -o bin_TEST_print_multiple_conversions
	@./bin_TEST_print_multiple_conversions

clean:
	@rm bin_*
