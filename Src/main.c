#include "cub3D.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        ft_putstr_fd("Usage: ./cub3D <map.cub>\n", 2);
        return (1);
    }

    init_game_struct(&game);
    parse_map_file(argv[1], &game);
    init_window(&game);

    game.img.img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
    game.img.img_width = WIN_WIDTH;
    game.img.img_height = WIN_HEIGHT;

    raycasting(&game);
    mlx_image_to_window(game.mlx, game.img.img, 0, 0);

    mlx_key_hook(game.mlx, handle_keypress, &game);

    mlx_loop(game.mlx);
    mlx_terminate(game.mlx);
    return (0);
}



/*
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
*/