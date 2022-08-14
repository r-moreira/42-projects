NAME	 			= ft_containers
CC 					= c++
CFLAGS 				= -Wall -Wextra -Werror -std=c++98
OBJS_DIR			= objs
OBJS				= $(patsubst $(TESTS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(TESTS))
TESTS_DIR			= tests
TESTS 				= ${TESTS_DIR}/main.cpp

all:				$(NAME)

$(NAME):			$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	$(TESTS_DIR)/%.cpp
	$(CC) $(CFLAGS) -I/srcs/containers -I/srcs/iterator -I/srcs/utils  -I/srcs/tree -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:				clean
	$(RM) $(NAME)

re:					fclean all

.PHONY:	all clen fclean re
