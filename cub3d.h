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
#  define BUFFER_SIZE 100000
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 640

# define KEY_PRESS 2
# define KEY_EXIT 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

# define ROTATION_SPEED 0.05
# define MOVE_SPEED 0.05

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct s_texture
{
	void			*img;
	char			*addr;
	char			*path;
	char			wall_hit_text;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				offset_x;
	int				offset_y;
	int				icon_w;
	int				icon_h;
}					t_texture;

typedef struct	s_ray
{
	double		posX;
	double		posY;
	double		dirX; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		dirY; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planeX; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		planeY; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		rayDirX;
	double		rayDirY;
	double		cameraX;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpWallDist;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			x;
}	t_ray;

typedef struct s_data
{
	int			x;
	int			y;
	int			i;
	int			j;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	int			path_error;
	int			count;
	int			count1;
	int			count2;
	int			player;
	int			nbr;
	int			map;
	int			length;
	int			height;
	char		**pars;
	char		**pars_temp;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	void		*img;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			color_c;
	int			color_f;
	int			side;
	int			lineHeight;
	t_texture	*texture;
	t_texture	*image;
	t_texture	*no_text;
	t_texture	*so_text;
	t_texture	*we_text;
	t_texture	*ea_text;
	t_ray		*ray;
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
int		len_y(t_data *game, int x);
size_t	len2(const char *str);
int		check_items(t_data *game);
int		check_numbers_items(t_data *game);
void	check_numbers_items2(t_data *game, int x, int y);
int		check_doublons(t_data *game);
int		check_flood_fill(t_data *game, int x, int y);
void	flood_fill(t_data *game, int x, int y);
char	**cpy_pars(t_data *game);
void	ft_free(t_data *game);
void	ft_strcpy(char *str, char *str1);
void	move_left(t_data *game, t_ray *player);
void	move_right(t_data *game, t_ray *player);
void	move_up(t_data *game, t_ray *player);
void	move_down(t_data *game, t_ray *player);
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
int		is_map_line(char *line);
int		check_doubles(t_data *game);
int		check_line(t_data *game, char *line);
int		check_path(t_data *game, int x, int y);
int		number_of_lines(char *file);
void	map_init(t_data *game, char *file);
int		ft_count(t_data *game);
int		ft_close(t_data *game);
int		ft_close1(t_data *game);
void	check_arg(int ac, char *file);
char	*ft_strstr(char *str, char *to_find);
int		is_whitespace(char c);
int		parsing_info(t_data *game, char *file);
int		is_map_line(char *line);
int		check_doubles(t_data *game);
int		check_line(t_data *game, char *line);
void	ft_count_id(t_data *game, char *str);
int		ft_check_id(const char *s1, const char *s2, size_t n);
int		ft_check_id_nb(const char *s1, const char *s2, size_t n);
int		check_numbers(const char *str);
int		check_char(char *str);
int		check_range(int *nb);
void	rotate_left(t_ray *player);
void	rotate_right(t_ray *player);
void	init_player_variables(t_ray *player, t_data *game);
void	initiate_mlx(t_data *game);
int		get_color(const char *str);
int		ft_check_id2(const char *s1, const char *s2, size_t n);
int		find_line(t_data *game, char *line);
void	ft_color(t_data *game, char *file);
void	putPixel(int x, int y, int color, t_data *game);
unsigned int	choose_color(t_data *game, int x, int y);
unsigned int	get_texture(t_data *game, int x, int y);
void	get_wall_texture(t_data *game, t_ray *player);
void	get_hor_texture_color(t_data *game, double y, t_ray *player);
void	get_vert_texture_color(t_data *game, double top_pxl, t_ray *player);
void	get_image(t_data *game);
int		init_image(t_data *game);
int		init_addr(t_data *game);
void	performDDA(t_ray *player, t_data *game);
void	renderFrame(t_data *game, t_ray *player);
#endif