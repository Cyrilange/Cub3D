/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:23:37 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/29 20:38:47 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_square(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			mlx_put_pixel(g->img.img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_cell(t_game *g, int x, int y, int offset_x)
{
	char	cell;
	int		color;

	cell = g->map.map[y][x];
	if (cell == '1')
		color = BLACK;
	else if (cell == '0' || cell == 'N' || cell == 'S'
		|| cell == 'E' || cell == 'W')
		color = WHITE;
	else
		return ;
	draw_square(g, x * MINIMAP_SCALE + offset_x,
		y * MINIMAP_SCALE + MINIMAP_OFFSET_Y, color);
}

static void	draw_minimap_player(t_game *g, int offset_x)
{
	int	px;
	int	py;

	px = g->player.pos_x * MINIMAP_SCALE + offset_x;
	py = g->player.pos_y * MINIMAP_SCALE + MINIMAP_OFFSET_Y;
	draw_square(g, px - 2, py - 2, RED_PLAYER);
}

void	draw_minimap(t_game *g)
{
	int	y;
	int	x;
	int	offset_x;

	offset_x = WIN_WIDTH - (g->map.map_width * MINIMAP_SCALE)
		- MINIMAP_MARGIN;
	y = -1;
	while (++y < g->map.map_height)
	{
		x = -1;
		while (++x < g->map.map_width && g->map.map[y][x] != '\0')
			draw_minimap_cell(g, x, y, offset_x);
	}
	draw_minimap_player(g, offset_x);
}
