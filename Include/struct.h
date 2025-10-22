
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
# include "define.h"

// Represents a single ray in the raycasting process
typedef struct s_ray
{
	double	cameraX;        // Position of the ray on the camera plane (-1 to +1)
	double	rayDirX;        // Direction of the ray on the X axis
	double	rayDirY;        // Direction of the ray on the Y axis
	int		mapX;           // Current X position in the map grid
	int		mapY;           // Current Y position in the map grid
	double	sideDistX;      // Distance from player to next X side
	double	sideDistY;      // Distance from player to next Y side
	double	deltaDistX;     // Distance the ray has to travel to go from one X-side to the next
	double	deltaDistY;     // Distance the ray has to travel to go from one Y-side to the next
	double	wallX;          // Exact position of wall hit on the X axis
	double	wallY;          // Exact position of wall hit on the Y axis
	int		stepX;          // Direction of step on X (1 or -1)
	int		stepY;          // Direction of step on Y (1 or -1)
	int		hit;            // 1 if the ray hit a wall, 0 otherwise
	int		side;           // 0 if hit on X side, 1 if hit on Y side
	double	perpWallDist;   // Perpendicular distance to the wall
	int		lineHeight;     // Height of the wall line to draw
	int		drawStart;      // Start pixel position for drawing the wall
	int		drawEnd;        // End pixel position for drawing the wall
}	t_ray;



// Represents an image (texture or frame buffer)
typedef struct s_img
{
	mlx_image_t	*img;        // MLX image pointer
	int			img_width;   // Image width
	int			img_height;  // Image height
}	t_img;


// Holds all wall textures and floor/ceiling colors
typedef struct s_texture
{
    mlx_texture_t 	*no;        // North texture
	char			*no_path;   // Path to north texture file
    mlx_texture_t 	*so;        // South texture
	char			*so_path;   // Path to south texture file
    mlx_texture_t 	*ea;        // East texture
	char			*ea_path;   // Path to east texture file
    mlx_texture_t 	*we;        // West texture
	char			*we_path;   // Path to west texture file
	unsigned int	ceilling;   // Ceiling color (RGBA)
	unsigned int	floor;      // Floor color (RGBA)
} t_texture;


// Represents the player's position, direction, and camera plane
typedef struct s_player
{
	double	pos_x;        // Player position on X axis
	double	pos_y;        // Player position on Y axis
	double	dir_x;        // Player direction vector X
	double	dir_y;        // Player direction vector Y
	double	plan_x;       // Camera plane X (used for FOV)
	double	plan_y;       // Camera plane Y
	double	move_speed;   // Movement speed
	double	rot_speed;    // Rotation speed
	char	start_dir;    // Initial direction (N, S, E, W)
	t_ray	ray[WIN_WIDTH]; // Array of rays (one per column on screen)
} t_player;


// Represents the map grid
typedef struct s_map
{
	char	**map;          // 2D array representing the map
	int		map_width;      // Width of the map
	int		map_height;     // Height of the map
} t_map;



// Main game structure, holds everything
typedef struct s_game
{
	mlx_t		*mlx;        // MLX instance
	void		*win;        // Window pointer
	t_player	player;      // Player data
	t_texture	texture;     // Texture data
	t_map		map;         // Map data
	t_img		img;         // Frame buffer image
} t_game;



# endif  
