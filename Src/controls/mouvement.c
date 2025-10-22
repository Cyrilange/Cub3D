#include "cub3D.h"

// Attempts to move the player by (dx, dy) while checking for collisions.
void try_move(t_game *game, double dx, double dy)
{
    double newX;
    double newY;

    // Calculate the player's potential new position
    newX = game->player.pos_x + dx;
    newY = game->player.pos_y + dy;

    // Make sure the new position is still inside the map boundaries
    if (newX >= 0 && newX < game->map.map_width && 
        newY >= 0 && newY < game->map.map_height)
    {
        // Move along Y axis only if there's no wall ('0' means empty space)
        if (game->map.map[(int)newY][(int)game->player.pos_x] == '0')
            game->player.pos_y = newY;
        
        // Move along X axis only if there's no wall
        if (game->map.map[(int)game->player.pos_y][(int)newX] == '0')
            game->player.pos_x = newX;
    }
}


// Rotates the player's direction and camera plane by a given angle.
static void rotate_player(t_player *player, double angle)
{
    double oldDirX;
    double oldPlaneX;
    double cos_angle;
    double sin_angle;

    // Store current direction and plane before rotation
    oldDirX = player->dir_x;
    oldPlaneX = player->plan_x;

    // Precompute cosine and sine of the angle for efficiency
    cos_angle = cos(angle);
    sin_angle = sin(angle);

    // Apply rotation matrix to direction vector
    player->dir_x = player->dir_x * cos_angle - player->dir_y * sin_angle;
    player->dir_y = oldDirX * sin_angle + player->dir_y * cos_angle;

    // Apply the same rotation to the camera plane
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
