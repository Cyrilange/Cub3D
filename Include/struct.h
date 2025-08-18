
#ifndef STRUCT_H
#define STRUCT_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <memory.h>
# include <fcntl.h>
# include <MLX42/MLX42.h>


typedef struct s_texture
{
    mlx_texture_t 	*no;
	char			*no_path;
    mlx_texture_t 	*so;
	char			*so_path;
    mlx_texture_t 	*ea;
	char			*ea_path;
    mlx_texture_t 	*we;
	char			*we_path;
	unsigned int	ceilling;
	unsigned int	floor;

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
	char	start_dir;

}       t_player;

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
} t_map;


typedef struct s_game
{
	mlx_t		*mlx;
	void		*win;
	t_player	player;
	t_texture	texture;
	t_map		map;

} t_game;


# endif  
