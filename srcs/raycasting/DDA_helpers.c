/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 00:00:00 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/17 00:57:53 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	get_texx(t_data *game, t_ray *player)
{
	double	wallx;

	if (game->side == 0)
		wallx = player->posy + player->perpwalldist * player->raydiry;
	else
		wallx = player->posx + player->perpwalldist * player->raydirx;
	wallx -= floor(wallx);
	game->texx = (int)(wallx * (double)game->texture->icon_w);
	if ((game->side == 0 && player->raydirx > 0)
		|| (game->side == 1 && player->raydiry < 0))
		game->texx = game->texture->icon_w - game->texx - 1;
}

static void	draw_ceiling(t_data *game, int x)
{
	int	y;

	y = 0;
	while (y < game->drawstart)
		putpixel(x, y++, game->color_c, game);
}

static void	draw_wall(t_data *game, t_ray *player, int x)
{
	int	y;

	get_texx(game, player);
	game->step = 1.0 * game->texture->icon_h / game->lineheight;
	game->texpos = (game->drawstart - SCREEN_HEIGHT / 2
			+ game->lineheight / 2) * game->step;
	y = game->drawstart;
	while (y < game->drawend)
	{
		game->texy = (int)game->texpos & (game->texture->icon_h - 1);
		putpixel(x, y, choose_color(game, game->texx, game->texy), game);
		game->texpos += game->step;
		y++;
	}
}

static void	draw_floor(t_data *game, int x)
{
	int	y;

	y = game->drawend;
	while (y < SCREEN_HEIGHT)
		putpixel(x, y++, game->color_f, game);
}

void	draw_picture(t_data *game, t_ray *player, int x)
{
	draw_ceiling(game, x);
	draw_wall(game, player, x);
	draw_floor(game, x);
}
