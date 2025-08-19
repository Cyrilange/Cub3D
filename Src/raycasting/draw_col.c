#include "cub3D.h"

void	calc_ray_direction(t_player *player, int x, double *rayDirX, double *rayDirY)
{
	double	cameraX = 2 * x / (double)WIN_WIDTH - 1;
	*rayDirX = player->dir_x + player->plan_x * cameraX;
	*rayDirY = player->dir_y + player->plan_y * cameraX;
}

uint32_t	get_texture_pixel(t_texture *tex, int tex_id, int x, int y)
{
	mlx_texture_t *t;

	if (tex_id == 0) t = tex->no;
	else if (tex_id == 1) t = tex->so;
	else if (tex_id == 2) t = tex->ea;
	else t = tex->we;
	int idx = (y * t->width + x) * 4;
	unsigned char *pixels = t->pixels;
	return (pixels[idx] << 24 | pixels[idx + 1] << 16 | pixels[idx + 2] << 8 | pixels[idx + 3]);
}
void	draw_ray_column(t_game *game, int x, t_ray *ray)
{
	int				y;
	double			wallX;
	mlx_texture_t	*t;
	uint32_t		color;
	int				texX;
	int				texY;
	int				d;
	int				tex_id;

	y = 0;
	while (y < ray->drawStart)
		mlx_put_pixel(game->img.img, x, y++, game->texture.ceilling);
	if (ray->side == 0)
		wallX = game->player.pos_y + ray->perpWallDist * ray->rayDirY;
	else
		wallX = game->player.pos_x + ray->perpWallDist * ray->rayDirX;
	wallX -= floor(wallX);
	if (ray->side == 0 && ray->rayDirX < 0)
		tex_id = 0;
	else if (ray->side == 0 && ray->rayDirX >= 0)
		tex_id = 1;
	else if (ray->side == 1 && ray->rayDirY < 0)
		tex_id = 2;
	else
		tex_id = 3;
	if (tex_id == 0)
		t = game->texture.no;
	else if (tex_id == 1)
		t = game->texture.so;
	else if (tex_id == 2)
		t = game->texture.we;
	else
		t = game->texture.ea;
	texX = (int)(wallX * (double)t->width);
	if ((ray->side == 0 && ray->rayDirX > 0) || (ray->side == 1 && ray->rayDirY < 0))
		texX = t->width - texX - 1;
	y = ray->drawStart;
	while (y < ray->drawEnd)
	{
		d = y * 256 - WIN_HEIGHT * 128 + ray->lineHeight * 128;
		texY = ((d * t->height) / ray->lineHeight) / 256;
		color = get_texture_pixel(&game->texture, tex_id, texX, texY);
		mlx_put_pixel(game->img.img, x, y, color);
		y++;
	}
	while (y < WIN_HEIGHT)
		mlx_put_pixel(game->img.img, x, y++, game->texture.floor);
}
