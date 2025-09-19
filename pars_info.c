#include "cub3d.h"
#include "mlx.h"

int check_range(int *nb)
{
	int	i;

	i = 0;
	if (!nb)
		return (0);
	while ( i < 3)
	{
		if (nb[i] < 0 || nb[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

int	check_char(char *str)
{
	int	i;
	int digit;

	i = 0;
	digit = 0;
	if (!str)
		return (0);
	while (is_whitespace(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = 1;
		i++;
	}
		
	while (is_whitespace(str[i]))
		i++;
	if (digit && str[i] == '\0')
		return (1);
	return (0);
}

int	check_numbers(const char *str)
{
	int		nb[2];
	char	s[1000];
	int		j;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!str || str[0] == '\0')
		return (0);
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
		if(!check_char(s))
			return (0);
		nb[k] = atoi(s);
		if (str[i] == '\0')
			break;
		i++;
		k++;
	}
	if (check_range(nb))
		return (1);
	return (0);
	
}

int	ft_check_id_nb(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0 ;
	while (s1[i] == s2[i] && i < n && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] != s2[i])
		return (0);
	i++;
	while (s1[i] && is_whitespace(s1[i]))
		i++;
	if (check_numbers(&s1[i]))
		return (1);
	return (0);
}

int	ft_check_id(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0 ;
	while (s1[i] == s2[i] && i < n && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] != s2[i])
		return (0);
	i++;
	while (s1[i] && is_whitespace(s1[i]))
		i++;
	if (s1[i] && strncmp(&s1[i], "./", 2) == 0)
		return (1);
	return (0);
}

void	ft_count_id(t_data *game, char *str)
{
	if (strcmp(str, "NO") == 0)
		game->no++;
	else if(strcmp(str, "SO") == 0)
		game->so++;
	else if (strcmp(str, "WE") == 0)
		game->we++;
	else if (strcmp(str, "EA") == 0)
		game->ea++;
	else if (strcmp(str, "F") == 0)
		game->f++;
	else if (strcmp(str, "C") == 0)
		game->c++;
}

int	check_line(t_data *game, char *line)
{
	int	i;
	char *id[] = {"NO", "SO", "WE", "EA", "F", "C"};
	char *path[] = {"./path_to_the_north_texture", "./path_to_the_south_texture", 
		"./path_to_the_west_texture", "./path_to_the_east_texture"};

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	if (line[i] == '\0')
		return (1);
	i = 0;
	while (i < 6)
	{
		if (ft_check_id(line, id[i], 1))
		{
			if (ft_strstr(line, path[i]))
			{
				ft_count_id(game, id[i]);
				return (1);
			}
		}
		if (i > 3 && ft_check_id_nb(line, id[i], 0))
		{
			ft_count_id(game, id[i]);
			return (1);

		}
		i++;
	}
	return (0);
}

int	check_doubles(t_data *game)
{
	int	doublons[] = {game->no, game->so, game->we, game->ea, game->f, game->c};
	int	i;

	i = 0;
	while (i < 6)
	{
		if (doublons[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	if (line[i] == '0' || line[i] == '1')
		return (1);
	return (0);
}

int	parsing_info(t_data *game, char *file)
{
	char	*line;
	int		map;

	map = open(file, O_RDONLY);
	line = get_next_line(map);
	while (line != NULL)
	{
		if (is_map_line(line))
			break;
		if (!check_line(game, line))
			return (0);
		line = get_next_line(map);
	}
	free(line);
	close(map);
	get_next_line(-1);
	if (!check_doubles(game))
		return (0);
	return (1);
}