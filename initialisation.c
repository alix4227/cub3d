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
#include "so_long.h"
#include "mlx.h"

void	render(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->pars[y] != NULL)
	{
		x = 0;
		while (game->pars[y][x] != '\r' && game->pars[y][x] != '\0')
		{
			if (game->pars[y][x] == '1')
				game->img_ptr = game->img_stone;
			else if (game->pars[y][x] == 'P')
				game->img_ptr = game->img_frodof;
			else if (game->pars[y][x] == 'L')
				game->img_ptr = game->img_frodol;
			choose_image(game, x, y);
			choose_image_2(game, x, y);
			choose_image_3(game, x, y);
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_ptr,
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	initiate(t_data *game)
{
	game->x = 0;
	game->y = 0;
	game->i = 0;
	game->j = 0;
	game->count1 = 0;
	game->count2 = 0;
	game->exit = 0;
	game->collectible = 0;
	game->player = 0;
	game->img_ptr = NULL;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->img_stone = NULL;
	game->img_frodof = NULL;
	game->img_frodol = NULL;
	game->img_frodor = NULL;
	game->img_frodob = NULL;
	game->img_dooro = NULL;
	game->img_doorc = NULL;
	game->img_coll = NULL;
	game->img_backg = NULL;
}

void	map_init(t_data *game, char *file)
{
	int		i;
	char	*line;
	int		map;

	map = open(file, O_RDONLY);
	line = get_next_line(map);
	i = 0;
	while (line != NULL)
	{
		game->pars[i] = line;
		i++;
		line = get_next_line(map);
	}
	free(line);
	game->pars[i] = NULL;
	close(map);
}
