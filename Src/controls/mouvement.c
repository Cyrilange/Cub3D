#include "cub3D.h"

void	try_move(t_game *game, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + dx;
	new_y = game->player.pos_y + dy;
	if (new_x >= 0 && new_x < game->map.map_width &&
		new_y >= 0 && new_y < game->map.map_height)
	{
		if (game->map.map[(int)new_y][(int)game->player.pos_x] == '0')
			game->player.pos_y = new_y;
		if (game->map.map[(int)game->player.pos_y][(int)new_x] == '0')
			game->player.pos_x = new_x;
	}
}

static void	rotate_player(t_player *player, double angle)
{
	double	oldDirX;
	double	oldPlaneX;
	double	cos_angle;
	double	sin_angle;

	oldDirX = player->dir_x;
	oldPlaneX = player->plan_x;
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	player->dir_x = player->dir_x * cos_angle - player->dir_y * sin_angle;
	player->dir_y = oldDirX * sin_angle + player->dir_y * cos_angle;
	player->plan_x = player->plan_x * cos_angle - player->plan_y * sin_angle;
	player->plan_y = oldPlaneX * sin_angle + player->plan_y * cos_angle;
}

void	rotate_left(t_player *player)
{
	rotate_player(player, player->rot_speed);
}

void	rotate_right(t_player *player)
{
	rotate_player(player, -player->rot_speed);
}
