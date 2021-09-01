NAME				= cub3D

#External Libs
MLX_DIR 			= mlx_linux
MLX 				= $(MLX_DIR)/libmlx_Linux.a
LIBFT_DIR 			= libft
LIBFT				= ${LIBFT_DIR}/libft.a

#Compiler
CC					= gcc
CFLAGS				= -Wextra -Wall -Werror -g -fsanitize=address
IFLAGS 				= -I includes
LFLAGS				= -lm -lXext -lX11

#Objects
OBJS_DIR 			= objs
MAIN_OBJ			= $(patsubst $(MAIN_DIR)/%.c, $(OBJS_DIR)/%.o, $(MAIN_SRCS))
GNL_OBJS			= $(patsubst $(GNL_DIR)/%.c, $(OBJS_DIR)/%.o, $(GNL_SRCS))
UTILS_OBJS			= $(patsubst $(UTILS_DIR)/%.c, $(OBJS_DIR)/%.o, $(UTILS_SRCS))
OPTION_HANDLERS_OBJS	= $(patsubst $(OPTION_HANDLERS_DIR)/%.c, $(OBJS_DIR)/%.o, $(OPTION_HANDLERS_SRCS))
GAME_ENGINE_OBJS	= $(patsubst $(GAME_ENGINE_DIR)/%.c, $(OBJS_DIR)/%.o, $(GAME_ENGINE_SRCS))

#Sources
MAIN_DIR 			= srcs
MAIN_SRCS			= $(MAIN_DIR)/cub3D.c

GNL_DIR				= $(MAIN_DIR)/get_next_line
GNL_SRCS			= $(GNL_DIR)/get_next_line.c \
					  $(GNL_DIR)/get_next_line_utils.c

UTILS_DIR			= $(MAIN_DIR)/utils
UTILS_SRCS			= $(UTILS_DIR)/free_and_null.c \
					  $(UTILS_DIR)/handle_arg.c \
					  $(UTILS_DIR)/get_cardinal_direction_angle.c \
					  $(UTILS_DIR)/get_fov_angle.c \
					  $(UTILS_DIR)/get_rotation_speed.c \
					  $(UTILS_DIR)/distance_between_points.c \
					  $(UTILS_DIR)/normalize_angle.c \
					  $(UTILS_DIR)/color_picker.c \
					  $(UTILS_DIR)/change_color_intensity.c

OPTION_HANDLERS_DIR	= $(MAIN_DIR)/option_handlers
OPTION_HANDLERS_SRCS = $(OPTION_HANDLERS_DIR)/parse_scene.c \
					  $(OPTION_HANDLERS_DIR)/get_rgb.c \
					  $(OPTION_HANDLERS_DIR)/get_path.c \
					  $(OPTION_HANDLERS_DIR)/create_map_buffer.c \
					  $(OPTION_HANDLERS_DIR)/normalize_map_buffer.c \
					  $(OPTION_HANDLERS_DIR)/validate_map.c \
					  $(OPTION_HANDLERS_DIR)/validate_zeros.c \
					  $(OPTION_HANDLERS_DIR)/build_map_matrix.c \
					  $(OPTION_HANDLERS_DIR)/log_parsed_info.c \

GAME_ENGINE_DIR		= $(MAIN_DIR)/game_engine
GAME_ENGINE_SRCS	= $(GAME_ENGINE_DIR)/setup_game.c \
					  $(GAME_ENGINE_DIR)/exit_game.c \
					  $(GAME_ENGINE_DIR)/start_game_engine.c \
					  $(GAME_ENGINE_DIR)/setup_textures.c \
					  $(GAME_ENGINE_DIR)/setup_sprite.c \
					  $(GAME_ENGINE_DIR)/close_window.c \
					  $(GAME_ENGINE_DIR)/game_loop.c \
					  $(GAME_ENGINE_DIR)/update_player.c \
					  $(GAME_ENGINE_DIR)/handle_keyboard_input.c \
					  $(GAME_ENGINE_DIR)/draw_pixel.c \
					  $(GAME_ENGINE_DIR)/draw_line.c \
					  $(GAME_ENGINE_DIR)/render_ceil_and_floor.c \
					  $(GAME_ENGINE_DIR)/render_minimap.c \
					  $(GAME_ENGINE_DIR)/render_rays.c \
					  $(GAME_ENGINE_DIR)/has_wall_at.c \
					  $(GAME_ENGINE_DIR)/handle_wall_texture_color.c \
					  $(GAME_ENGINE_DIR)/get_dist_to_proj_plane.c \
					  $(GAME_ENGINE_DIR)/get_texture_color.c \
					  $(GAME_ENGINE_DIR)/render_wall_projection.c \
					  $(GAME_ENGINE_DIR)/render_sprite_projection.c \
					  $(GAME_ENGINE_DIR)/raycasting.c \
					  $(GAME_ENGINE_DIR)/handle_wall_interceptions.c

all:				$(NAME)

$(NAME): 			libs $(MAIN_OBJ) $(GNL_OBJS) $(UTILS_OBJS) $(OPTION_HANDLERS_OBJS) $(GAME_ENGINE_OBJS)
	$(CC) $(MAIN_OBJ) $(GNL_OBJS) $(UTILS_OBJS) $(OPTION_HANDLERS_OBJS) $(GAME_ENGINE_OBJS) $(MLX) $(LIBFT) $(IFLAGS) $(CFLAGS) $(LFLAGS) -o ${NAME}

#Compiling external libs
libs:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)

#Compiling main
$(OBJS_DIR)/%.o:	$(MAIN_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

#Compiling gnl
$(OBJS_DIR)/%.o: 	$(GNL_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

#Compiling auxiliary functions
$(OBJS_DIR)/%.o:	$(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

#Compiling option handlers functions
$(OBJS_DIR)/%.o:	$(OPTION_HANDLERS_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

#Compiling game engine functions
$(OBJS_DIR)/%.o:	$(GAME_ENGINE_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(MAIN_OBJ) $(GNL_OBJS) $(UTILS_OBJS) $(OPTION_HANDLERS_OBJS) $(GAME_ENGINE_OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MLX)

re: fclean all

.PHONY:	all clean fclean re
