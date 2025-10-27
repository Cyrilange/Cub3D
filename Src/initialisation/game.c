/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:10:35 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/27 11:10:36 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->map_height = 0;
	map->map_width = 0;
}

void	init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	init_textures(&game->texture);
	init_map(&game->map);
}

void	init_game(t_game *game)
{
	// parsing function()
	init_images(game);
}
