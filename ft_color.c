/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:29:07 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/12 00:51:55 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		find_color_line(game, line);
		free(line);
		line = get_next_line(map);
	}
	close(map);
	get_next_line(-1);
}
