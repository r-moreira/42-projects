NAME	 			= webserv
CC 					= c++
CFLAGS 				=  -std=c++98 #-Wall -Wextra -Werror
OBJS_DIR			= objs
OBJS				= $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))
SRCS_DIR			= srcs
CONF_DIR			= ${SRCS_DIR}/config
NETWORK_DIR			= ${SRCS_DIR}/network
PARSER_DIR			= ${SRCS_DIR}/parser
IO_DIR				= ${SRCS_DIR}/io

SRCS				= ${SRCS_DIR}/webserv.cpp\
					  ${CONF_DIR}/Configuration.cpp\
					  ${NETWORK_DIR}/Network.cpp\
					  ${NETWORK_DIR}/Socket.cpp\
					  ${NETWORK_DIR}/Server.cpp\
					  ${NETWORK_DIR}/Location.cpp\
					  ${IO_DIR}/Multiplexer.cpp

all:				$(NAME)

$(NAME):			$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp
	$(CC) $(CFLAGS) -I/includes/ -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:				clean
	$(RM) $(NAME)

re:					fclean all

.PHONY:	all clen fclean re
