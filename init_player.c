#include "cub3d.h"
#include "mlx.h"

void	init_player_variables(t_ray *player, t_data *game)
{
	int		x;
	int		y;
	char	dir;

	y = -1;
	while (game->pars[++y])
	{
		x = -1;
		while (game->pars[y][++x])
		{
			dir = game->pars[y][x];
			if (dir == 'N' || dir == 'S' || dir == 'W' || dir == 'E')
			{
				player->posX = x;
				player->posY = y;
				player->dirX = (dir == 'E') - (dir == 'W');
				player->dirY = (dir == 'S') - (dir == 'N');
				player->planeX = -player->dirY * 0.66;
				player->planeY = player->dirX * 0.66;
				return ;
			}
		}
	}
}