#include "cub3D.h"

static void	perform_dda(t_map *map, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (map->map[ray->mapY][ray->mapX] == '1')
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

static void	draw_ray_column(t_game *game, int x, t_ray *ray)
{
	int	y = 0;

	while (y < ray->drawStart)
	{
		mlx_put_pixel(game->img.img, x, y, game->texture.ceilling);
		y++;
	}

	uint32_t wall_color;
	if (ray->side == 0)
		wall_color = 0xAAAAAAFF;
	else
		wall_color = 0x555555FF;

	draw_column(game, x, ray->drawStart, ray->drawEnd, wall_color);

	y = ray->drawEnd;
	while (y < WIN_HEIGHT)
	{
		mlx_put_pixel(game->img.img, x, y, game->texture.floor);
		y++;
	}
}

void	raycasting(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		calc_ray_direction(&game->player, x, &ray.rayDirX, &ray.rayDirY);
		init_ray_step(&game->player, ray.rayDirX, ray.rayDirY, &ray);
		perform_dda(&game->map, &ray);
		calc_wall_distance_and_height(&game->player, &ray);
		draw_ray_column(game, x, &ray);
		x++;
	}
}
