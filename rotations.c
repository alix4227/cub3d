/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/04/08 14:25:33 by acrusoe           #+#    #+#             */
/*   updated: 2025/04/08 14:25:33 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "mlx.h"

void	rotate_left(t_ray *player)
{
	double	old_dirX;
	double	old_dirY;
	double	old_planeX;
	double	old_planeY;

	old_dirX = player->dirx;
	old_dirY = player->diry;
	old_planeX = player->planex;
	old_planeY = player->planey;
	player->dirx = old_dirX * cos(-ROTATION_SPEED) - old_dirY * sin(-ROTATION_SPEED);
	player->diry = old_dirX * sin(-ROTATION_SPEED) + old_dirY * cos(-ROTATION_SPEED);
	player->planex = old_planeX * cos(-ROTATION_SPEED) - old_planeY * sin(-ROTATION_SPEED);
	player->planey = old_planeX * sin(-ROTATION_SPEED) + old_planeY * cos(-ROTATION_SPEED);
}

void	rotate_right(t_ray *player)
{
	double	old_dirX;
	double	old_dirY;
	double	old_planeX;
	double	old_planeY;

	old_dirX = player->dirx;
	old_dirY = player->diry;
	old_planeX = player->planex;
	old_planeY = player->planey;
	player->dirx = old_dirX * cos(ROTATION_SPEED) - old_dirY * sin(ROTATION_SPEED);
	player->diry = old_dirX * sin(ROTATION_SPEED) + old_dirY * cos(ROTATION_SPEED);
	player->planex = old_planeX * cos(ROTATION_SPEED) - old_planeY * sin(ROTATION_SPEED);
	player->planey = old_planeX * sin(ROTATION_SPEED) + old_planeY * cos(ROTATION_SPEED);
}

void	move_up(t_data *game, t_ray *player)
{
	double	new_posX;
	double	new_posY;

	new_posX = player->posx + player->dirx * MOVE_SPEED;
	new_posY = player->posy + player->diry * MOVE_SPEED;
	if (game->pars[(int)player->posy][(int)new_posX] == '0')
		player->posx = new_posX;
	if (game->pars[(int)new_posY][(int)player->posx] == '0')
		player->posy = new_posY;
}

void	move_down(t_data *game, t_ray *player)
{
	double	new_posX;
	double	new_posY;

	new_posX = player->posx - player->dirx * MOVE_SPEED;
	new_posY = player->posy - player->diry * MOVE_SPEED;
	if (game->pars[(int)player->posy][(int)new_posX] == '0')
		player->posx = new_posX;
	if (game->pars[(int)new_posY][(int)player->posx] == '0')
		player->posy = new_posY;
}

void	move_right(t_data *game, t_ray *player)
{
	double	new_posX;
	double	new_posY;

	new_posX = player->posx - player->diry * MOVE_SPEED;
	new_posY = player->posy + player->dirx * MOVE_SPEED;
	if (game->pars[(int)player->posy][(int)new_posX] == '0')
		player->posx = new_posX;
	if (game->pars[(int)new_posY][(int)player->posx] == '0')
		player->posy = new_posY;
}

void	move_left(t_data *game, t_ray *player)
{
	double	new_posX;
	double	new_posY;

	new_posX = player->posx + player->diry * MOVE_SPEED;
	new_posY = player->posy - player->dirx * MOVE_SPEED;
	if (game->pars[(int)player->posy][(int)new_posX] == '0')
		player->posx = new_posX;
	if (game->pars[(int)new_posY][(int)player->posx] == '0')
		player->posy = new_posY;
}