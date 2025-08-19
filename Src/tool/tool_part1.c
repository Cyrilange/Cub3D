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



void    free_game(t_game *game)
{
    if (game->texture.no)
        mlx_delete_texture(game->texture.no);
    if (game->texture.so)
        mlx_delete_texture(game->texture.so);
    if (game->texture.ea)
        mlx_delete_texture(game->texture.ea);
    if (game->texture.we)
        mlx_delete_texture(game->texture.we);
    if (game->map.map)
        {
            int i = 0;
            while (game->map.map[i])
            {
                free(game->map.map[i]);
                i++;
            }
            free(game->map.map);
        }
    
    if (game->img.img)
            mlx_delete_image(game->mlx, game->img.img);
}
