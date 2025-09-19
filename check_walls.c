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

size_t	len2(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	len_y(t_data *game, int x)
{
	int	y;

	y = 0;
	while (game->pars[y] && game->pars[y][x] != '\n')
		y++;
	return (y);
}

int is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}

int	check_walls_1(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->pars[y])
	{
		x = 0;
		while (is_whitespace(game->pars[y][x]) && game->pars[y][x] != '\n')
			x++;
		if (game->pars[y][x] != '1')
		{
			write(1, "Error: wrong wall\n", 18);
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_walls_2(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->pars[y])
	{
		x = len2(game->pars[y]) - 1;
		while (x >= 0 && is_whitespace(game->pars[y][x]))
			x--;
		if (x >= 0 && game->pars[y][x] != '1')
		{
			write(1, "Error: wrong wall\n", 18);
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_walls_3(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->pars[y][x] != '\n')
	{
		y = 0;
		while (is_whitespace(game->pars[y][x]) && game->pars[y] != NULL)
			y++;
		if (game->pars[y][x] != '1')
		{
			write(1, "Error: wrong wall\n", 18);
			return (0);
		}
		x++;
	}
	return (1);
}

int	check_walls_4(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->pars[0][x] && game->pars[0][x] != '\n')
	{
		y = len_y(game, x) - 1;
		while (y >= 0 && x >= (int)ft_strlen(game->pars[y]))
			y--;
		while (y >= 0 && is_whitespace(game->pars[y][x]))
			y--;
		if (y >= 0 && game->pars[y][x] != '1')
		{
			write(1, "Error: wrong wall\n", 18);
			return (0);
		}
		x++;
	}
	return (1);
}
