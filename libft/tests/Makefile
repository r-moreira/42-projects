NAME		= libftest
LIB			= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -o
CFILES		= $(wildcard *.c)


all:		$(LIB) $(NAME)

run:		$(LIB) $(NAME)
			@echo "\n---- Running the test. ----\n"
			./$(NAME)

$(NAME):
			@echo "\n---- Compiling libftest. ----\n"
			$(CC) $(CFLAGS) $@ $(CFILES) $(LIB)

$(LIB):
			@echo "\n---- Compiling libft. ----\n"
			$(MAKE) -C ../
			@echo "\n---- Copying libft.a to the test folder. ----\n"
			cp ../$@ $@
			@echo "\n---- Cleaning the temp files on the root folder. ----\n"
			$(MAKE) fclean -C ../

clean:
			@echo "\n---- Cleaning the temp files in the tests folder. ----\n"
			rm -f $(NAME) $(LIB)

re:			clean all
			@echo "\n---- Recompiling the test. ----\n"

.PHONY:		clean all run
