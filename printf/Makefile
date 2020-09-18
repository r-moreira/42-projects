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

all:					$(NAME)

# Compiling libtfprintf.a
$(NAME):				$(LIBFT) $(OBJS_AUX) $(OBJS_PFTS) $(OBJS_CORE_FT)
	cp $(LIBFT) ./
	mv $(subst $(LIBFT_DIR)/,, $(LIBFT)) $(NAME)
	ar rc $@ $(OBJS_AUX) $(OBJS_PFTS) $(OBJS_CORE_FT)
	ranlib $@

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

aux_tests:				$(LIBFT)
	$(MAKE) -C unit_tests/aux_tests

print_tests:			all
	$(MAKE) -C unit_tests/print_tests

unit_tests:				aux_tests print_tests

clean:
	$(MAKE) clean -C ${LIBFT_DIR}
	$(RM) $(OBJS_AUX) $(OBJS_PFTS) $(OBJS_CORE_FT)

fclean:					clean
	$(RM) $(LIBFT) $(NAME)

re:						fclean all

.PHONY:	all clen fclean re bonus
