NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(CFILES:.c=.o)
CFILES		=	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

BON_OBJS	=	$(BON_CFILES:.c=.o)
BON_CFILES	=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

all:			$(NAME)

bonus:			$(NAME) $(OBJS)
				$(CC) $(CFLAGS) -c $(BON_CFILES)
				ar rc $< $(BON_OBJS)
				ranlib $<

$(NAME):
				$(CC) $(CFLAGS) -c $(CFILES)
				ar rc $@ $(OBJS)
				ranlib $@

test:
				make run -C tests/

clean:
				rm -f $(OBJS) $(BON_OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
