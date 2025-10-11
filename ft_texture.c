/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:50:07 by parracha          #+#    #+#             */
/*   Updated: 2025/10/12 00:51:55 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_wall_texture(t_data *game, t_ray *player)
{
	/* mur horizontal (side == 1)*/
	if (game->side == 1)
	{
		/* rayon va vers le haut → mur sud */
		if (player->stepy == -1)
			game->texture = game->so_text;
		else // stepy == 1, rayon va vers le bas → mur nord
			game->texture = game->no_text; // ou game->no_text
	}
	// mur vertical (side == 0)
	else
	{
		if (player->stepx == -1) // rayon va vers la gauche → mur est
			game->texture = game->ea_text; // ou game->ea_text
		else // stepx == 1, rayon va vers la droite → mur ouest
			game->texture = game->we_text; // ou game->we_text
	}
}

unsigned int	get_texture(t_data *game, int x, int y)
{
	int				res;
	int				tex_i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	tex_i = y * game->texture->line_length + x
		* (game->texture->bits_per_pixel / 8);
	r = (unsigned char)(game->texture->addr)[tex_i + 2];
	g = (unsigned char)(game->texture->addr)[tex_i + 1];
	b = (unsigned char)(game->texture->addr)[tex_i];
	res = ((int)r << 16) + ((int)g << 8) + (int)b;
	return (res);
}

unsigned int	choose_color(t_data *game, int x, int y)
{
	unsigned int	color;

	color = get_texture(game, x, y);
	return (color);
}
