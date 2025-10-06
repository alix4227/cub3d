/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:18:52 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/06 14:18:59 by acrusoe          ###   ########.fr       */
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

int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}
