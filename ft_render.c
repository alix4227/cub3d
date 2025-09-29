/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:01:51 by blefebvr          #+#    #+#             */
/*   Updated: 2025/09/29 18:42:53 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	putPixel(int x, int y, int color, t_data *game)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	ft_put_colors(t_cub *cub)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < WIN_H / 2)
// 	{
// 		x = 0;
// 		while (x <= WIN_L)
// 		{
// 			my_mlx_pixel_put(cub->image, x, y, cub->c_color);
// 			x++;
// 		}
// 		y++;
// 	}
// 	while (y <= WIN_H)
// 	{
// 		x = 0;
// 		while (x <= WIN_L)
// 		{
// 			my_mlx_pixel_put(cub->image, x, y, cub->f_color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	draw_strips(t_player *p, int x, double top_pxl)
{
	double	y;
	int		next;
	double	tmp_top_pxl;

	y = 0;
	next = x + WALL_STRIP_L;
	tmp_top_pxl = top_pxl;
	while (x < next)
	{
		y = 0;
		while (top_pxl < 0)
		{
			top_pxl = tmp_top_pxl + y++;
		}
		while (top_pxl < WIN_H)
		{
			my_mlx_pixel_put(p->cub->image, x, top_pxl,
				choose_color(&p->r[x], y));
			y += 1;
			top_pxl = tmp_top_pxl + y;
			if (y > p->r[x].wall_height)
				break ;
		}
		x++;
	}
}
