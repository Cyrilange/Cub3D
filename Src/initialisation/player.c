/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 16:39:34 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-26 16:39:34 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_north(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plan_x = FOV;
	player->plan_y = 0;
}

static void	init_south(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plan_x = FOV_INVERS;
	player->plan_y = 0;
}

static void	init_east(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plan_x = 0;
	player->plan_y = FOV;
}

static void	init_west(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plan_x = 0;
	player->plan_y = FOV_INVERS;
}

void	init_player(t_player *player, double start_x, double start_y, char start)
{
	player->pos_x = start_x;
	player->pos_y = start_y;

	player->move_speed = 0.2;//spped player
	player->rot_speed = 0.2; //speed of the player
=======

	if (start == 'N')
		init_north(player);
	else if (start == 'S')
		init_south(player);
	else if (start == 'E')
		init_east(player);
	else if (start == 'W')
		init_west(player);
}


void	find_player(t_game *game, double *start_x, double *start_y, char *start_dir)
{
	int	y;
	int	x;

	y = 0;
    while (y < game->map.map_height)
    {
		x = 0;
        while (x < game->map.map_width)
        {
            char c = game->map.map[y][x];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                *start_x = x + 0.5;
                *start_y = y + 0.5;
                *start_dir = c;
                game->map.map[y][x] = '0';
                return;
            }
			x++;
        }
		y++;
    }
    error_function("Error: no player start found in map");
}