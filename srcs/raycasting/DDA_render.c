/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 00:00:00 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/17 00:57:48 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	get_position(t_ray *player)
{
	player->mapx = (int)player->posx;
	player->mapy = (int)player->posy;
}

void	drawcolumn(int x, t_data *game, t_ray *player)
{
	game->drawstart = -game->lineheight / 2 + SCREEN_HEIGHT / 2;
	if (game->drawstart < 0)
		game->drawstart = 0;
	game->drawend = game->lineheight / 2 + SCREEN_HEIGHT / 2;
	if (game->drawend >= SCREEN_HEIGHT)
		game->drawend = SCREEN_HEIGHT - 1;
	draw_picture(game, player, x);
}

void	renderframe(t_data *game, t_ray *player)
{
	int		x;
	double	camerax;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camerax = 2 * x / (double)SCREEN_WIDTH - 1;
		player->raydirx = player->dirx + player->planex * camerax;
		player->raydiry = player->diry + player->planey * camerax;
		performdda(player, game);
		game->lineheight = (int)(SCREEN_HEIGHT / player->perpwalldist);
		get_wall_texture(game, player);
		drawcolumn(x, game, player);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
}
