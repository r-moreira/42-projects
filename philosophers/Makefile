# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 19:41:29 by rarodrig          #+#    #+#              #
#    Updated: 2022/04/14 19:42:04 by romoreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= philo

CC					= clang
CFLAGS				= -Wall -Wextra -Werror -g -pthread -fsanitize=address

OBJS_DIR			= objs
MAIN_OBJ			= $(patsubst $(MAIN_DIR)%.c, $(OBJS_DIR)%.o, $(MAIN_SRC))
UTILS_OBJS			= $(patsubst $(UTILS_DIR)/%.c, $(OBJS_DIR)/%.o, $(UTILS_SRCS))

MAIN_DIR			= srcs
MAIN_SRC			= $(MAIN_DIR)/philosophers.c

UTILS_DIR			= $(MAIN_DIR)/utils
UTILS_SRCS			= $(UTILS_DIR)/utils.c

all: $(NAME)

$(NAME):			$(MAIN_OBJ) $(UTILS_OBJS)
	$(CC) $(MAIN_OBJ) $(UTILS_OBJS) $(CFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o:	$(MAIN_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o:	$(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
