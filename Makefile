# compiler
CC			= gcc

# flags
CFLAGS		= -g -Wall -Wextra -Werror

# artifacts
NAME		= cub3D

# source files
SRCS	= get_next_line.c \
		get_next_line_utils.c \
		check_items.c \
		initialisation.c \
		check_map_and_path.c \
		check_walls.c \
		parsing_utils.c\
		cleaning.c\
		flood_fill.c\
		pars_info.c\
		animations.c\
		animations2.c\
		DDA.c\
		ft_render.c\
		ft_texture.c\
		init_mlx_canvas.c\
		init_player.c\
		main.c 

# object files
OBJS	= ${SRCS:.c=.o}

# mlx library
MLX_NAME	= -lmlx_Linux
MLX_PATH	= ./mlx-linux
MLX_FLAGS   = -lXext -lX11 -lmlx -lm
MLX			= -L${MLX_PATH} ${MLX_NAME} ${MLX_FLAGS}

# cub3d library
CUB3D		= cub3d.h

# rules
all: ${NAME}

${NAME}		: ${OBJS} cub3d.h
			${CC} ${CFLAGS} ${OBJS} ${CUB3D} ${MLX}  -o $(NAME) 

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