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
				if (y == 0 || x == 0
					|| y == game->map.map_height - 1
					|| x == game->map.map_width - 1
					|| game->map.map[y - 1][x] == ' '
					|| game->map.map[y + 1][x] == ' '
					|| game->map.map[y][x - 1] == ' '
					|| game->map.map[y][x + 1] == ' ')
					error_function("Error: map not closed");
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