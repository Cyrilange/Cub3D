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
	unsigned char	*p;
	uint32_t		col;
	int				y, d, ty, tx, i;

	tx = (int)(r->wallX * t->width);
	if ((r->side == 0 && r->rayDirX > 0) || (r->side == 1 && r->rayDirY < 0))
		tx = t->width - tx - 1;
	p = t->pixels;
	y = r->drawStart;
	while (y < r->drawEnd)
	{
		d = y * 256 - WIN_HEIGHT * 128 + r->lineHeight * 128;
		ty = ((d * t->height) / r->lineHeight) / 256;
		i = (ty * t->width + tx) * 4;
		col = (p[i] << 24) | (p[i + 1] << 16)
			| (p[i + 2] << 8) | p[i + 3];
		ft_put_pixel(g, x, y, col);
		y++;
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
