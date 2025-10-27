/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:14:21 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/27 12:56:18 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static mlx_texture_t	*get_texture_ptr(t_texture *tex, int id)
{
	if (id == 0)
		return (tex->no);
	if (id == 1)
		return (tex->so);
	if (id == 2)
		return (tex->ea);
	return (tex->we);
}

static int	get_texture_id(t_ray *r)
{
	if (r->side == 0 && r->rayDirX < 0)
		return (0);
	if (r->side == 0 && r->rayDirX >= 0)
		return (1);
	if (r->side == 1 && r->rayDirY < 0)
		return (2);
	return (3);
}

void	ft_put_pixel(t_game *g, int x, int y, uint32_t c)
{
	uint8_t	*p;
	int		i;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	p = g->img.img->pixels;
	i = (y * g->img.img->width + x) * 4;
	p[i] = (c >> 24) & 0xFF;
	p[i + 1] = (c >> 16) & 0xFF;
	p[i + 2] = (c >> 8) & 0xFF;
	p[i + 3] = c & 0xFF;
}

static void	draw_tex_line(t_game *g, int x, t_ray *r, mlx_texture_t *t)
{
	unsigned char	*pixels;
	uint32_t		color;
	int				y;

	r->tx = (int)(r->wallX * t->width);
	if ((r->side == 0 && r->rayDirX > 0) || (r->side == 1 && r->rayDirY < 0))
		r->tx = t->width - r->tx - 1;
	pixels = t->pixels;
	y = r->drawStart;
	while (y < r->drawEnd)
	{
		r->d = y * 256 - WIN_HEIGHT * 128 + r->lineHeight * 128;
		r->ty = ((r->d * t->height) / r->lineHeight) / 256;
		r->idx = (r->ty * t->width + r->tx) * 4;
		color = (pixels[r->idx] << 24) | (pixels[r->idx
				+ 1] << 16) | (pixels[r->idx + 2] << 8) | pixels[r->idx + 3];
		ft_put_pixel(g, x, y++, color);
	}
}

void	draw_ray_column(t_game *g, int x, t_ray *r)
{
	mlx_texture_t	*t;
	int				id;

	if (r->side == 0)
		r->wallX = g->player.pos_y + r->perpWallDist * r->rayDirY;
	else
		r->wallX = g->player.pos_x + r->perpWallDist * r->rayDirX;
	r->wallX -= floor(r->wallX);
	id = get_texture_id(r);
	t = get_texture_ptr(&g->texture, id);
	if (!t)
		return ;
	draw_tex_line(g, x, r, t);
}
