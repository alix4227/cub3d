/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:20:05 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:20:05 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "mlx.h"

void	initiate(t_data *game)
{
	game->x = 0;
	game->y = 0;
	game->i = 0;
	game->j = 0;
	game->count1 = 0;
	game->count2 = 0;
	game->player = 0;
	game->path_error = 0;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->no = 0;
	game->so = 0;
	game->we = 0;
	game->ea = 0;
	game->f = 0;
	game->c = 0;
	game->bits_per_pixel = 0;
	game->line_length = 0;
	game->endian = 0;
	game->lineHeight = 0;
}

void	map_init(t_data *game, char *file)
{
	int		i;
	char	*line;
	int		map;

	map = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(map);
	while (line != NULL)
	{
		if (is_map_line(line))
			break;
		free(line);
		line = get_next_line(map);
	}
	while (line != NULL)
	{
		game->pars[i] = line;
		i++;
		line = get_next_line(map);
	}
	game->pars[i] = NULL;
	close(map);
}

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