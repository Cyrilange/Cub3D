#include "cub3D.h"

void try_move(t_game *game, double dx, double dy)
{
    double newX = game->player.pos_x + dx;
    double newY = game->player.pos_y + dy;

    if (game->map.map[(int)newY][(int)game->player.pos_x] == '0')
        game->player.pos_y = newY;
    if (game->map.map[(int)game->player.pos_y][(int)newX] == '0')
        game->player.pos_x = newX;
}

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

void rotate_left(t_player *player)
{
    double oldDirX = player->dir_x;
    player->dir_x = player->dir_x * cos(player->rot_speed) - player->dir_y * sin(player->rot_speed);
    player->dir_y = oldDirX * sin(player->rot_speed) + player->dir_y * cos(player->rot_speed);

    double oldPlaneX = player->plan_x;
    player->plan_x = player->plan_x * cos(player->rot_speed) - player->plan_y * sin(player->rot_speed);
    player->plan_y = oldPlaneX * sin(player->rot_speed) + player->plan_y * cos(player->rot_speed);
}

void rotate_right(t_player *player)
{
    double oldDirX = player->dir_x;
    player->dir_x = player->dir_x * cos(-player->rot_speed) - player->dir_y * sin(-player->rot_speed);
    player->dir_y = oldDirX * sin(-player->rot_speed) + player->dir_y * cos(-player->rot_speed);

    double oldPlaneX = player->plan_x;
    player->plan_x = player->plan_x * cos(-player->rot_speed) - player->plan_y * sin(-player->rot_speed);
    player->plan_y = oldPlaneX * sin(-player->rot_speed) + player->plan_y * cos(-player->rot_speed);
}
