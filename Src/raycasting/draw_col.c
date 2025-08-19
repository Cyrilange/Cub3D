#include "cub3D.h"

void	calc_ray_direction(t_player *player, int x, double *rayDirX, double *rayDirY)
{
	double	cameraX = 2 * x / (double)WIN_WIDTH - 1;
	*rayDirX = player->dir_x + player->plan_x * cameraX;
	*rayDirY = player->dir_y + player->plan_y * cameraX;
}

void	draw_column(t_game *game, int x, int start, int end, uint32_t color)
{
    int y;

    y = start;
	while (y < end)
    {
        mlx_put_pixel(game->img.img, x, y, color);
        y++;
    }
}