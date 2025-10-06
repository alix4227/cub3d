/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:12:17 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/03 14:12:17 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}

void	check_arg(int ac, char *file)
{
	if (ac != 2)
	{
		write(1, "Invalid number of arguments\n", 28);
		exit (-1);
	}
	if (!ft_strstr(file, ".cub"))
	{
		write(1, "Invalid File\n", 13);
		exit (-1);
	}
}

void	mlx_and_map_init(t_data *game, t_ray *player, char **av)
{
	map_init(game, av[1]); //je recupere la map avec le pointeur game->pars
	if (!parsing(game)) //je parse la map
		ft_close1(game);
	initiate_mlx(game, av[1]);
	init_player_variables(player, game);
	renderframe(game, player);
	mlx_hook(game->mlx_win, KEY_PRESS, 1L << 0, &key_hook, game);
	mlx_hook(game->mlx_win, KEY_EXIT, 1L << 0, &ft_close, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_data	*game;
	t_ray	*player;

	check_arg(ac, av[1]);
	game = malloc(sizeof(t_data));
	if (!game)
		return (0);
	player = malloc(sizeof(t_ray));
	if (!player)
		return (0);
	game->ray = player;
	game->nbr = number_of_lines(av[1]);
	initiate(game);//j'initialise mes variables
	if (!parsing_info(game, av[1])) //je verifie que dans le fichier .cub les informations au dessus de la map sont correctes 
	{
		printf("error\n");
		ft_close1(game);
		return (0);
	}
	ft_color(game, av[1]);// je recupere la couleur du plafond et du sol
	game->pars = malloc(((game->nbr) + 1) * sizeof(char *));
	if (!game->pars)
		return (0);
	mlx_and_map_init(game, player, av);
}
