/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:16:18 by gekido            #+#    #+#             */
/*   Updated: 2025/10/17 01:16:18 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		write(2, "Error\nUsage: ./cub3D <map.cub>\n", 32);
		exit (-1);
	}
	if (!ft_strstr(file, ".cub"))
	{
		write(2, "Error\nInvalid file extension (must be .cub)\n", 45);
		exit (-1);
	}
}

void	mlx_and_map_init(t_data *game, t_ray *player, char **av)
{
	if (!map_init(game, av[1]))
		ft_close1(game);
	if (!parsing(game))
		ft_close1(game);
	initiate_mlx(game, av[1]);
	init_player_variables(player, game);
	renderframe(game, player);
	mlx_hook(game->mlx_win, KEY_PRESS, 1L << 0, &key_hook, game);
	mlx_hook(game->mlx_win, KEY_EXIT, 1L << 0, &ft_close, game);
	mlx_loop(game->mlx);
}

void	init_structs(t_data **game, t_ray **player, char **av)
{
	*game = malloc(sizeof(t_data));
	if (!*game)
		exit(1);
	ft_memset(*game, 0, sizeof(t_data));
	*player = malloc(sizeof(t_ray));
	if (!*player)
		exit(1);
	ft_memset(*player, 0, sizeof(t_ray));
	(*game)->ray = *player;
	(*game)->nbr = number_of_lines(av[1]);
	initiate(*game);
}

int	main(int ac, char **av)
{
	t_data	*game;
	t_ray	*player;

	check_arg(ac, av[1]);
	init_structs(&game, &player, av);
	if (!parsing_info(game, av[1]))
	{
		write(2, "Error\nInvalid configuration file format\n", 41);
		ft_close1(game);
		return (1);
	}
	ft_color(game, av[1]);
	game->pars = malloc(((game->nbr) + 1) * sizeof(char *));
	if (!game->pars)
		return (0);
	mlx_and_map_init(game, player, av);
}
