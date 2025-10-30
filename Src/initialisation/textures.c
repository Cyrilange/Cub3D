/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:14:03 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/30 16:40:27 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_textures(t_texture *tex)
{
	tex->no = NULL;
	tex->so = NULL;
	tex->ea = NULL;
	tex->we = NULL;
	tex->no_path = NULL;
	tex->so_path = NULL;
	tex->ea_path = NULL;
	tex->we_path = NULL;
	tex->ceilling = 0;
	tex->floor = 0;
}

void	init_hud(t_game *game)
{
	game->hud.hand_texture = mlx_load_png("./Include/assets/weapons/big.png");
	if (!game->hud.hand_texture)
		g_error_function(game, "Error\n failed to load hand texture");
	game->hud.hand_image = mlx_texture_to_image
		(game->mlx, game->hud.hand_texture);
	if (!game->hud.hand_image)
		g_error_function(game, "Error\n failed to create hand image");
	game->hud.x = WIN_WIDTH / 2 - game->hud.hand_image->width / 2;
	game->hud.y = 350;
	if (mlx_image_to_window
		(game->mlx, game->hud.hand_image, game->hud.x, game->hud.y) < 0)
		g_error_function(game, "Error\n failed to display hand image");
}
