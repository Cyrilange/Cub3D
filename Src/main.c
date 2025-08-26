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

static char *call_cub(char  *map_path)
{
    // Définir le préfixe du chemin
    const char *prefix = "Include/";
    char *full_path;

    full_path = malloc(strlen(prefix) + ft_strlen(map_path) + 1);
    if (!full_path)
    {
        printf("Erreur: Échec de l'allocation mémoire pour le chemin de la carte.\n");
        return (NULL);
    }
    strcpy(full_path, prefix); //need to add this functions in lbft or in utils 
    strcat(full_path, map_path); //need to add this function  in utils or libft
    return (full_path);
}
// helper.c
static void init_graphics(t_game *game)
{
    load_textures(game);
    init_window(game);
    game->img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
    if (!game->img.img)
        error_function("Error: failed to create main image buffer");
    if (mlx_image_to_window(game->mlx, game->img.img, 0, 0) < 0)
        error_function("Error: failed to attach image buffer to window");
    raycasting(game);
}

int main(int argc, char **argv)
{
    t_game game;
    char *map_file_path;

    if (argc != 2)
        return (ft_putstr_fd("Usage: ./cub3D <map.cub>\n", 2), 1);

    map_file_path = call_cub(argv[1]);
    if (!map_file_path)
        return 1;
    check_name(map_file_path);
    init_game_struct(&game);
    parse_map_file(map_file_path, &game);
    free(map_file_path);
    find_player(&game, &game.player.pos_x, &game.player.pos_y, &game.player.start_dir);
    init_player(&game.player, game.player.pos_x, game.player.pos_y, game.player.start_dir);
    init_graphics(&game);
    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_loop(game.mlx);
    free_game(&game);
    return 0;
}
