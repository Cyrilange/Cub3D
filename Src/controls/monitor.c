#include "cub3D.h"

void handle_keypress(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_W)
            move_forward(game);
        else if (keydata.key == MLX_KEY_S)
            move_backward(game);
        else if (keydata.key == MLX_KEY_A)
            rotate_left(&game->player);
        else if (keydata.key == MLX_KEY_D)
            rotate_right(&game->player);

        raycasting(game);
        mlx_image_to_window(game->mlx, game->img.img, 0, 0);
    }
}
