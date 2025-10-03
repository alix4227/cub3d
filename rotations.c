/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:25:50 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/03 14:25:50 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	rotate_left(t_ray *player)
{
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	old_planey;

	old_dirx = player->dirx;
	old_diry = player->diry;
	old_planex = player->planex;
	old_planey = player->planey;
	player->dirx = old_dirx * cos(-ROTATION_SPEED)
		- old_diry * sin(-ROTATION_SPEED);
	player->diry = old_dirx * sin(-ROTATION_SPEED)
		+ old_diry * cos(-ROTATION_SPEED);
	player->planex = old_planex * cos(-ROTATION_SPEED)
		- old_planey * sin(-ROTATION_SPEED);
	player->planey = old_planex * sin(-ROTATION_SPEED)
		+ old_planey * cos(-ROTATION_SPEED);
}

void	rotate_right(t_ray *player)
{
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	old_planey;

	old_dirx = player->dirx;
	old_diry = player->diry;
	old_planex = player->planex;
	old_planey = player->planey;
	player->dirx = old_dirx * cos(ROTATION_SPEED)
		- old_diry * sin(ROTATION_SPEED);
	player->diry = old_dirx * sin(ROTATION_SPEED)
		+ old_diry * cos(ROTATION_SPEED);
	player->planex = old_planex * cos(ROTATION_SPEED)
		- old_planey * sin(ROTATION_SPEED);
	player->planey = old_planex * sin(ROTATION_SPEED)
		+ old_planey * cos(ROTATION_SPEED);
}

void	move_up(t_data *game, t_ray *player)
{
	double	new_posx;
	double	new_posy;

	new_posx = player->posx + player->dirx * MOVE_SPEED;
	new_posy = player->posy + player->diry * MOVE_SPEED;
	if (game->pars[(int)player->posy][(int)new_posx] == '0')
		player->posx = new_posx;
	if (game->pars[(int)new_posy][(int)player->posx] == '0')
		player->posy = new_posy;
}

void	move_down(t_data *game, t_ray *player)
{
	double	new_posx;
	double	new_posy;

	new_posx = player->posx - player->dirx * MOVE_SPEED;
	new_posy = player->posy - player->diry * MOVE_SPEED;
	if (game->pars[(int)player->posy][(int)new_posx] == '0')
		player->posx = new_posx;
	if (game->pars[(int)new_posy][(int)player->posx] == '0')
		player->posy = new_posy;
}

void	move_right(t_data *game, t_ray *player)
{
	double	new_posx;
	double	new_posy;

	new_posx = player->posx - player->diry * MOVE_SPEED;
	new_posy = player->posy + player->dirx * MOVE_SPEED;
	if (game->pars[(int)player->posy][(int)new_posx] == '0')
		player->posx = new_posx;
	if (game->pars[(int)new_posy][(int)player->posx] == '0')
		player->posy = new_posy;
}

void	move_left(t_data *game, t_ray *player)
{
	double	new_posx;
	double	new_posy;

	new_posx = player->posx + player->diry * MOVE_SPEED;
	new_posy = player->posy - player->dirx * MOVE_SPEED;
	if (game->pars[(int)player->posy][(int)new_posx] == '0')
		player->posx = new_posx;
	if (game->pars[(int)new_posy][(int)player->posx] == '0')
		player->posy = new_posy;
}
