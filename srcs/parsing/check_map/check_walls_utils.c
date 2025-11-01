/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:18:52 by acrusoe           #+#    #+#             */
/*   Updated: 2025/11/01 10:48:35 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int	last_non_empty;

	y = 0;
	last_non_empty = -1;
	while (game->pars[y])
	{
		if (x < (int)ft_strlen(game->pars[y]))
		{
			if (!is_whitespace(game->pars[y][x]))
				last_non_empty = y;
		}
		y++;
	}
	return (last_non_empty + 1);
}

int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}
