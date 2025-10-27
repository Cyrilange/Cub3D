/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:13:57 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/27 12:23:24 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	load_textures(t_game *game)
{
	game->texture.no = mlx_load_png(game->texture.no_path);
	game->texture.so = mlx_load_png(game->texture.so_path);
	game->texture.ea = mlx_load_png(game->texture.ea_path);
	game->texture.we = mlx_load_png(game->texture.we_path);

	if (!game->texture.no || !game->texture.so
		|| !game->texture.ea || !game->texture.we)
	{
		free_game(game);
		error_function("Error: failed to load textures");
	}
}

void	init_images(t_game *game)
{
	game->img.img = NULL;
	game->img.img_width = 0;
	game->img.img_height = 0;
	load_textures(game);
	game->img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img.img || mlx_image_to_window(game->mlx, game->img.img, 0, 0) < 0)
	{
		free_game(game);
		error_function("Error: failed to create/attach main image");
	}
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
