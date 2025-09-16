/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:33:22 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:33:22 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "mlx.h"

int	check_flood_fill(t_data *game, int x, int y)
{
	flood_fill(game, x, y);
	return (game->path_error);
}

void	flood_fill(t_data *game, int x, int y)
{
	if (y < 0 || x < 0 || !game->pars_temp[y] || x >= (int)ft_strlen(game->pars_temp[y]))
	{
		game->path_error = 1;
		printf("path");
		return ;
	}
	if (game->pars_temp[y][x] == '1' || game->pars_temp[y][x] == 'X')
		return ;
	if (is_whitespace(game->pars[y][x]))
	{
		game->path_error = 1;
		return ;
	}
	if (game->pars[y][x] == 'N' || game->pars[y][x] == 'S' ||
			game->pars[y][x] == 'E' || game->pars[y][x] == 'W' 
			|| game->pars[y][x] == '0')
		game->pars_temp[y][x] = 'X';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	ft_strcpy(char *str, char *str1)
{
	int	i;

	i = 0;
	while (str1[i] != '\n' && str1[i] != '\0')
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '\0';
}

char	**cpy_pars(t_data *game)
{
	int	i;

	i = 0;
	game->pars_temp = malloc(((game->nbr) + 1) * sizeof(char *));
	while (game->pars[i])
	{
		game->pars_temp[i] = malloc((len(game) + 1) * sizeof(char));
		ft_strcpy(game->pars_temp[i], game->pars[i]);
		i++;
	}
	game->pars_temp[i] = NULL;
	return (game->pars_temp);
}

void	ft_free(t_data *game)
{
	int	i;

	i = 0;
	while (game->pars_temp[i])
	{
		free(game->pars_temp[i]);
		i++;
	}
	free(game->pars_temp);
}
