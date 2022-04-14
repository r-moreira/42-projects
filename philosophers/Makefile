# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 19:41:29 by rarodrig          #+#    #+#              #
#    Updated: 2022/04/14 19:30:42 by romoreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g #-pthread #-fsanitize=address

OBJS_DIR	= objs
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

SRCS_DIR	= srcs
SRCS		= $(SRCS_DIR)/philosophers.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
