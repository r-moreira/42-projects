NAME	 			= animal
CC 					= c++
CFLAGS 				= -Wall -Wextra -Werror -std=c++98
OBJS_DIR			= objs
OBJS				= $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))
SRCS_DIR			= srcs
SRCS 				= ${SRCS_DIR}/main.cpp\
					  ${SRCS_DIR}/Animal.cpp\
					  ${SRCS_DIR}/Cat.cpp\
					  ${SRCS_DIR}/Dog.cpp \
					  ${SRCS_DIR}/WrongAnimal.cpp\
					  ${SRCS_DIR}/WrongCat.cpp \
					  ${SRCS_DIR}/Brain.cpp

all:				$(NAME)

$(NAME):			$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:				clean
	$(RM) $(NAME)

re:					fclean all

.PHONY:	all clen fclean re
