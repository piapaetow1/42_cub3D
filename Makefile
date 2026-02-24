# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 15:14:25 by hreusing          #+#    #+#              #
#    Updated: 2025/08/18 14:49:23 by pbohme           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra -I cub/includes/libft -I cub/includes/minilibx-linux_copy

SRCS = cub/srcs/main.c \
		cub/srcs/parsing/map/get_map.c \
		cub/srcs/parsing/map/config.c \
		cub/srcs/parsing/map/config_textures.c \
		cub/srcs/parsing/map/config_colors.c \
		cub/srcs/parsing/map/rgb.c \
		cub/srcs/parsing/checks/check_map_content.c \
		cub/srcs/parsing/checks/check_map_file.c \
		cub/srcs/parsing/checks/check_map_walls.c \
		cub/srcs/parsing/checks/check_map_flood_fill.c \
		cub/srcs/parsing/checks/check_map_holes.c \
		cub/srcs/parsing/checks/check_map.c \
		cub/srcs/parsing/graphics/load_textures.c \
		cub/srcs/game/game_helpers.c \
		cub/srcs/game/init_game.c \
		cub/srcs/game/init_player.c \
		cub/srcs/game/player_direction.c \
		cub/srcs/game/move_directions.c \
		cub/srcs/game/move_player.c \
		cub/srcs/rendering/render_scene.c \
		cub/srcs/rendering/camera_position.c \
		cub/srcs/rendering/dda.c \
		cub/srcs/rendering/draw_image_to_walls.c \
		cub/srcs/free.c \
		cub/srcs/helpers.c

BONUS_SRCS = bonus/srcs_bonus/main.c \
		bonus/srcs_bonus/parsing/map/get_map.c \
		bonus/srcs_bonus/parsing/map/config.c \
		bonus/srcs_bonus/parsing/map/config_textures.c \
		bonus/srcs_bonus/parsing/map/config_colors.c \
		bonus/srcs_bonus/parsing/map/rgb.c \
		bonus/srcs_bonus/parsing/checks/check_map_content.c \
		bonus/srcs_bonus/parsing/checks/check_map_file.c \
		bonus/srcs_bonus/parsing/checks/check_map_walls.c \
		bonus/srcs_bonus/parsing/checks/check_map_flood_fill.c \
		bonus/srcs_bonus/parsing/checks/check_map_holes.c \
		bonus/srcs_bonus/parsing/checks/check_map.c \
		bonus/srcs_bonus/parsing/graphics/load_textures.c \
		bonus/srcs_bonus/parsing/graphics/load_sprites.c \
		bonus/srcs_bonus/game/game_helpers.c \
		bonus/srcs_bonus/game/init_game.c \
		bonus/srcs_bonus/game/init_player.c \
		bonus/srcs_bonus/game/player_direction.c \
		bonus/srcs_bonus/game/move_directions.c \
		bonus/srcs_bonus/game/move_player.c \
		bonus/srcs_bonus/game/door_opener.c \
		bonus/srcs_bonus/rendering/render_scene.c \
		bonus/srcs_bonus/rendering/camera_position.c \
		bonus/srcs_bonus/rendering/dda.c \
		bonus/srcs_bonus/rendering/draw_image_to_walls.c \
		bonus/srcs_bonus/rendering/minimap.c \
		bonus/srcs_bonus/rendering/player_fov.c \
		bonus/srcs_bonus/free.c \
		bonus/srcs_bonus/helpers.c \
		bonus/srcs_bonus/game/mouse_move.c \

		
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_DIR = cub/includes/libft
MLX_DIR = cub/includes/minilibx-linux_copy

LIBFT = $(LIBFT_DIR)/libft.a
MLX = -L./$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lm -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS) | $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX) -lm -o $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
