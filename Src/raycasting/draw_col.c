#include "cub3D.h"

// Calculates the direction of the ray for a given screen column (x)
void calc_ray_direction(t_player *player, int x, double *rayDirX, double *rayDirY)
{
	double	cameraX = 2 * x / (double)WIN_WIDTH - 1; // Convert screen X to camera space (-1 to 1)
	*rayDirX = player->dir_x + player->plan_x * cameraX; // Compute ray direction on X
	*rayDirY = player->dir_y + player->plan_y * cameraX; // Compute ray direction on Y
}


// Retrieves a pixel color from a texture at position (x, y)
uint32_t get_texture_pixel(t_texture *tex, int tex_id, int x, int y)
{
	mlx_texture_t *t;
	// Choose which texture to use based on the wall side
	if (tex_id == 0) t = tex->no;
	else if (tex_id == 1) t = tex->so;
	else if (tex_id == 2) t = tex->ea;
	else t = tex->we;

	int idx = (y * t->width + x) * 4;     // Compute index in RGBA pixel array
	unsigned char *pixels = t->pixels;    // Get pixel buffer
	return (pixels[idx] << 24 | pixels[idx + 1] << 16 | pixels[idx + 2] << 8 | pixels[idx + 3]); // Combine RGBA
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

// Draws a vertical wall column based on ray hit info and texture mapping
void draw_ray_column(t_game *game, int x, t_ray *ray)
{
    // Determine exact wall hit coordinate
    if (ray->side == 0)
        ray->wallX = game->player.pos_y + ray->perpWallDist * ray->rayDirY;
    else
        ray->wallX = game->player.pos_x + ray->perpWallDist * ray->rayDirX;
    ray->wallX -= floor(ray->wallX);

    // Determine which texture to use based on wall orientation
    int tex_id;
    if (ray->side == 0 && ray->rayDirX < 0) tex_id = 0;
    else if (ray->side == 0 && ray->rayDirX >= 0) tex_id = 1;
    else if (ray->side == 1 && ray->rayDirY < 0) tex_id = 2;
    else tex_id = 3;

    mlx_texture_t *t;
    if (tex_id == 0) t = game->texture.no;
    else if (tex_id == 1) t = game->texture.so;
    else if (tex_id == 2) t = game->texture.we;
    else t = game->texture.ea;

    // Compute texture X coordinate
    int texX = (int)(ray->wallX * (double)t->width);
    if ((ray->side == 0 && ray->rayDirX > 0) || (ray->side == 1 && ray->rayDirY < 0))
        texX = t->width - texX - 1;

    // Loop through each pixel in the wall slice and draw it
    int y = ray->drawStart;
    while (y < ray->drawEnd)
    {
        int d = y * 256 - WIN_HEIGHT * 128 + ray->lineHeight * 128;
        int texY = ((d * t->height) / ray->lineHeight) / 256;
        int idx = (texY * t->width + texX) * 4;
        uint32_t color = (t->pixels[idx] << 24) | (t->pixels[idx+1] << 16)
                       | (t->pixels[idx+2] << 8) | t->pixels[idx+3];
        ft_put_pixel(game, x, y, color);
        y++;
    }
}

