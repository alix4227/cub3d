/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:50:07 by parracha          #+#    #+#             */
/*   Updated: 2025/10/01 21:01:48 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	get_wall_texture(t_data *game, t_ray *player)
{
    // Mur HORIZONTAL (side == 1)
    if (game->side == 1)
    {
        if (player->stepY == -1)  // Rayon va vers le HAUT → mur SUD
           game->texture = game->so_text; 
        else  // stepY == 1, Rayon va vers le BAS → mur NORD
            game->texture = game->no_text;  // ou game->no_text
    }
    // Mur VERTICAL (side == 0)
    else
    {
        if (player->stepX == -1)  // Rayon va vers la GAUCHE → mur EST
            game->texture = game->ea_text;   // ou game->ea_text
        else  // stepX == 1, Rayon va vers la DROITE → mur OUEST
            game->texture = game->we_text;   // ou game->we_text
    }
}

unsigned int	get_texture(t_data *game, int x, int y)
{
	int				res;
	int				tex_i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	tex_i = y * game->texture->line_length + x * (game->texture->bits_per_pixel / 8);
	r = (unsigned char)(game->texture->addr)[tex_i + 2];
	g = (unsigned char)(game->texture->addr)[tex_i + 1];
	b = (unsigned char)(game->texture->addr)[tex_i];
	res = ((int)r << 16) + ((int)g << 8) + (int)b;
	return (res);
}

unsigned int	choose_color(t_data *game, int x, int y)
{
	unsigned int	color;
	
	color = get_texture(game, x , y);
	return (color);
}
