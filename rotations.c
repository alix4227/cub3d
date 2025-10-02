/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:25:33 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:25:33 by acrusoe          ###   ########.fr       */
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

	old_dirX = player->dirX;
	old_dirY = player->dirY;
	old_planeX = player->planeX;
	old_planeY = player->planeY;
	player->dirX = old_dirX * cos(-ROTATION_SPEED) - old_dirY * sin(-ROTATION_SPEED);
	player->dirY = old_dirX * sin(-ROTATION_SPEED) + old_dirY * cos(-ROTATION_SPEED);
	player->planeX = old_planeX * cos(-ROTATION_SPEED) - old_planeY * sin(-ROTATION_SPEED);
	player->planeY = old_planeX * sin(-ROTATION_SPEED) + old_planeY * cos(-ROTATION_SPEED);
}

void	rotate_right(t_ray *player)
{
	double	old_dirX;
	double	old_dirY;
	double	old_planeX;
	double	old_planeY;

	old_dirX = player->dirX;
	old_dirY = player->dirY;
	old_planeX = player->planeX;
	old_planeY = player->planeY;
	player->dirX = old_dirX * cos(ROTATION_SPEED) - old_dirY * sin(ROTATION_SPEED);
	player->dirY = old_dirX * sin(ROTATION_SPEED) + old_dirY * cos(ROTATION_SPEED);
	player->planeX = old_planeX * cos(ROTATION_SPEED) - old_planeY * sin(ROTATION_SPEED);
	player->planeY = old_planeX * sin(ROTATION_SPEED) + old_planeY * cos(ROTATION_SPEED);
}

void	move_up(t_data *game, t_ray *player)
{
	double	new_posX;
	double	new_posY;

	new_posX = player->posX + player->dirX * MOVE_SPEED;
	new_posY = player->posY + player->dirY * MOVE_SPEED;
	if (game->pars[(int)player->posY][(int)new_posX] == '0')
		player->posX = new_posX;
	if (game->pars[(int)new_posY][(int)player->posX] == '0')
		player->posY = new_posY;
}

void	move_down(t_data *game, t_ray *player)
{
	double	new_posX;
	double	new_posY;

	new_posX = player->posX - player->dirX * MOVE_SPEED;
	new_posY = player->posY - player->dirY * MOVE_SPEED;
	if (game->pars[(int)player->posY][(int)new_posX] == '0')
		player->posX = new_posX;
	if (game->pars[(int)new_posY][(int)player->posX] == '0')
		player->posY = new_posY;
}

void	move_right(t_data *game, t_ray *player)
{
	double	new_posX;
	double	new_posY;

	new_posX = player->posX - player->dirY * MOVE_SPEED;
	new_posY = player->posY + player->dirX * MOVE_SPEED;
	if (game->pars[(int)player->posY][(int)new_posX] == '0')
		player->posX = new_posX;
	if (game->pars[(int)new_posY][(int)player->posX] == '0')
		player->posY = new_posY;
}

void	move_left(t_data *game, t_ray *player)
{
	double	new_posX;
	double	new_posY;

	new_posX = player->posX + player->dirY * MOVE_SPEED;
	new_posY = player->posY - player->dirX * MOVE_SPEED;
	if (game->pars[(int)player->posY][(int)new_posX] == '0')
		player->posX = new_posX;
	if (game->pars[(int)new_posY][(int)player->posX] == '0')
		player->posY = new_posY;
}