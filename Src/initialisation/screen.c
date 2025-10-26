#include "cub3D.h"

void	init_window(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", true);
	if (!game->mlx)
	{
		error_function("Error: Failed to initialize window\n");
	}
}

void	init_images(t_game *game)
{
	game->img.img = NULL;
	game->img.img_width = 0;
	game->img.img_height = 0;
	game->texture.no = mlx_load_png(game->texture.no_path);
	if (!game->texture.no)
		error_function("Error: failed to load NO texture");
	game->texture.so = mlx_load_png(game->texture.so_path);
	if (!game->texture.so)
		error_function("Error: failed to load SO texture");
	game->texture.ea = mlx_load_png(game->texture.ea_path);
	if (!game->texture.ea)
		error_function("Error: failed to load EA texture");
	game->texture.we = mlx_load_png(game->texture.we_path);
	if (!game->texture.we)
		error_function("Error: failed to load WE texture");
	game->img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img.img)
		error_function("Error: failed to create main image buffer");
	if (mlx_image_to_window(game->mlx, game->img.img, 0, 0) < 0)
		error_function("Error: failed to attach image buffer to window");
}

void	init_ray(t_ray *ray, t_game *game, int x)
{
	ray->cameraX = 2 * x / (double)WIN_WIDTH - 1;
	ray->rayDirX = game->player.dir_x + game->player.plan_x * ray->cameraX;
	ray->rayDirY = game->player.dir_y + game->player.plan_y * ray->cameraX;
	ray->mapX = (int)game->player.pos_x;
	ray->mapY = (int)game->player.pos_y;
	if (ray->rayDirX == 0)
		ray->deltaDistX = 1e30;
	else
		ray->deltaDistX = fabs(1 / ray->rayDirX);
	if (ray->rayDirY == 0)
		ray->deltaDistY = 1e30;
	else
		ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
}

void	init_ray_step(t_ray *ray, t_game *game)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (game->player.pos_x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - game->player.pos_x)
			* ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (game->player.pos_y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - game->player.pos_y)
			* ray->deltaDistY;
	}
}
