#include "cub3D.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		error_function("Error: Failed to initialize window\n");
	}
}
static void load_and_display(t_game *game, char *path, mlx_texture_t **tex_ptr, int x)
{
    *tex_ptr = mlx_load_png(path);
    if (!*tex_ptr)
        error_function("Error: texture issue");
    mlx_image_t *img = mlx_texture_to_image(game->mlx, *tex_ptr);
    if (!img)
        error_function("Error: image issue");
    mlx_image_to_window(game->mlx, img, x, 0);
    *tex_ptr = NULL;
}

void init_images(t_game *game)
{
    if (game->texture.no_path)
        load_and_display(game, game->texture.no_path, &game->texture.no, 0);
    if (game->texture.so_path)
        load_and_display(game, game->texture.so_path, &game->texture.so, 100);
    if (game->texture.ea_path)
        load_and_display(game, game->texture.ea_path, &game->texture.ea, 200);
    if (game->texture.we_path)
        load_and_display(game, game->texture.we_path, &game->texture.we, 300);
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

void	init_ray_step(t_player *player, double rayDirX, double rayDirY, t_ray *ray)
{
	ray->mapX = (int)player->pos_x;
	ray->mapY = (int)player->pos_y;
	if (rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (player->pos_x - ray->mapX) / fabs(rayDirX);
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - player->pos_x) / fabs(rayDirX);
	}

	if (rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (player->pos_y - ray->mapY) / fabs(rayDirY);
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - player->pos_y) / fabs(rayDirY);
	}
	ray->deltaDistX = fabs(1 / rayDirX);
	ray->deltaDistY = fabs(1 / rayDirY);
	ray->hit = 0;
}
