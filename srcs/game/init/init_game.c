/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:11:14 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/03 14:11:14 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initiate(t_data *game)
{
	game->x = 0;
	game->y = 0;
	game->i = 0;
	game->j = 0;
	game->count1 = 0;
	game->count2 = 0;
	game->player = 0;
	game->path_error = 0;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->no = 0;
	game->so = 0;
	game->we = 0;
	game->ea = 0;
	game->f = 0;
	game->c = 0;
	game->bits_per_pixel = 0;
	game->line_length = 0;
	game->endian = 0;
	game->lineheight = 0;
	game->pars = NULL;
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	handle_empty_line_error(int map, char *line)
{
	char	*temp;

	write(2, "Error\nEmpty line in map\n", 25);
	free(line);
	temp = get_next_line(map);
	while (temp)
	{
		free(temp);
		temp = get_next_line(map);
	}
	close(map);
	get_next_line(-1);
	return (0);
}

static char	*skip_to_map(int map)
{
	char	*line;

	line = get_next_line(map);
	while (line != NULL)
	{
		if (is_map_line(line))
			break ;
		free(line);
		line = get_next_line(map);
	}
	return (line);
}

int	map_init(t_data *game, char *file)
{
	int		i;
	char	*line;
	int		map;

	map = open(file, O_RDONLY);
	i = 0;
	line = skip_to_map(map);
	while (line != NULL)
	{
		if (i > 0 && is_empty_line(line))
		{
			game->pars[i] = NULL;
			return (handle_empty_line_error(map, line));
		}
		game->pars[i] = line;
		i++;
		line = get_next_line(map);
	}
	game->pars[i] = NULL;
	close(map);
	return (1);
}
