#include "cub3D.h"

static void check_name(char *file)
{
    int len;

    len = ft_strlen(file);
    if (len < 4 || ft_strncmp(&file[len - 4], ".cub", 4) != 0)
        error_function("Error: Invalid file name. Expected a .cub file\n");
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2) {
        ft_putstr_fd("Usage: ./cub3D <map.cub>\n", 2);
        return (1);
    }
    check_name(argv[1]);
    init_game_struct(&game);
    parse_map_file(argv[1], &game);
    find_player(&game, &game.player.pos_x, &game.player.pos_y, &game.player.start_dir);
    init_player(&game.player, game.player.pos_x, game.player.pos_y, game.player.start_dir);
    load_textures(&game);
    init_window(&game);
    game.img.img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
    if (!game.img.img) error_function("Error: failed to create main image buffer");
    if (mlx_image_to_window(game.mlx, game.img.img, 0, 0) < 0)
        error_function("Error: failed to attach image buffer to window");
    raycasting(&game);
    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_loop(game.mlx);
    free_game(&game);
    //mlx_terminate(game.mlx);
    return (0);
}
