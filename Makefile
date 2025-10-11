# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gekido <gekido@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/12 01:42:13 by gekido            #+#    #+#              #
#    Updated: 2025/10/12 01:43:27 by gekido           ###   ########.fr        #
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
		srcs/parsing/parse_file.c \
		srcs/parsing/parse_textures.c \
		srcs/parsing/find_color_line.c \
		srcs/parsing/ft_color.c \
		srcs/parsing/parse_map.c \
		srcs/parsing/check_walls.c \
		srcs/parsing/check_walls_utils.c \
		srcs/parsing/check_items.c \
		srcs/parsing/check_map_and_path.c \
		srcs/parsing/flood_fill.c \
		srcs/parsing/check_cardinal_lines.c \
		srcs/parsing/check_color_lines.c \
		srcs/parsing/ft_doublons.c \
		srcs/raycasting/DDA.c \
		srcs/rendering/ft_render.c \
		srcs/textures/ft_texture.c \
		srcs/game/init_game.c \
		srcs/game/init_player.c \
		srcs/game/init_mlx.c \
		srcs/game/movements.c \
		srcs/game/rotations.c \
		srcs/game/hooks.c \
		srcs/utils/get_next_line.c \
		srcs/utils/get_next_line_utils.c \
		srcs/cleanup/cleaning.c 

# object files
OBJS	= ${SRCS:.c=.o}

# mlx library
MLX_NAME	= -lmlx_Linux
MLX_PATH	= ./minilibx-linux
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