# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/12 01:42:13 by gekido            #+#    #+#              #
#    Updated: 2025/10/29 20:16:36 by acrusoe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler
CC			= gcc

# flags
CFLAGS		= -g -Wall -Wextra -Werror -I./includes -I./minilibx-linux

# artifacts
NAME		= cub3D

# source files
SRCS	= srcs/main.c \
		srcs/parsing/check_file/parse_file.c \
		srcs/parsing/check_file/ft_doublons.c \
		srcs/parsing/check_textures/parse_textures.c \
		srcs/parsing/check_textures/check_cardinal_lines.c \
		srcs/parsing/check_colors/find_color_line.c \
		srcs/parsing/check_colors/ft_color.c \
		srcs/parsing/check_colors/check_color_lines.c \
		srcs/parsing/check_map/parse_map.c \
		srcs/parsing/check_map/check_walls.c \
		srcs/parsing/check_map/check_walls_utils.c \
		srcs/parsing/check_map/check_items.c \
	srcs/parsing/check_map/check_map_and_path.c \
	srcs/parsing/check_map/flood_fill.c \
	srcs/raycasting/DDA.c \
	srcs/raycasting/DDA_helpers.c \
	srcs/raycasting/DDA_render.c \
	srcs/rendering/ft_render.c \
	srcs/textures/ft_texture.c \
	srcs/game/init/init_game.c \
	srcs/game/init/init_player.c \
	srcs/game/init/init_mlx.c \
	srcs/game/init/init_textures.c \
	srcs/game/player/movements.c \
	srcs/game/player/rotations.c \
	srcs/game/events/hooks.c \
	srcs/utils/get_next_line.c \
	srcs/utils/get_next_line_utils.c \
	srcs/utils/ft_memset.c \
	srcs/cleanup/cleaning.c
OBJS	= ${SRCS:.c=.o}

# mlx library
MLX_NAME	= -lmlx_Linux
MLX_PATH	= ./mlx-linux
MLX_FLAGS   = -lXext -lX11 -lmlx -lm -lz
MLX			= -L${MLX_PATH} ${MLX_NAME} ${MLX_FLAGS}

# cub3d library
CUB3D		= includes/cub3d.h

# rules
all: ${NAME}

${NAME}		: ${OBJS} ${CUB3D}
			${CC} ${CFLAGS} ${OBJS} ${MLX}  -o $(NAME) 

%.o 		: %.c
			${CC} ${CFLAGS} -c $< -o $@ 

clean		:
			rm -rf ${OBJS}

fclean		: clean
			rm -rf ${NAME}

re			: fclean all

val			:${NAME}
			valgrind \
			--leak-check=full --tool=memcheck \
			--show-reachable=yes \
			--track-fds=yes \
			--errors-for-leak-kinds=all \
			--show-leak-kinds=all ./${NAME}

norme		:
			norminette ${SRCS} ${CUB3D}

.PHONY: all clean fclean re