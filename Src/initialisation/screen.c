#include "cub3D.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		error_message("Error: Failed to initialize window\n");
	}
}

static void	image_north(t_game *game)
{
    game->texture.no = mlx_load_png(game->texture.no_path);
    if (!game->texture.no)
        error_function("Error : north texture issue");
    mlx_image_t *no_img = mlx_texture_to_image(game->mlx, game->texture.no);
    if (!no_img)
        error_function("Error : north image issue");
    mlx_image_to_window(game->mlx, no_img, 0, 0);
}

static void	image_south(t_game *game)
{
    game->texture.so = mlx_load_png(game->texture.so_path);
    if (!game->texture.so)
        error_function("Error : south texture issue");
    mlx_image_t *so_img = mlx_texture_to_image(game->mlx, game->texture.so);
    if (!so_img)
        error_function("Error : south image issue");
    mlx_image_to_window(game->mlx, so_img, 100, 0);
}

static void	image_east(t_game *game)
{
    game->texture.ea = mlx_load_png(game->texture.ea_path);
    if (!game->texture.ea)
        error_function("Error : east texture issue");
    mlx_image_t *ea_img = mlx_texture_to_image(game->mlx, game->texture.ea);
    if (!ea_img)
        error_function("Error : east image issue");
    mlx_image_to_window(game->mlx, ea_img, 200, 0);
}

static void	image_west(t_game *game)
{
    game->texture.we = mlx_load_png(game->texture.we_path);
    if (!game->texture.we)
        error_function("Error : west texture issue");
    mlx_image_t *we_img = mlx_texture_to_image(game->mlx, game->texture.we);
    if (!we_img)
        error_function("Error : west image issue");
    mlx_image_to_window(game->mlx, we_img, 300, 0);
}

void	init_images(t_game *game)
{
	if (game->texture.no_path)
		image_north(game);
	if (game->texture.so_path)
		image_south(game);
    if (game->texture.ea_path)
		image_east(game);
    if (game->texture.we_path)
		image_west(game);
}