#include "cub3d.h"
#include "mlx.h"

char *get_image_path(const char *str)
{
	char	*s;
	int		j;
	int		i;

	i = 0;
	j = 0;
	s = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!s)
		return NULL;
	while (str[i] && str[i] != '.')
		i++;
	while (str[i] && str[i] != '\n' && str[i] != '\r')
	{
		s[j] = str[i];
		j++;
		i++;
	}
	s[j] = '\0';
	return (s);
}

void	find_lines(t_data *game, char *line)
{
	int	i;
	int	j;
	char *id[] = {"NO", "SO", "WE", "EA"};
	char **textures[] = {&game->no_text->path, &game->so_text->path,
		&game->we_text->path, &game->ea_text->path};
	
	i = 0;
	j = 0;
	while (is_whitespace(line[i]))
		i++;
	while (j < 4)
	{
		if (ft_check_id2(&line[i], id[j], 1))
		{
			*textures[j] = get_image_path(line);
			return ;
		}
		j++;
	}
}

void	get_image(t_data *game, char *file)
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
			break;
		}
		find_lines(game, line);
		free(line);
		line = get_next_line(map);
	}
	close(map);
	get_next_line(-1);
}