/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 16:40:17 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-26 16:40:17 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

int main(int argc, char **argv)
{
    t_game game;
    char *map_file_path;

    if (argc != 2) {
        ft_putstr_fd("Usage: ./cub3D <map.cub>\n", 2);
        return (1);
    }

    map_file_path = argv[1];

    check_name(map_file_path);
    init_game_struct(&game);
    parse_map_file(map_file_path, &game);
    find_player(&game, &game.player.pos_x, &game.player.pos_y, &game.player.start_dir);
    init_player(&game.player, game.player.pos_x, game.player.pos_y, game.player.start_dir);
    load_textures(&game);
    init_window(&game);

    game.img.img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
    if (!game.img.img)
        error_function("Error: failed to create main image buffer");
    if (mlx_image_to_window(game.mlx, game.img.img, 0, 0) < 0)
        error_function("Error: failed to attach image buffer to window");

    raycasting(&game);
    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_loop(game.mlx);

    free_game(&game);
    return (0);
}
