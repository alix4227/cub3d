/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_and_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:34:36 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:34:36 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	check_map(t_data *game)
{
	if (!game || !game->pars || !game->pars[0])
	{
		write(2, "Error\nMap not loaded or empty\n", 31);
		return (0);
	}
	if (check_walls_1(game) == 0)
		return (0);
	if (check_walls_2(game) == 0)
		return (0);
	if (check_walls_3(game) == 0)
		return (0);
	if (check_walls_4(game) == 0)
		return (0);
	if (check_items(game) == 0)
		return (0);
	if (check_numbers_items(game) == 0)
		return (0);
	if (check_doublons(game) == 0)
		return (0);
	return (1);
}

int	check_path(t_data *game, int x, int y)
{
	while (game->pars[y])
	{
		x = 0;
		while (game->pars[y][x])
		{
			if (game->pars[y][x] == 'N' || game->pars[y][x] == 'S' ||
				game->pars[y][x] == 'E' || game->pars[y][x] == 'W')
				break ;
			x++;
		}
		if (game->pars[y][x] == 'N' || game->pars[y][x] == 'S' ||
				game->pars[y][x] == 'E' || game->pars[y][x] == 'W')
			break ;
		y++;
	}
	cpy_pars(game);
	if (check_flood_fill(game, x, y) == 1)
	{
		ft_free(game);
		return (0);
	}
	ft_free(game);
	return (1);
}

int	parsing(t_data *game)
{
	if (check_map(game) == 0)
		return (0);
	if (check_path(game, 0, 0) == 0)
		return (0);
	return (1);
}
