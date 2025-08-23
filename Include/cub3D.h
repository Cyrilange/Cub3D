
#ifndef CUB3D_H
#define CUB3D_H
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
void    init_game_struct(t_game *game);
void	init_map(t_map *map);
void	init_textures(t_texture *textures);
void	init_images(t_game *game);
void	init_window(t_game *game);
void	init_ray(t_ray *ray, t_game *game, int x);
void    init_ray_step(t_ray *ray, t_game *game);
//tools
void	*check_malloc(size_t size);
void	error_function(const char *message);
void    free_game(t_game *game);
//parsing
void            parse_map_file(const char *filename, t_game *game);
unsigned int    parse_color(char *s);
void	        load_textures(t_game *game);
void	find_player(t_game *game, double *start_x, double *start_y, char *start_dir);
//3d
void	draw_ray_column(t_game *game, int x, t_ray *ray);
void	raycasting(t_game *game);
void	calc_ray_direction(t_player *player, int x, double *rayDirX, double *rayDirY);
uint32_t	get_texture_pixel(t_texture *tex, int tex_id, int x, int y);
void ft_put_pixel(t_game *game, int x, int y, uint32_t color);
//control
void    try_move(t_game *game, double dx, double dy);
void    move_forward(t_game *game);
void    move_backward(t_game *game);
void    rotate_left(t_player *player);
void    rotate_right(t_player *player);
void    handle_keypress(mlx_key_data_t keydata, void *param);
void move_left(t_game *game);
void move_right(t_game *game);
void game_loop(void *param);


# endif
