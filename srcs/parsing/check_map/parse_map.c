/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:49:38 by acrusoe           #+#    #+#             */
/*   Updated: 2025/03/22 10:49:38 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	len(t_data *game)
{
	int	y;
	int	x;
	int	max_len;
	int	current_len;

	y = 0;
	max_len = 0;
	while (game->pars[y])
	{
		x = 0;
		current_len = 0;
		while (game->pars[y][x] && game->pars[y][x] != '\n')
		{
			current_len++;
			x++;
		}
		if (current_len > max_len)
			max_len = current_len;
		y++;
	}
	return (max_len);
}

int	number_of_lines(char *file)
{
	int		i;
	char	*ligne;
	int		map;

	i = 0;
	map = open(file, O_RDONLY);
	ligne = get_next_line(map);
	while (ligne != NULL)
	{
		i++;
		free(ligne);
		ligne = get_next_line(map);
	}
	free(ligne);
	close(map);
	return (i);
}
