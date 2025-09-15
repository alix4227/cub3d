/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:29:00 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:29:00 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "mlx.h"

int is_whitespaces(char c)
{
	if ( c >= 9 && c <= 13 || c == ' ')
		return (1);
	return (0);
}

int	check_walls_1(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (is_whitespace(game->pars[y][x]) && game->pars[y][x] != '\n')
		x++;
	if (game->pars[y][x] != '1')
	{
		write(1, "Error: wrong wall\n", 18);
		return (0);
	}
	return (1);
}

int	check_walls_2(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (is_whitespace(game->pars[y][x]) && game->pars[y] != NULL)
		y++;
	if (game->pars[y][x] != '1')
	{
		write(1, "Error: wrong wall\n", 18);
		return (0);
	}
	return (1);
}

int	check_walls_3(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	x = len(game) - 1;
	while (is_whitespace(game->pars[y][x]) && game->pars[y] != NULL)
		y++;
	if (game->pars[y][x] != '1')
	{
		write(1, "Error: wrong wall\n", 18);
		return (0);
	}
	return (1);
}

int	check_walls_4(t_data *game)
{
	int	x;
	int	y;

	y = game->nbr - 1;
	x = 0;
	while (is_whitespace(game->pars[y][x]) && game->pars[y][x] != '\n')
		x++;
	if (game->pars[y][x] != '1')
	{
		write(1, "Error: wrong wall\n", 18);
		return (0);
	}
	return (1);
}
