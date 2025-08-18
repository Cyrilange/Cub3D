#define CUB3D_H
# ifdef CUB3D_H
//struc from struct.h
# include "struct.h"
//define for all the define parts
# include "define.h"
//minilbx
# include "MLX42/include/MLX42/MLX42.h"
//libft
# include "libft/libft.h"
//Math 
# include "math.h"
//initialisation
void	init_player(t_player *player, double start_x, double start_y, char start);
void	init_game(t_game *game);
void	init_textures(t_texture *textures);
void	init_images(t_game *game);
void	init_window(t_game *game);
//tools
void	*check_malloc(size_t size);
void	error_function(const char *message);

# endif
