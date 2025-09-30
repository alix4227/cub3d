/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:23:54 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:23:54 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "mlx.h"

// void	ft_mlx_destroy_image(t_data *game)
// {
// 	if (game->img_stone)
// 		mlx_destroy_image(game->mlx, game->img_stone);
// 	if (game->img_frodof)
// 		mlx_destroy_image(game->mlx, game->img_frodof);
// 	if (game->img_frodol)
// 		mlx_destroy_image(game->mlx, game->img_frodol);
// 	if (game->img_frodor)
// 		mlx_destroy_image(game->mlx, game->img_frodor);
// 	if (game->img_frodob)
// 		mlx_destroy_image(game->mlx, game->img_frodob);
// 	if (game->img_dooro)
// 		mlx_destroy_image(game->mlx, game->img_dooro);
// 	if (game->img_doorc)
// 		mlx_destroy_image(game->mlx, game->img_doorc);
// 	if (game->img_coll)
// 		mlx_destroy_image(game->mlx, game->img_coll);
// 	if (game->img_backg)
// 		mlx_destroy_image(game->mlx, game->img_backg);
// }

void	ft_free_pars(t_data *game)
{
	int	i;

	i = 0;
	while (game->pars[i])
	{
		free(game->pars[i]);
		i++;
	}
	free(game->pars);
}

int	ft_close(t_data *game)
{
	// ft_mlx_destroy_image(game);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->mlx);
	ft_free_pars(game);
	free(game);
	exit (0);
}

int	ft_close1(t_data *game)
{
	// free(game->mlx);
	ft_free_pars(game);
	free(game);
	exit (0);
}
