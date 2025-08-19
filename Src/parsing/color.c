#include "cub3D.h"


unsigned int    parse_color(char *s)
{
    char        *trim;
    char        **split;
    int         rgb[3];
    unsigned int color;
    int         i;

    trim = ft_strtrim(s, " \t\n");
    split = ft_split(trim, ',');
    free(trim);
    rgb[0] = ft_atoi(split[0]); // R
    rgb[1] = ft_atoi(split[1]); // G
    rgb[2] = ft_atoi(split[2]); // B
    color = ((unsigned int)rgb[0] << 24)
          | ((unsigned int)rgb[1] << 16)
          | ((unsigned int)rgb[2] << 8)
          | 0xFF;
    i = -1;
    while (split[++i])
        free(split[i]);
    free(split);
    return (color);
}

void	load_textures(t_game *game)
{
	game->texture.no = mlx_load_png(game->texture.no_path);
	game->texture.so = mlx_load_png(game->texture.so_path);
	game->texture.ea = mlx_load_png(game->texture.ea_path);
	game->texture.we = mlx_load_png(game->texture.we_path);
	if (!game->texture.no || !game->texture.so || !game->texture.ea || !game->texture.we)
	{
		ft_putstr_fd("Error loading textures\n", 2);
		exit(EXIT_FAILURE);
	}
    printf("NO texture: %p, SO: %p, EA: %p, WE: %p\n",
        game->texture.no, game->texture.so,
        game->texture.ea, game->texture.we);
 
}

