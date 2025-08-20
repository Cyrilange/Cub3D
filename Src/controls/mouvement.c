#include "cub3D.h"

void try_move(t_game *game, double dx, double dy)
{
    double newX = game->player.pos_x + dx;
    double newY = game->player.pos_y + dy;
    if (newX >= 0 && newX < game->map.map_width && 
        newY >= 0 && newY < game->map.map_height)
    {
        if (game->map.map[(int)newY][(int)game->player.pos_x] == '0')
            game->player.pos_y = newY;
    
        if (game->map.map[(int)game->player.pos_y][(int)newX] == '0')
            game->player.pos_x = newX;
    }
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

static void rotate_player(t_player *player, double angle)
{
    double oldDirX = player->dir_x;
    double oldPlaneX = player->plan_x;
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    
    // Rotation du vecteur direction
    player->dir_x = player->dir_x * cos_angle - player->dir_y * sin_angle;
    player->dir_y = oldDirX * sin_angle + player->dir_y * cos_angle;
    
    // Rotation du plan de caméra
    player->plan_x = player->plan_x * cos_angle - player->plan_y * sin_angle;
    player->plan_y = oldPlaneX * sin_angle + player->plan_y * cos_angle;
}

void rotate_left(t_player *player)
{
    rotate_player(player, player->rot_speed);
}

void rotate_right(t_player *player)
{
    rotate_player(player, -player->rot_speed);
}
