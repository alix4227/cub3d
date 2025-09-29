#include "cub3d.h"
#include "mlx.h"

void initiate_mlx(t_data *game)
{
	game->img = mlx_new_image(game->mlx, game->length, game->height);
	game->addr = mlx_get_data_addr(game->img,
			&game->bits_per_pixel,
			&game->line_length, &game->endian);
}

int	get_color(const char *str)
{
	int		nb[2];
	char	s[1000];
	int		j;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] != ',')
		{
			s[j] = str[i];
			j++;
			i++;
		}
		s[j] = '\0';
		nb[k] = atoi(s);
		if (str[i] == '\0')
			break;
		i++;
		k++;
	}
	b = nb[0];
	g = nb[1];
	r = nb[2];
	res = (r << 16) + (g << 8) + b;
	return (res);
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
	int	i;
	char *id[] = {"F", "C"};
	
	i = 0;
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

void	ft_color(t_data *game)
{
	char	*line;
	int		map;

	map = open(file, O_RDONLY);
	line = get_next_line(map);
	while (line != NULL)
	{
		if (is_map_line(line))
			break;
		find_line(game, line)
		line = get_next_line(map);
	}
	free(line);
	close(map);
	get_next_line(-1);
}





