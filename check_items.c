/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:30:49 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:30:49 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	check_items(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->pars[y] != NULL)
	{
		x = 0;
		while (game->pars[y][x] != '\n' && game->pars[y][x] != '\0')
		{
			if (game->pars[y][x] != 'N' && game->pars[y][x] != 'S' &&
				game->pars[y][x] != 'E' && game->pars[y][x] != 'W'
				&& game->pars[y][x] != '0' && game->pars[y][x] != '1'
				&& !is_whitespace(game->pars[y][x]))
			{
				write(2, "Error\nInvalid character in map: '", 34);
				write(2, &game->pars[y][x], 1);
				write(2, "'\n", 2);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	check_numbers_items2(t_data *game, int x, int y)
{
	while (game->pars[y] != NULL)
	{
		x = 0;
		while (game->pars[y][x] != '\n' && game->pars[y][x] != '\0')
		{
			if (game->pars[y][x] == 'N' || game->pars[y][x] == 'S' ||
				game->pars[y][x] == 'E' || game->pars[y][x] == 'W')
				game->player++;
			x++;
		}
		y++;
	}
}

int	check_numbers_items(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	check_numbers_items2(game, x, y);
	if (game->player == 0)
	{
		write(2, "Error\nNo player starting position (N/S/E/W) found in map\n", 58);
		return (0);
	}
	return (1);
}

int	check_doublons(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	game->count = 0;
	while (game->pars[y] != NULL)
	{
		x = 0;
		while (game->pars[y][x] != '\n' && game->pars[y][x] != '\0')
		{
			if (game->pars[y][x] == 'N' || game->pars[y][x] == 'S' ||
				game->pars[y][x] == 'E' || game->pars[y][x] == 'W')
				game->count++;
			x++;
		}
		y++;
	}
	if (game->count > 1 || game->count2 > 1)
	{
		if (game->count > 1)
			write(2, "Error\nMultiple player starting positions found in map\n", 55);
		return (0);
	}
	return (1);
}
