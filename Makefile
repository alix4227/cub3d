# compiler
CC			= gcc

# flags
CFLAGS		= -g -Wall -Wextra -Werror

# artifacts
NAME		= so_long

# source files
SRCS	= get_next_line.c \
		get_next_line_utils.c \
		parsing_utils.c \
		check_items.c \
		flood_fill.c \
		initialisation.c \
		animations.c \
		animations2.c \
		check_map_and_path.c \
		check_rectangle.c \
		check_walls.c \
		images_creation.c \
		main.c \
		cleaning.c

# object files
OBJS	= ${SRCS:.c=.o}

# mlx library
MLX_NAME	= -lmlx_Linux
MLX_PATH	= ./mlx-linux
MLX_FLAGS   = -lXext -lX11 -lmlx -lm
MLX			= -L${MLX_PATH} ${MLX_NAME} ${MLX_FLAGS}

# so long library
SOLONG		= so_long.h

# rules
all: ${NAME}

${NAME}		: ${OBJS} so_long.h
			${CC} ${CFLAGS} ${OBJS} ${SOLONG} ${MLX}  -o $(NAME) 

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
			norminette ${SRCS} ${SOLONG}

.PHONY: all clean fclean re