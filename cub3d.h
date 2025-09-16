/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:14:52 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:14:52 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21000
# endif

// # ifndef TILE_SIZE
// #  define TILE_SIZE 64
// # endif

// # define KEY_PRESS 2
// # define KEY_EXIT 17
// # define KEY_ESC 65307
// # define KEY_W 119
// # define KEY_A 97
// # define KEY_S 115
// # define KEY_D 100
// # define KEY_UP 65362
// # define KEY_DOWN 65364
// # define KEY_RIGHT 65363
// # define KEY_LEFT 65361

// # define STONE "./images/stone.xpm"
// # define FRODO_F "./images/frodo_face.xpm"
// # define FRODO_L "./images/frodo_left.xpm"
// # define FRODO_R "./images/frodo_right.xpm"
// # define FRODO_B "./images/frodo_back.xpm"
// # define DOOR_C "./images/door_close.xpm"
// # define DOOR_O "./images/door_open.xpm"
// # define COLL "./images/ring.xpm"
// # define BACKG "./images/grass.xpm"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		path_error;
	int		count;
	int		count1;
	int		count2;
	int		player;
	int		nbr;
	int		map;
	int		length;
	int		height;
	char	**pars;
	char	**pars_temp;
	void	*mlx;
	void	*mlx_win;
}	t_data;

char	*get_next_line(int fd);
int		parsing(t_data *game);
size_t	ft_strlen(const char *str);
int		ft_strchr(char *left_char);
char	*ft_strdup(char *s1);
char	*ft_strcat(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
int		check_walls_4(t_data *game);
int		check_walls_3(t_data *game);
int		check_walls_2(t_data *game);
int		check_walls_1(t_data *game);
int		len(t_data *game);
int		check_items(t_data *game);
int		check_numbers_items(t_data *game);
void	check_numbers_items2(t_data *game, int x, int y);
int		check_doublons(t_data *game);
int	check_flood_fill(t_data *game, int x, int y);
void	flood_fill(t_data *game, int x, int y);
char	**cpy_pars(t_data *game);
void	ft_free(t_data *game);
void	ft_strcpy(char *str, char *str1);
void	move_left(t_data *game);
void	move_right(t_data *game);
void	move_up(t_data *game);
void	move_down(t_data *game);
void	render(t_data *game);
void	choose_image(t_data *game, int x, int y);
void	choose_image_2(t_data *game, int x, int y);
void	choose_image_3(t_data *game, int x, int y);
int		key_hook(int keycode, t_data *game);
void	ft_door_open(t_data *game);
void	ft_mlx_destroy_image(t_data *game);
void	ft_free_pars(t_data *game);
void	initiate(t_data *game);
void	check_position(t_data *game);
int		check_map(t_data *game);
int		check_path(t_data *game, int x, int y);
int		number_of_lines(char *file);
void	map_init(t_data *game, char *file);
int		ft_count(t_data *game);
int		ft_close(t_data *game);
int		ft_close1(t_data *game);
void	check_arg(int ac, char *file);
char	*ft_strstr(char *str, char *to_find);
int		is_whitespace(char c);
#endif