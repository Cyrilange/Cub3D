#include "cub3D.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->map_height = 0;
	map->map_width = 0;
}
