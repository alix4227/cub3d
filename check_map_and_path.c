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
#include "mlx.h"

int	check_map(t_data *game)
{
	if (!game || !game->pars || !game->pars[0])
	{
		write(2, "Error : map non chargée\n", 26);
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
	if (check_flood_fill(game, x, y) == 1)
		return (0);
	return (1);
}

int	parsing(t_data *game)
{
	// int	x;
	// int	y;

	// x = 0;
	// y = 0;
	if (check_map(game) == 0)
		return (0);
	// game->pars_temp = cpy_pars(game);
	// if (check_path(game, x, y) == 0)
	// {
	// 	write(1, "Error: No path\n", 15);
	// 	ft_free(game);
	// 	return (0);
	// }
	// ft_free(game);
	return (1);
}
