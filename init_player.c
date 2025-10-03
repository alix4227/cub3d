/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:10:24 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/03 14:10:24 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	init_player_variables(t_ray *player, t_data *game)
{
	int		x;
	int		y;
	char	dir;

	y = -1;
	while (game->pars[++y])
	{
		x = -1;
		while (game->pars[y][++x])
		{
			dir = game->pars[y][x];
			if (dir == 'N' || dir == 'S' || dir == 'W' || dir == 'E')
			{
				player->posx = x;
				player->posy = y;
				player->dirx = (dir == 'E') - (dir == 'W');
				player->diry = (dir == 'S') - (dir == 'N');
				player->planex = -player->diry * 0.66;
				player->planey = player->dirx * 0.66;
				return ;
			}
		}
	}
}
