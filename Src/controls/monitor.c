#include "cub3D.h"

void move_forward(t_game *game)
{
    try_move(game, game->player.dir_x * game->player.move_speed,
                    game->player.dir_y * game->player.move_speed);
}


void move_backward(t_game *game)
{
    try_move(game, -game->player.dir_x * game->player.move_speed,
                    -game->player.dir_y * game->player.move_speed);
}

void move_right(t_game *game)
{
    try_move(game, game->player.dir_y * game->player.move_speed,
                    game->player.dir_x * game->player.move_speed);
}

void move_left(t_game *game)
{
    try_move(game, -game->player.dir_y * game->player.move_speed,
                    -game->player.dir_x * game->player.move_speed);
}

void game_loop(void *param)
{
    t_game *game = (t_game *)param;

    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        move_forward(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        move_backward(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        move_right(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        move_left(game);
    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
        rotate_left(&game->player);
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
        rotate_right(&game->player);
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    raycasting(game);
    mlx_image_to_window(game->mlx, game->img.img, 0, 0);
}
