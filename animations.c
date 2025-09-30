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
	double	old_planX;
	double	old_planY;

	old_dirX = player->dirX;
	old_dirY = player->dirY;
	old_planX = player->planX;
	old_planY = player->planY;
	player->dirX = old_dirX * cos(-ROTATION_SPEED) - old_dirY * sin(-ROTATION_SPEED);
	player->dirY = old_dirX * sin(-ROTATION_SPEED) + old_dirY * cos(-ROTATION_SPEED);
	player->planX = old_planX * cos(-ROTATION_SPEED) - old_planY * sin(-ROTATION_SPEED);
	player->planY = old_planX * sin(-ROTATION_SPEED) + old_planY * cos(-ROTATION_SPEED);
}

void	rotate_right(t_ray *player)
{
	double	old_dirX;
	double	old_dirY;
	double	old_planX;
	double	old_planY;

	old_dirX = player->dirX;
	old_dirY = player->dirY;
	old_planX = player->planX;
	old_planY = player->planY;
	player->dirX = old_dirX * cos(ROTATION_SPEED) - old_dirY * sin(ROTATION_SPEED);
	player->dirY = old_dirX * sin(ROTATION_SPEED) + old_dirY * cos(ROTATION_SPEED);
	player->planX = old_planX * cos(ROTATION_SPEED) - old_planY * sin(ROTATION_SPEED);
	player->planY = old_planX * sin(ROTATION_SPEED) + old_planY * cos(ROTATION_SPEED);
}

// void	move_up(t_data *game)
// {
// 	if (game->pars[game->i - 1][game->j] == 'C')
// 	{
// 		game->count -= 1;
// 		game->pars[game->i - 1][game->j] = 'B';
// 		game->pars[game->i][game->j] = '0';
// 		if (game->count == 0)
// 			ft_door_open(game);
// 	}
// 	if (game->pars[game->i - 1][game->j] == '0')
// 	{
// 		game->pars[game->i - 1][game->j] = 'B';
// 		game->pars[game->i][game->j] = '0';
// 	}
// 	if (game->pars[game->i - 1][game->j] == 'O')
// 	{
// 		ft_close(game);
// 	}
// }

// void	move_down(t_data *game)
// {
// 	if (game->pars[game->i + 1][game->j] == 'C')
// 	{
// 		game->count -= 1;
// 		game->pars[game->i + 1][game->j] = 'P';
// 		game->pars[game->i][game->j] = '0';
// 		if (game->count == 0)
// 			ft_door_open(game);
// 	}
// 	if (game->pars[game->i + 1][game->j] == '0')
// 	{
// 		game->pars[game->i + 1][game->j] = 'P';
// 		game->pars[game->i][game->j] = '0';
// 	}
// 	if (game->pars[game->i + 1][game->j] == 'O')
// 	{
// 		ft_close(game);
// 	}
// }
