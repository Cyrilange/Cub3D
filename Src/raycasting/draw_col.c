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

void ft_put_pixel(t_game *game, int x, int y, uint32_t color)
{
    if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
        return ;

    uint8_t *pixels = game->img.img->pixels;
    int idx = (y * game->img.img->width + x) * 4;

    pixels[idx + 0] = (color >> 24) & 0xFF; // R
    pixels[idx + 1] = (color >> 16) & 0xFF; // G
    pixels[idx + 2] = (color >> 8)  & 0xFF; // B
    pixels[idx + 3] = color & 0xFF;         // A
}


void draw_ray_column(t_game *game, int x, t_ray *ray)
{
    mlx_texture_t *t;
    uint32_t color;
    int texX, texY, d, y, tex_id;

    if (ray->side == 0)
        ray->wallX = game->player.pos_y + ray->perpWallDist * ray->rayDirY;
    else
        ray->wallX = game->player.pos_x + ray->perpWallDist * ray->rayDirX;
    ray->wallX -= floor(ray->wallX);

    if (ray->side == 0 && ray->rayDirX < 0) tex_id = 0;
    else if (ray->side == 0 && ray->rayDirX >= 0) tex_id = 1;
    else if (ray->side == 1 && ray->rayDirY < 0) tex_id = 2;
    else tex_id = 3;

    if (tex_id == 0) t = game->texture.no;
    else if (tex_id == 1) t = game->texture.so;
    else if (tex_id == 2) t = game->texture.we;
    else t = game->texture.ea;

    texX = (int)(ray->wallX * (double)t->width);
    if ((ray->side == 0 && ray->rayDirX > 0) || (ray->side == 1 && ray->rayDirY < 0))
        texX = t->width - texX - 1;

    unsigned char *pix = t->pixels;
    int tw = t->width;
    int th = t->height;
	y = ray->drawStart; 
    while (y < ray->drawEnd)
    {
        d = y * 256 - WIN_HEIGHT * 128 + ray->lineHeight * 128;
        texY = ((d * th) / ray->lineHeight) / 256;
        int idx = (texY * tw + texX) * 4;
        color = (pix[idx] << 24) | (pix[idx+1] << 16) | (pix[idx+2] << 8) | pix[idx+3];
        ft_put_pixel(game, x, y, color);
		y++;
    }
}
