#include "cub3D.h"


int main(int argc, char **argv)
{
    t_game game;

    // Initialisation
    init_game_struct(&game);

    // Parsing
    if (argc != 2)
    {
        printf("Usage: %s <map.cub>\n", argv[0]);
        return 1;
    }
    parse_map_file(argv[1], &game);
    find_player(&game, &game.player.pos_x, &game.player.pos_y, &game.player.start_dir); //& because we give the address
    init_game(&game);
    // Création win
    init_window(&game);
    // Initialisation player, no the address so no &
    init_player(&game.player, game.player.pos_x, game.player.pos_y, game.player.start_dir);

    // principale while
    mlx_loop(game.mlx);

    // cleaning
    mlx_terminate(game.mlx);
    return 0;
}
