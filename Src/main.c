#include "cub3D.h"

#include "cub3D.h"

#include "cub3D.h"
/*
int main(void)
{
    t_game game;

    // initialisation
    init_game_struct(&game);
    init_map(&game.map);
    init_textures(&game.texture);
    // window mlx
    game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", false);
    if (!game.mlx)
    {
        error_message("Error: Failed to initialize window\n");
        return 1;
    }
    // path wall
    game.texture.no_path = "textures/nord.png";
    game.texture.so_path = "textures/sud.png";
    game.texture.ea_path = "textures/est.png";
    game.texture.we_path = "textures/ouest.png";
    // show images
    init_images(&game);
    // while mlx
    mlx_loop(game.mlx);
    // free all 
    mlx_terminate(game.mlx);
    return 0;
}
*/


//test main
#include "cub3D.h"

int main(void)
{
    t_game game;

    init_game_struct(&game);
    init_map(&game.map);
    init_textures(&game.texture);


    game.mlx = mlx_init(400, 100, "Test Images", false);
    if (!game.mlx)
        return (write(2, "Erreur MLX\n", 12), 1);

  
    game.texture.no_path = "textures/nord.png";
    game.texture.so_path = "textures/sud.png";
    game.texture.ea_path = "textures/est.png";
    game.texture.we_path = "textures/ouest.png";

 
    init_images(&game);

    mlx_loop(game.mlx);

   
    mlx_terminate(game.mlx);
    return 0;
}
