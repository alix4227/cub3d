/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:26:36 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:26:36 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "mlx.h"

void	check_position(t_data *game)
{
	game->i = 0;
	while (game->pars[game->i] != NULL)
	{
		game->j = 0;
		while (game->pars[game->i][game->j])
		{
			if (game->pars[game->i][game->j] == 'N')
				return ;
			if (game->pars[game->i][game->j] == 'S')
				return ;
			if (game->pars[game->i][game->j] == 'W')
				return ;
			if (game->pars[game->i][game->j] == 'E')
				return ;
			game->j++;
		}
		game->i++;
	}
}

int	key_hook(int keycode, t_data *game, t_ray *player)
{
	(void)game;
	// check_position(game);
	if (keycode == KEY_LEFT)
		rotate_left(player);
	if (keycode == KEY_RIGHT)
		rotate_right(player);
	// if (keycode == KEY_W )
	// 	move_up(game, player);
	// if (keycode == KEY_S)
	// 	move_down(game, player);
	// if (keycode == KEY_ESC)
	// 	ft_close(game);
	// render(game);
	return (0);
}
