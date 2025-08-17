#define STRUCT_H
# ifdef STRUCT_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <memory.h>
# include <MLX42/MLX42.h>

typedef struct s_texture
{
    mlx_texture_t *NO;
    mlx_texture_t *SO;
    mlx_texture_t *EA;
    mlx_texture_t *WE;

}       t_texture;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
	double	move_speed;
	double	rot_speed;

}       t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	char		**map;
	int			map_width;
	int			map_height;
} t_game;


# endif  
