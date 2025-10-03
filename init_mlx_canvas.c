/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_canvas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:05:31 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/03 14:05:31 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	initiate_mlx(t_data *game, char *file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Cub3D");
	if (!game->mlx_win)
		return ;
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->addr = mlx_get_data_addr(game->img,
			&game->bits_per_pixel,
			&game->line_length, &game->endian);
	if (!init_image(game, file))
		return ;
}

int	find_color2(int *nb)
{
	int		b;
	int		g;
	int		r;
	int		res;

	r = nb[0];
	g = nb[1];
	b = nb[2];
	res = (r << 16) + (g << 8) + b;
	return (res);
}

void	find_color(const char *str, char *s, int *nb)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] != ',')
		{
			if (str[i] == 'F' || str[i] == 'C')
				i++;
			s[j++] = str[i++];
		}
		s[j] = '\0';
		nb[k++] = atoi(s);
		if (str[i] == '\0')
			break ;
		i++;
	}
}

int	get_color(const char *str)
{
	int		nb[1000];
	char	s[1000];

	find_color(str, s, nb);
	return (find_color2(nb));
}

int	ft_check_id2(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0 ;
	while (s1[i] == s2[i] && i < n && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

int	find_line(t_data *game, char *line)
{
	int		i;
	char	*id[2];

	i = 0;
	id[0] = "F";
	id[1] = "C";
	while (is_whitespace(line[i]))
		i++;
	if (line[i] == '\0')
		return (1);
	i = 0;
	while (i < 2)
	{
		if (ft_check_id2(line, id[i], 0))
		{
			if (i == 0)
				game->color_f = get_color(line);
			else
				game->color_c = get_color(line);
		}
		i++;
	}
	return (0);
}

void	ft_color(t_data *game, char *file)
{
	char	*line;
	int		map;

	map = open(file, O_RDONLY);
	line = get_next_line(map);
	while (line != NULL)
	{
		if (is_map_line(line))
		{
			free(line);
			break ;
		}
		find_line(game, line);
		free(line);
		line = get_next_line(map);
	}
	close(map);
	get_next_line(-1);
}
