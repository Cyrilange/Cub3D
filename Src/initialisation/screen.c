#include "cub3D.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		error_message("Error: Failed to initialize window\n");
	}
}

void	init_images(t_game *game)
{
	// Exemple pour charger une texture Nord :
	game->texture.no = mlx_load_png(game->texture.no_path);
	if (!game->texture.no)
		exit(1);
	mlx_image_t *north_img = mlx_texture_to_image(game->mlx, game->texture.no);
	if (!north_img)
		exit(1);
	mlx_image_to_window(game->mlx, north_img, 0, 0);
}
