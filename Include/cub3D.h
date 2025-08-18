#define CUB3D_H
# ifdef CUB3D_H
//struc from struct.h
# include "struct.h"
//define for all the define parts
#include "define.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "math.h"
//initialisation
void	init_player(t_player *player, double start_x, double start_y, char start);
void	init_game(t_game *game);
void	init_textures(t_texture *textures);

# endif
