/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:50:07 by parracha          #+#    #+#             */
/*   Updated: 2025/09/29 19:34:02 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	get_wall_text(t_player *p, int col)
{
	if (p->r[col].is_hor_hit && p->r[col].is_ray_up && (p->r[col].is_ray_left
			|| p->r[col].is_ray_right))
	{
		p->r[col].text = p->cub->so_text;
		p->r[col].text->wall_hit_text = 'S';
	}
	else if (p->r[col].is_hor_hit && p->r[col].is_ray_down
		&& (p->r[col].is_ray_left || p->r[col].is_ray_right))
	{
		p->r[col].text = p->cub->no_text;
		p->r[col].text->wall_hit_text = 'N';
	}
	if (p->r[col].is_vert_hit && p->r[col].is_ray_left && (p->r[col].is_ray_up
			|| p->r[col].is_ray_down))
	{
		p->r[col].text = p->cub->ea_text;
		p->r[col].text->wall_hit_text = 'E';
	}
	else if (p->r[col].is_vert_hit && p->r[col].is_ray_right
		&& (p->r[col].is_ray_up || p->r[col].is_ray_down))
	{
		p->r[col].text = p->cub->we_text;
		p->r[col].text->wall_hit_text = 'W';
	}
}

unsigned int	get_texture(t_data *game)
{
	int				res;
	int				tex_i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	tex_i = game->texture->offset_y * game->texture->line_length + game->texture->offset_x
			* (game->texture->bits_per_pixel / 8);
	r = (unsigned char)(game->texture)[tex_i + 2];
	g = (unsigned char)(game->texture)[tex_i + 1];
	b = (unsigned char)(game->texture)[tex_i];
	res = ((int)r << 16) + ((int)g << 8) + (int)b;
	return (res);
}

unsigned int	choose_color(t_data *game, double y)
{
	unsigned int	color;

	if (r->is_hor_hit)
		get_hor_texture_color(r, y);
	else if (r->is_vert_hit)
		get_vert_texture_color(r, y);
	color = get_texture(game);
	return (color);
}

void	get_hor_texture_color(t_ray *r, double y)
{
	game->texture->offset_y = (y * game->texture->icon_h) / floor(r->wall_height);
	if (game->texture->offset_y > game->texture->icon_h)
		game->texture->offset_y = game->texture->icon_h - 1;
	game->texture->offset_x = r->end.x % TILES_S;
	if (r->is_ray_down)
		game->texture->offset_x = TILES_S - game->texture->offset_x;
	game->texture->offset_x = (game->texture->offset_x * game->texture->icon_w) / TILES_S;
	if (game->texture->offset_x > game->texture->icon_w)
		game->texture->offset_x = game->texture->icon_w;
}

void	get_vert_texture_color(t_ray *r, double top_pxl)
{
	t_image	*tex;

	tex = r->text;
	tex->offset_y = (top_pxl * tex->icon_h) / floor(r->wall_height);
	if (tex->offset_y >= tex->icon_w)
		tex->offset_y = tex->icon_w - 1;
	tex->offset_x = r->end.y % TILES_S;
	if (r->is_ray_left)
		tex->offset_x = TILES_S - tex->offset_x;
	tex->offset_x = (tex->offset_x * tex->icon_h) / TILES_S;
	if (tex->offset_x > tex->icon_w)
		tex->offset_x = tex->icon_w;
}
