# You can edit these variables to make a custom test:
NAME			= test #This is the name of binary.
BVALUE			= 1024 #Buffer value.
TXT				= test.txt #Name of the file to test the get_next_line function.
BONTXT			= test.txt test2.txt test3.txt #Name of the files to test the get_next_line functon with bonus.
# Edit the following variables only if you need to.
CC				= gcc
FLAGS			= -Wall -Wextra -Werror -I ../ -o
BUFFER			= -D BUFFER_SIZE=$(BVALUE)
PROGFILES		= main.c ../get_next_line.c ../get_next_line_utils.c
BONFILES		= main_bonus.c ../get_next_line_bonus.c ../get_next_line_utils.c
COMPMACRO		= $(CC) $(FLAGS) $(NAME) $(BUFFER)

all:			file breakline bonus_file

stdin:
				@echo "---- Compiling GNL and running in stdin ----\n"
				$(COMPMACRO) $(PROGFILES) && ./$(NAME)

file:
				@echo "---- Compiling GNL and runing with a file descriptor ----"
				$(COMPMACRO) $(PROGFILES) && ./$(NAME) $(TXT)

bonus_stdin:
				@echo "---- Compiling GNL Bonus and running in stdin ----\n"
				$(COMPMACRO) $(BONFILES) && ./$(NAME)

bonus_file:
				@echo "---- Compiling GNL  Bonus and runing with more than one file descriptor ----"
				$(COMPMACRO) $(BONFILES) && ./$(NAME) $(BONTXT)

breakline:
				@echo "\n"

clean:
				@rm -f $(NAME)

re:				clean all

.PHONY:			clean all re file stdin breakline
