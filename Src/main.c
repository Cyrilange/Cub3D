#include "cub3D.h"

#include "cub3D.h"

int	main(int argc, char **argv)
{
    t_game	*game;

    init_game(&game);
    init_textures(&game->texture);
    check_game();
    init_player();
    start_game();
    free_game();
    return (0);
}