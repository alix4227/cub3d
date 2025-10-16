/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:35:08 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/12 01:10:24 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	move_up(t_data *game, t_ray *player)
{
	double	new_posx;
	double	new_posy;

	new_posx = player->posx + player->dirx * MOVE_SPEED;
	new_posy = player->posy + player->diry * MOVE_SPEED;
	if (is_walkable(game->pars[(int)player->posy][(int)new_posx]))
		player->posx = new_posx;
	if (is_walkable(game->pars[(int)new_posy][(int)player->posx]))
		player->posy = new_posy;
}

void	move_down(t_data *game, t_ray *player)
{
	double	new_posx;
	double	new_posy;

	new_posx = player->posx - player->dirx * MOVE_SPEED;
	new_posy = player->posy - player->diry * MOVE_SPEED;
	if (is_walkable(game->pars[(int)player->posy][(int)new_posx]))
		player->posx = new_posx;
	if (is_walkable(game->pars[(int)new_posy][(int)player->posx]))
		player->posy = new_posy;
}

void	move_right(t_data *game, t_ray *player)
{
	double	new_posx;
	double	new_posy;

	new_posx = player->posx - player->diry * MOVE_SPEED;
	new_posy = player->posy + player->dirx * MOVE_SPEED;
	if (is_walkable(game->pars[(int)player->posy][(int)new_posx]))
		player->posx = new_posx;
	if (is_walkable(game->pars[(int)new_posy][(int)player->posx]))
		player->posy = new_posy;
}

void	move_left(t_data *game, t_ray *player)
{
	double	new_posx;
	double	new_posy;

	new_posx = player->posx + player->diry * MOVE_SPEED;
	new_posy = player->posy - player->dirx * MOVE_SPEED;
	if (is_walkable(game->pars[(int)player->posy][(int)new_posx]))
		player->posx = new_posx;
	if (is_walkable(game->pars[(int)new_posy][(int)player->posx]))
		player->posy = new_posy;
}
