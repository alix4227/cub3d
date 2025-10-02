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

void	ft_mlx_destroy_image(t_data *game)
{
	if (game->no_text->img)
		mlx_destroy_image(game->mlx, game->no_text->img);
	if (game->so_text->img)
		mlx_destroy_image(game->mlx, game->so_text->img);
	if (game->we_text->img)
		mlx_destroy_image(game->mlx, game->we_text->img);
	if (game->ea_text->img)
		mlx_destroy_image(game->mlx, game->ea_text->img);
	if (game->img)
        mlx_destroy_image(game->mlx, game->img);
}

void	ft_destroy_image_path(t_data *game)
{
	free(game->no_text->path);
	free(game->so_text->path);
	free(game->ea_text->path);
	free(game->we_text->path);
	free(game->no_text);
	free(game->so_text);
	free(game->ea_text);
	free(game->we_text);

}

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
	ft_mlx_destroy_image(game);
	ft_destroy_image_path(game);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->mlx);
	ft_free_pars(game);
	free(game->ray);
	free(game);
	exit (0);
}

int	ft_close1(t_data *game)
{
	free(game->mlx);
	ft_free_pars(game);
	free(game->ray);
	free(game);
	exit (0);
}
