/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:56:58 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/03 13:56:58 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_image_path(const char *str)
{
	char	*s;
	int		j;
	int		i;

	i = 0;
	j = 0;
	s = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!s)
		return (NULL);
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

static void	init_ids(char **id)
{
	id[0] = "NO";
	id[1] = "SO";
	id[2] = "WE";
	id[3] = "EA";
}

static void	init_textures(char ***textures, t_data *game)
{
	textures[0] = &game->no_text->path;
	textures[1] = &game->so_text->path;
	textures[2] = &game->we_text->path;
	textures[3] = &game->ea_text->path;
}

void	find_lines(t_data *game, char *line)
{
	int		i;
	int		j;
	char	*id[4];
	char	**textures[4];

	i = 0;
	j = 0;
	init_ids(id);
	init_textures(textures, game);
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
			break ;
		}
		find_lines(game, line);
		free(line);
		line = get_next_line(map);
	}
	close(map);
	get_next_line(-1);
}
