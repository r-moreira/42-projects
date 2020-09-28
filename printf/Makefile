NAME				=	libftprintf.a
CC					=	gcc
FLAGS				=	-Wall -Wextra -Werror
INCS				=	-I ./includes -I ../libft
LIBFT_DIR			=	./libft
LIBFT				=	${LIBFT_DIR}/libft.a
OBJS_DIR			=	./objs
OBJS_CORE_FT		=	./objs/ft_printf.o
OBJS_AUX			=	$(patsubst $(SRCS_AUX_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS_AUX))
OBJS_PFTS			=	$(patsubst $(SRCS_PFTS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS_PFTS))
SRCS_AUX_DIR		=	./srcs/aux_functions
SRCS_PFTS_DIR		=	./srcs/print_functions
SRC_CORE_FT			=	srcs
SRCS_AUX			=	${SRCS_AUX_DIR}/ft_set_things.c				\
						${SRCS_AUX_DIR}/ft_define_options.c			\
						${SRCS_AUX_DIR}/ft_handle_options.c			\
						${SRCS_AUX_DIR}/ft_is_input_valid.c			\
						${SRCS_AUX_DIR}/ft_nbr_to_str.c				\
						${SRCS_AUX_DIR}/ft_get_output_len.c
SRCS_PFTS			=	${SRCS_PFTS_DIR}/ft_print_width_precision.c	\
						${SRCS_PFTS_DIR}/ft_ptr_funct_character.c	\
						${SRCS_PFTS_DIR}/ft_ptr_funct_string.c		\
						${SRCS_PFTS_DIR}/ft_ptr_funct_pointer.c		\
						${SRCS_PFTS_DIR}/ft_ptr_funct_integer.c		\
						${SRCS_PFTS_DIR}/ft_ptr_funct_hexadecimal.c \
						${SRCS_PFTS_DIR}/ft_ptr_funct_percent.c
OBJS_CORE_FT_BONUS	=	./objs/ft_printf_bonus.o
OBJS_AUX_BONUS		=	$(patsubst $(SRCS_AUX_DIR_BONUS)/%.c, $(OBJS_DIR)/%.o, $(SRCS_AUX_BONUS))
OBJS_PFTS_BONUS		=	$(patsubst $(SRCS_PFTS_DIR_BONUS)/%.c, $(OBJS_DIR)/%.o, $(SRCS_PFTS_BONUS))
SRCS_AUX_DIR_BONUS	=	./srcs_bonus/aux_functions
SRCS_PFTS_DIR_BONUS	=	./srcs_bonus/print_functions
SRC_CORE_FT_BONUS	=	srcs_bonus
SRCS_AUX_BONUS		=	${SRCS_AUX_DIR_BONUS}/ft_set_things_bonus.c				\
						${SRCS_AUX_DIR_BONUS}/ft_define_options_bonus.c			\
						${SRCS_AUX_DIR_BONUS}/ft_handle_options_bonus.c			\
						${SRCS_AUX_DIR_BONUS}/ft_is_input_valid_bonus.c			\
						${SRCS_AUX_DIR_BONUS}/ft_nbr_to_str_bonus.c				\
						${SRCS_AUX_DIR_BONUS}/ft_get_output_len_bonus.c
SRCS_PFTS_BONUS		=	${SRCS_PFTS_DIR_BONUS}/ft_print_width_precision_bonus.c	\
						${SRCS_PFTS_DIR_BONUS}/ft_ptr_funct_character_bonus.c	\
						${SRCS_PFTS_DIR_BONUS}/ft_ptr_funct_string_bonus.c		\
						${SRCS_PFTS_DIR_BONUS}/ft_ptr_funct_pointer_bonus.c		\
						${SRCS_PFTS_DIR_BONUS}/ft_ptr_funct_integer_bonus.c		\
						${SRCS_PFTS_DIR_BONUS}/ft_ptr_funct_hexadecimal_bonus.c	\
						${SRCS_PFTS_DIR_BONUS}/ft_ptr_funct_percent_bonus.c


all:					$(NAME)

# Compiling libtfprintf.a
$(NAME):				$(LIBFT) $(OBJS_AUX) $(OBJS_PFTS) $(OBJS_CORE_FT)
	cp $(LIBFT) ./
	mv $(subst $(LIBFT_DIR)/,, $(LIBFT)) $(NAME)
	ar rc $@ $(OBJS_AUX) $(OBJS_PFTS) $(OBJS_CORE_FT)
	ranlib $@

# Compiling libftprintf.a with bonus files
bonus:					$(NAME)	$(OBJS_AUX_BONUS) $(OBJS_PFTS_BONUS) $(OBJS_CORE_FT_BONUS)
	ar rc  $(NAME) $(OBJS_AUX_BONUS) $(OBJS_PFTS_BONUS) $(OBJS_CORE_FT_BONUS)
	ranlib $(NAME)

# Compiling libft.a
$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

# Compiling ft_printf objects
$(OBJS_DIR)/%.o:		$(SRCS_AUX_DIR)/%.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(OBJS_DIR)/%.o:		$(SRCS_PFTS_DIR)/%.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(OBJS_DIR)/ft_printf.o:
	$(CC) $(FLAGS) $(INCS) -c $(SRC_CORE_FT)/ft_printf.c -o $@


# Compiling ft_printf bonus objects
$(OBJS_DIR)/%.o:		$(SRCS_AUX_DIR_BONUS)/%.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(OBJS_DIR)/%.o:		$(SRCS_PFTS_DIR_BONUS)/%.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(OBJS_DIR)/ft_printf_bonus.o:
	$(CC) $(FLAGS) $(INCS) -c $(SRC_CORE_FT_BONUS)/ft_printf_bonus.c -o $@

# ft_printf tests
aux_tests:				$(LIBFT)
	$(MAKE) -C unit_tests/aux_tests

print_tests:			all
	$(MAKE) -C unit_tests/print_tests

unit_tests:				aux_tests print_tests

# ft_printf_bonus tests
aux_tests_bonus:		$(LIBFT)
	$(MAKE) -C unit_tests_bonus/aux_tests

print_tests_bonus:		all
	$(MAKE) -C unit_tests_bonus/print_tests

unit_tests_bonus:		aux_tests_bonus print_tests_bonus

clean:
	$(MAKE) clean -C ${LIBFT_DIR}
	$(RM) $(OBJS_AUX) $(OBJS_PFTS) $(OBJS_CORE_FT) $(OBJS_AUX_BONUS) $(OBJS_PFTS_BONUS) $(OBJS_CORE_FT_BONUS)

fclean:					clean
	$(RM) $(LIBFT) $(NAME)

re:						fclean all

re_bonus:				fclean bonus

.PHONY:	all clen fclean re bonus
