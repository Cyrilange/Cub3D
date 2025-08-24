#include "cub3D.h"

void	error_function(const char *message)
{
	printf(RED"%s \n"RESET, message);
	exit(EXIT_FAILURE);
}

void	*check_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_function("Error: Memory allocation failed.");
	return (ptr);
}



void free_game(t_game *game)
{
    int i;

    if (game->map.map)
    {
        i = -1;
        while (++i < game->map.map_height)
        {
            if (game->map.map[i])
                free(game->map.map[i]);
        }
        free(game->map.map);
        game->map.map = NULL;
    }
    if (game->texture.no_path)
        free(game->texture.no_path);
    if (game->texture.so_path)
        free(game->texture.so_path);
    if (game->texture.ea_path)
        free(game->texture.ea_path);
    if (game->texture.we_path)
        free(game->texture.we_path);
    if (game->texture.no)
        mlx_delete_texture(game->texture.no);
    if (game->texture.so)
        mlx_delete_texture(game->texture.so);
    if (game->texture.ea)
        mlx_delete_texture(game->texture.ea);
    if (game->texture.we)
        mlx_delete_texture(game->texture.we);
    if (game->img.img) mlx_delete_image(game->mlx, game->img.img);
    mlx_terminate(game->mlx);
}