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
