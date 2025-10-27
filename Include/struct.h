/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:10:01 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/27 15:18:18 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "define.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <limits.h>
# include <memory.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Linked list node to temporarily store lines while parsing the map
typedef struct s_line
{
	char			*content;	// The content of the line
	struct s_line	*next;		// Pointer to the next line
}					t_line;
//struct for the color RGB because of the norm
typedef struct s_rgb
{
	int	r; //red
	int	g; //green
	int	b; //blue
}	t_rgb;
// Structure storing raycasting-related
typedef struct s_ray
{
	double	camera_x;		// x-coordinate in camera space (-1 to 1)
	double	ray_dir_x;		// ray direction vector x
	double	ray_dir_y;		// ray direction vector y
	int		map_x;			// current x position in map grid
	int		map_y;			// current y position in map grid
	double	side_dist_x;	// distance to next x side
	double	side_dist_y;	// distance to next y side
	double	delta_dist_x;	// distance between two x intersections
	double	delta_dist_y;	// distance between two y intersections
	double	wall_x;			// exact hit position on wall (for texture)
	int		step_x;			// step direction on x axis (-1 or 1)
	int		step_y;			// step direction on y axis (-1 or 1)
	int		hit;			// flag: 1 if wall hit, 0 otherwise
	int		side;			// side of the wall hit (0=x, 1=y)
	double	perp_wall_dist;	// corrected perpendicular distance
	int		line_height;	// height of the wall slice on screen
	int		draw_start;		// start pixel for drawing the wall
	int		draw_end;		// end pixel for drawing the wall
	int		tx;				// texture x coordinate
	int		ty;				// texture y coordinate
	int		d;				// intermediate distance for texture calc
	int		idx;			// pixel index in texture buffer
}	t_ray;

// Wrapper for MLX image data (used as render buffer)
typedef struct s_img
{
	mlx_image_t		*img;			// MLX image pointer
	int				img_width;		// Image width
	int				img_height;		// Image height
}					t_img;
// Holds all texture resources and their RGB data
typedef struct s_texture
{
	mlx_texture_t	*no;			// North wall texture
	char			*no_path;		// Path to north texture file
	mlx_texture_t	*so;			// South wall texture
	char			*so_path;		// Path to south texture file
	mlx_texture_t	*ea;			// East wall texture
	char			*ea_path;		// Path to east texture file
	mlx_texture_t	*we;			// West wall texture
	char			*we_path;		// Path to west texture file
	unsigned int	ceilling;		// Ceiling color (RGB encoded)
	unsigned int	floor;			// Floor color (RGB encoded)
}					t_texture;
// Player info and precomputed rays for each screen column
typedef struct s_player
{
	double			pos_x;			// Player position X
	double			pos_y;			// Player position Y
	double			dir_x;			// Direction vector X
	double			dir_y;			// Direction vector Y
	double			plan_x;			// Camera plane X (for FOV)
	double			plan_y;			// Camera plane Y (for FOV)
	double			move_speed;		// Movement speed
	double			rot_speed;		// Rotation speed
	char			start_dir;		// Initial orientation (N, S, E, W)
	t_ray			ray[WIN_WIDTH];	// Ray data for each screen column
}					t_player;
// Map information and dimensions
typedef struct s_map
{
	char			**map;			// 2D array of map characters
	int				map_width;		// Map width (max line length)
	int				map_height;		// Map height (line count)
}					t_map;
// Main game structure containing everything
typedef struct s_game
{
	mlx_t			*mlx;			// MLX context pointer
	void			*win;			// window handle
	t_player		player;			// Player and ray info
	t_texture		texture;		// Texture data and colors
	t_map			map;			// Map data
	t_img			img;			// Main rendering image buffer
}					t_game;

#endif
