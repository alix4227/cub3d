/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:41:36 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/17 00:00:00 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	get_distance(t_ray *player)
{
	if (player->raydirx == 0)
		player->deltadistx = 1e30;
	else
		player->deltadistx = fabs(1 / player->raydirx);
	if (player->raydiry == 0)
		player->deltadisty = 1e30;
	else
		player->deltadisty = fabs(1 / player->raydiry);
}

void	get_position_and_distance(t_ray *player)
{
	get_distance(player);
	get_position(player);
	if (player->raydirx < 0)
	{
		player->stepx = -1;
		player->sidedistx = (player->posx - player->mapx) * player->deltadistx;
	}
	else
	{
		player->stepx = 1;
		player->sidedistx = (player->mapx + 1.0 - player->posx)
			* player->deltadistx;
	}
	if (player->raydiry < 0)
	{
		player->stepy = -1;
		player->sidedisty = (player->posy - player->mapy) * player->deltadisty;
	}
	else
	{
		player->stepy = 1;
		player->sidedisty = (player->mapy + 1.0 - player->posy)
			* player->deltadisty;
	}
}

void	did_it_hit_wall(t_ray *player, t_data *game)
{
	int		hit;
	char	c;

	hit = 0;
	while (hit == 0)
	{
		if (player->sidedistx < player->sidedisty)
		{
			player->sidedistx += player->deltadistx;
			player->mapx += player->stepx;
			game->side = 0;
		}
		else
		{
			player->sidedisty += player->deltadisty;
			player->mapy += player->stepy;
			game->side = 1;
		}
		c = game->pars[player->mapy][player->mapx];
		if (c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
			hit = 1;
	}
}

void	performdda(t_ray *player, t_data *game)
{
	get_position_and_distance(player);
	did_it_hit_wall(player, game);
	if (game->side == 0)
		player->perpwalldist = (player->mapx - player->posx
				+ (1 - player->stepx) / 2) / player->raydirx;
	else
		player->perpwalldist = (player->mapy - player->posy
				+ (1 - player->stepy) / 2) / player->raydiry;
}
