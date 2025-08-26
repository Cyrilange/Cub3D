/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 16:40:38 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-26 16:40:38 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_ray
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	wallX;
	double	wallY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	perpWallDist;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}	t_ray;


typedef struct s_img
{
	mlx_image_t	*img;
	int			img_width;
	int			img_height;
}	t_img;

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
	t_ray	ray[WIN_WIDTH];

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
	t_img		img; //image buffer

} t_game;


# endif  
