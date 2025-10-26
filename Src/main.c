/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 16:40:17 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-26 16:40:17 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	find_player(t_game *g, double *s_x, double *s_y, char *start_dir)
{
	int		y;
	int		x;
	int		found;
	char	c;

	found = 0;
	y = -1;
	while (++y < g->map.map_height)
	{
		x = -1;
		while (++x < g->map.map_width)
		{
			c = g->map.map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (found++)
					error_function("Error: multiple player starts in map");
				*s_x = x + 0.5;
				*s_y = y + 0.5;
				*start_dir = c;
				g->map.map[y][x] = '0';
			}
		}
	}
	if (found == 0)
		error_function("Error: no player start found in map");
	}

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		error_function("Usage: ./cub3D <map.cub>");
	check_name(av[1]);
	init_game_struct(&g);
	parse_map_file(av[1], &g);
	check_wall(&g);
	find_player(&g, &g.player.pos_x, &g.player.pos_y, &g.player.start_dir);
	init_player(&g.player, g.player.pos_x, g.player.pos_y, g.player.start_dir);
	load_textures(&g);
	init_window(&g);
	g.img.img = mlx_new_image(g.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!g.img.img || mlx_image_to_window(g.mlx, g.img.img, 0, 0) < 0)
		error_function("Error: image buffer failed");
	raycasting(&g);
	mlx_loop_hook(g.mlx, game_loop, &g);
	mlx_loop(g.mlx);
	free_game(&g);
}
