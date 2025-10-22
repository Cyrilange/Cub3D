#include "cub3D.h"


// Converts a string like "220,100,0" into a 32-bit RGBA color value.
unsigned int parse_color(char *s)
{
    char *trim;
    char **split;
    int rgb[3];
    unsigned int color;
    int i;

    trim = ft_strtrim(s, " \t\n");
    split = ft_split(trim, ',');
    free(trim);

    // Convert each component (R, G, B) to integer
    rgb[0] = ft_atoi(split[0]);
    rgb[1] = ft_atoi(split[1]);
    rgb[2] = ft_atoi(split[2]);

    // Pack R, G, B into a single 32-bit integer with full alpha
    color = ((unsigned int)rgb[0] << 24)
          | ((unsigned int)rgb[1] << 16)
          | ((unsigned int)rgb[2] << 8)
          | 0xFF;

    // Free temporary memory
    i = -1;
    while (split[++i])
        free(split[i]);
    free(split);

    return (color);
}


// Loads all textures (NO, SO, EA, WE) from file paths.
void load_textures(t_game *game)
{
	game->texture.no = mlx_load_png(game->texture.no_path);
	game->texture.so = mlx_load_png(game->texture.so_path);
	game->texture.ea = mlx_load_png(game->texture.ea_path);
	game->texture.we = mlx_load_png(game->texture.we_path);

	// Error handling if any texture fails to load
	if (!game->texture.no || !game->texture.so || !game->texture.ea || !game->texture.we)
	{
		ft_putstr_fd("Error loading textures\n", 2);
		exit(EXIT_FAILURE);
	}
}


