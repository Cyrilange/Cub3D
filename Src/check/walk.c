#include "cub3D.h"

int is_walkable(t_map *map, int x, int y)
{
    if (y < 0 || y >= map->map_height)
        return (0);
    if (x < 0 || x >= (int)ft_strlen(map->map[y]))
        return (0);
    return (map->map[y][x] == '0');
}


void	clamp_tex_coords(int *texX, int *texY, int tw, int th)
{
	if (*texX < 0)
		*texX = 0;
	else if (*texX >= tw)
		*texX = tw - 1;

	if (*texY < 0)
		*texY = 0;
	else if (*texY >= th)
		*texY = th - 1;
}