/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:48:12 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/06 15:35:31 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	ft_count_id(t_data *game, char *str)
{
	if (strcmp(str, "NO") == 0)
		game->no++;
	else if (strcmp(str, "SO") == 0)
		game->so++;
	else if (strcmp(str, "WE") == 0)
		game->we++;
	else if (strcmp(str, "EA") == 0)
		game->ea++;
	else if (strcmp(str, "F") == 0)
		game->f++;
	else if (strcmp(str, "C") == 0)
		game->c++;
}

static void	init_doublons(int *doublons, t_data *game)
{
	doublons[0] = game->no;
	doublons[1] = game->so;
	doublons[2] = game->we;
	doublons[3] = game->ea;
	doublons[4] = game->f;
	doublons[5] = game->c;
}

int	check_doubles(t_data *game)
{
	int	doublons[6];
	int	i;

	i = 0;
	init_doublons(doublons, game);
	while (i < 6)
	{
		if (doublons[i] != 1)
			return (0);
		i++;
	}
	return (1);
}
