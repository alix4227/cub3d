/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:41:36 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/03 18:41:36 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
// // ========== Étape 1: initialisation des directions ==========

// // position du joueur (coordonnées réelles, pas de grille)
// double posx = player->x; 
// double posy = player->y;  

// // direction de la caméra (vecteur directeur)
// double dirx = player->dirx;
// double diry = player->diry;

// // plan de la caméra (perpendiculaire à la direction, pour le fov)
// double planex = player->planex;
// double planey = player->planey; 

// // pour chaque colonne x de l'écran (de 0 à screenwidth-1)
// int x = ;

// // coordonnée x dans l'espace caméra (de -1 à +1)
// double camerax = 2 * x / (double)screenwidth - 1;

// // direction du rayon pour cette colonne
// double player->raydirx = dirx + planex * camerax;
// double player->raydiry = diry + planey * camerax;

// // ========== Étape 2: calcul des delta distances ==========

// // distance que le rayon doit parcourir pour traverser 1 case entière
// // si player->raydirx = 0, on met une valeur très grande (1e30)
// double deltadistx = (player->raydirx == 0) ? 1e30 : fabs(1 / player->raydirx);
// double deltadisty = (player->raydiry == 0) ? 1e30 : fabs(1 / player->raydiry);

// // ========== Étape 3: calcul des premiÈres side distances et steps ==========

// int mapx = (int)posx;
// int mapy = (int)posy;

// double sidedistx, sidedisty;
// int stepx, stepy;

// if (player->raydirx < 0) 
// {
//     stepx = -1;  
//     sidedistx = (posx - mapx) * deltadistx;
// } else {
//     stepx = 1;
//     sidedistx = (mapx + 1.0 - posx) * deltadistx;
// }

// if (player->raydiry < 0) {
//     stepy = -1;  // on va vers le haut
//     sidedisty = (posy - mapy) * deltadisty;
// } 
// else 
// {
// 	stepy = 1;
//     sidedisty = (mapy + 1.0 - posy) * deltadisty;
// }

/* explication sidedistx:
 * C'est la distance du point de départ jusqu'à la prochaine ligne verticale de la grille
 */
void	get_texx(t_data *game, t_ray *player)
{
	double	wallx;

	if (game->side == 0) // mur vertical
		wallx = player->posy + player->perpwalldist * player->raydiry;
	else // mur horizontal
		wallx = player->posx + player->perpwalldist * player->raydirx;
	wallx -= floor(wallx);
// choix de la coordonnée X dans la texture
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

void	get_position(t_ray *player)
{
	player->mapx = (int)player->posx;
	player->mapy = (int)player->posy;
}

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
	int	hit;

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
		if (game->pars[player->mapy][player->mapx] > '0')
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
