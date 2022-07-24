NAME	 			= ft_containers
CC 					= c++
CFLAGS 				= -Wall -Wextra -Werror -std=c++98
OBJS_DIR			= objs
OBJS				= $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))
SRCS_DIR			= srcs/tests
SRCS 				= ${SRCS_DIR}/main.cpp

all:				$(NAME)

$(NAME):			$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp
	$(CC) $(CFLAGS) -I/srcs/containers -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:				clean
	$(RM) $(NAME)

re:					fclean all

.PHONY:	all clen fclean re
