/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 16:39:19 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-26 16:39:19 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void try_move(t_game *game, double dx, double dy)
{
    double newX = game->player.pos_x + dx;
    double newY = game->player.pos_y + dy;

 
    if (is_walkable(&game->map, (int)game->player.pos_x, (int)newY))
        game->player.pos_y = newY;
    if (is_walkable(&game->map, (int)newX, (int)game->player.pos_y))
        game->player.pos_x = newX;
}


static void rotate_player(t_player *player, double angle)
{
	double	oldDirX;
	double	oldPlaneX;
	double	cos_angle;
	double	sin_angle;

	oldDirX = player->dir_x;
	oldPlaneX = player->plan_x;
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	player->dir_x = player->dir_x * cos_angle - player->dir_y * sin_angle;
	player->dir_y = oldDirX * sin_angle + player->dir_y * cos_angle;
	player->plan_x = player->plan_x * cos_angle - player->plan_y * sin_angle;
	player->plan_y = oldPlaneX * sin_angle + player->plan_y * cos_angle;
}

void rotate_left(t_player *player)
{
	rotate_player(player, player->rot_speed);
}

void rotate_right(t_player *player)
{
	rotate_player(player, -player->rot_speed);
}
