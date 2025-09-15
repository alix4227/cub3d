/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:29:43 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:29:43 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "mlx.h"

int	check_rectangle(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\n' && s2[i] != '\n')
		i++;
	if (s1[i] != '\n' || s2[i] != '\n')
	{
		write(1, "Error : map not rectangular\n", 28);
		return (0);
	}
	return (1);
}

int	check_rectangle_2(t_data *game)
{
	int	x;
	int	z;
	int	y;

	x = 0;
	y = 0;
	z = len(game) - 1;
	while (game->pars[y] != NULL)
		y++;
	if (game->pars[y - 1][x] == '1' && game->pars[y - 1][z] == '1')
		return (1);
	else
	{
		write(1, "Error : map not rectangular\n", 28);
		return (0);
	}
}
