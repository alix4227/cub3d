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

int	main(int ac, char **av)
{
	t_data	*game;
	t_ray player;
	check_arg(ac, av[1]);
	game = malloc(sizeof(t_data));
	if (!game)
		return (0);
	game->nbr = number_of_lines(av[1]);
	game->pars = malloc(((game->nbr) + 1) * sizeof(char *));
	if (!game->pars)
		return (0);
	initiate(game);
	if (!parsing_info(game, av[1]))
	{
		printf("error\n");
		return (0);
	}
	ft_color(game, av[1]);
	map_init(game, av[1]);
	if (parsing(game) == 0)
		ft_close1(game);
	renderFrame(game, player);
	// game->mlx = mlx_init();
	// game->height = game->nbr * TILE_SIZE;
	// game->length = len(game) * TILE_SIZE;
	// game->mlx_win = mlx_new_window(game->mlx, game->length,
	// 		game->height, "Cub3D");
	// init_image(game);
	// render(game);
	// mlx_hook(game->mlx_win, KEY_PRESS, 1L << 0, &key_hook, game);
	// mlx_hook(game->mlx_win, KEY_EXIT, 1L << 0, &ft_close, game);
	// mlx_loop(game->mlx);
}
