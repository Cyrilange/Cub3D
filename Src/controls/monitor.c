/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:04:28 by csalamithom       #+#    #+#             */
/*   Updated: 2025/10/31 10:18:24 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	handle_minimap_toggle(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_M))
	{
		if (!game->m_key_pressed)
		{
			game->show_minimap = !game->show_minimap;
			game->m_key_pressed = true;
		}
	}
	else
		game->m_key_pressed = false;
	if (game->show_minimap)
		draw_minimap(game);
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_left(&game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_right(&game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		close_game(game);
	raycasting(game);
	handle_minimap_toggle(game);
}
