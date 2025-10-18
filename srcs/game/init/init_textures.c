/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 00:00:00 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/18 21:09:25 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_addr(t_data *game)
{
	game->no_text->addr = mlx_get_data_addr(game->no_text->img,
			&game->no_text->bits_per_pixel, &game->no_text->line_length,
			&game->no_text->endian);
	game->so_text->addr = mlx_get_data_addr(game->so_text->img,
			&game->so_text->bits_per_pixel, &game->so_text->line_length,
			&game->so_text->endian);
	game->ea_text->addr = mlx_get_data_addr(game->ea_text->img,
			&game->ea_text->bits_per_pixel, &game->ea_text->line_length,
			&game->ea_text->endian);
	game->we_text->addr = mlx_get_data_addr(game->we_text->img,
			&game->we_text->bits_per_pixel, &game->we_text->line_length,
			&game->we_text->endian);
	if (!game->no_text->addr || !game->so_text->addr || !game->ea_text->addr
		|| !game->we_text->addr)
		return (0);
	return (1);
}

int	init_image(t_data *game, char *file)
{
	game->no_text = malloc(sizeof(t_texture));
	game->so_text = malloc(sizeof(t_texture));
	game->ea_text = malloc(sizeof(t_texture));
	game->we_text = malloc(sizeof(t_texture));
	if (!game->no_text || !game->so_text || !game->ea_text || !game->we_text)
		return (0);
	get_image(game, file);
	game->no_text->img = mlx_xpm_file_to_image(game->mlx, game->no_text->path,
			&game->no_text->icon_w, &game->no_text->icon_h);
	game->so_text->img = mlx_xpm_file_to_image(game->mlx, game->so_text->path,
			&game->so_text->icon_w, &game->so_text->icon_h);
	game->we_text->img = mlx_xpm_file_to_image(game->mlx, game->we_text->path,
			&game->we_text->icon_w, &game->we_text->icon_h);
	game->ea_text->img = mlx_xpm_file_to_image(game->mlx, game->ea_text->path,
			&game->ea_text->icon_w, &game->ea_text->icon_h);
	if (!init_addr(game))
		return (0);
	return (1);
}
