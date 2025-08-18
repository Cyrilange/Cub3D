#include "cub3D.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		error_function("Error: Failed to initialize window\n");
	}
}
static void load_and_display(t_game *game, char *path, mlx_texture_t **tex_ptr, int x)
{
    *tex_ptr = mlx_load_png(path);
    if (!*tex_ptr)
        error_function("Error: texture issue");
    mlx_image_t *img = mlx_texture_to_image(game->mlx, *tex_ptr);
    if (!img)
        error_function("Error: image issue");
    mlx_image_to_window(game->mlx, img, x, 0);
    *tex_ptr = NULL;
}

void init_images(t_game *game)
{
    if (game->texture.no_path)
        load_and_display(game, game->texture.no_path, &game->texture.no, 0);
    if (game->texture.so_path)
        load_and_display(game, game->texture.so_path, &game->texture.so, 100);
    if (game->texture.ea_path)
        load_and_display(game, game->texture.ea_path, &game->texture.ea, 200);
    if (game->texture.we_path)
        load_and_display(game, game->texture.we_path, &game->texture.we, 300);
}
