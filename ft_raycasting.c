/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:53:20 by blefebvr          #+#    #+#             */
/*   Updated: 2025/09/28 14:05:49 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	ft_update_player_pos(t_player *p)
{
	int		move_step;
	double	new_pos_x;
	double	new_pos_y;

	move_step = 0;
	p->rot_angle += p->turn_dir * ROT_SPEED;
	normalize_rotation_angle(p);
	if (p->walk_dir != 0)
		move_step = p->walk_dir * MOVE_SPEED;
	new_pos_x = p->x + cos(p->rot_angle) * move_step;
	new_pos_y = p->y + sin(p->rot_angle) * move_step;
	if (p->lateral_dir != 0)
	{
		move_step = p->lateral_dir * MOVE_SPEED;
		new_pos_x = p->x + cos(p->rot_angle + (M_PI / 2)) * move_step;
		new_pos_y = p->y + sin(p->rot_angle + (M_PI / 2)) * move_step;
	}
	if (!ft_has_wall(p, new_pos_x, new_pos_y))
	{
		p->x = new_pos_x;
		p->y = new_pos_y;
		p->ray_angle = p->rot_angle - (FOV_ANGLE / 2);
	}
}

void	cast_one_ray(t_player *p, int col)
{
	get_ray_orientation(&p->r[col]);
	check_horizontal_ray(p, col);
	check_vertical_ray(p, col);
	p->r[col].end = get_hit_dist(p, col);
	p->r[col].dist = normalize_distortion(p, col);
	get_wall_text(p, col);
	get_wall_height(p, col);
}

void	cast_rays(t_player *p)
{
	int		col;
	double	ray_a;
	double	top_pxl;

	col = 0;
	ft_put_colors(p->cub);
	while (col < NUM_RAYS)
	{
		ray_a = p->rot_angle + atan((col - NUM_RAYS / 2) / p->player_dist);
		ft_init_ray(&p->r[col], ray_a);
		cast_one_ray(p, col);
		top_pxl = WIN_H / 2 - p->r[col].wall_height / 2;
		draw_strips(p, col, top_pxl);
		col++;
	}
	mlx_put_image_to_window(p->cub->mlx, p->cub->win, p->cub->image->img, 0, 0);
}
