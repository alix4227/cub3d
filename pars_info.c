/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:45:48 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/03 14:45:48 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

int	check_lines2(char *line, char **id, int j, t_data *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_check_cardinal_line(&line[j], id[i], 1))
		{
			ft_count_id(game, id[i]);
			return (1);
		}
		if (i > 3 && ft_check_color_nb(line, id[i], 0))
		{
			ft_count_id(game, id[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_line(t_data *game, char *line)
{
	int		j;
	char	*id[6];

	j = 0;
	init_ids2(id);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] == '\0')
		return (1);
	if (check_lines2(line, id, j, game))
		return (1);
	return (0);
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

/* ************************************************************************** */

#include "cub3d.h"

int	parsing_info(t_data *game, char *file)
{
	char	*line;
	int		map;

	map = open(file, O_RDONLY);
	line = get_next_line(map);
	while (line != NULL)
	{
		if (is_map_line(line))
			break ;
		if (!check_line(game, line))
		{
			free(line);
			get_next_line(-1);
			return (0);
		}
		free(line);
		line = get_next_line(map);
	}
	close(map);
	free(line);
	get_next_line(-1);
	if (!check_doubles(game))
		return (0);
	return (1);
}
