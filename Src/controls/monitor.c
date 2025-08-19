#include "cub3D.h"

void game_loop(void *param)
{
    t_game *game = (t_game *)param;

    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        move_forward(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        move_backward(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        rotate_left(&game->player);
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        rotate_right(&game->player);
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);

    raycasting(game);
    mlx_image_to_window(game->mlx, game->img.img, 0, 0);
}
