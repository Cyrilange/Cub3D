#include "cub3D.h"

static void perform_dda(t_game *game, t_ray *ray) {
    while (!ray->hit) 
	{
		if (ray->mapX < 0 || ray->mapX >= game->map.map_width ||
			ray->mapY < 0 || ray->mapY >= game->map.map_height)
		{
			ray->hit = 1;
			break;
		}
        if (ray->sideDistX < ray->sideDistY) {
            ray->sideDistX += ray->deltaDistX;
            ray->mapX += ray->stepX;
            ray->side = 0;
        } else {
            ray->sideDistY += ray->deltaDistY;
            ray->mapY += ray->stepY;
            ray->side = 1;
        }
        if (game->map.map[ray->mapY][ray->mapX] == '1')
            ray->hit = 1;
    }
}


static void	calc_wall_distance_and_height(t_player *player, t_ray *ray)
{
	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - player->pos_x + (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		ray->perpWallDist = (ray->mapY - player->pos_y + (1 - ray->stepY) / 2) / ray->rayDirY;

	ray->lineHeight = (int)(WIN_HEIGHT / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + WIN_HEIGHT / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + WIN_HEIGHT / 2;
	if (ray->drawEnd >= WIN_HEIGHT)
		ray->drawEnd = WIN_HEIGHT - 1;
}


void raycasting(t_game *game)
{
    int x;
    t_ray ray;

    x = 0;
    while (x < WIN_WIDTH)
    {
        init_ray(&ray, game, x);
        init_ray_step(&ray, game);
        perform_dda(game, &ray);
        if (!ray.hit)
            printf("Ray at column %d didn't hit any wall. mapX=%d, mapY=%d\n",
                   x, ray.mapX, ray.mapY);
        calc_wall_distance_and_height(&game->player, &ray);
        draw_ray_column(game, x, &ray);
        x++;
    }
}
