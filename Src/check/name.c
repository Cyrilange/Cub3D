/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:10:12 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/27 15:01:14 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_wall(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			if (game->map.map[y][x] == '0')
			{
				if (y == 0 || x == 0 || y == game->map.map_height - 1
					|| x == game->map.map_width - 1 || game->map.map[y
						- 1][x] == ' ' || game->map.map[y + 1][x] == ' '
					|| game->map.map[y][x - 1] == ' ' || game->map.map[y][x
						+ 1] == ' ')
					g_error_function(game, "Error: map not closed");
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	check_name(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(&file[len - 4], ".cub", 4) != 0)
		error_function("Error: Invalid file name. Expected a .cub file\n");
}
