#include "cub3D.h"

// Performs the Digital Differential Analyzer (DDA) algorithm
// to find where the ray hits a wall on the map grid.
static void perform_dda(t_game *game, t_ray *ray)
{
    while (!ray->hit)
    {
        // Check if ray is out of bounds to avoid infinite loop
        if (ray->mapX < 0 || ray->mapX >= game->map.map_width ||
            ray->mapY < 0 || ray->mapY >= game->map.map_height)
        {
            ray->hit = 1;
            break;
        }

        // Move to the next map square, in X or Y direction
        if (ray->sideDistX < ray->sideDistY)
        {
            ray->sideDistX += ray->deltaDistX;
            ray->mapX += ray->stepX;
            ray->side = 0; // Hit vertical wall
        }
        else
        {
            ray->sideDistY += ray->deltaDistY;
            ray->mapY += ray->stepY;
            ray->side = 1; // Hit horizontal wall
        }

        // Stop when we hit a wall block ('1')
        if (game->map.map[ray->mapY][ray->mapX] == '1')
            ray->hit = 1;
    }
}



// Calculates the perpendicular wall distance and height
// of the wall slice that will be drawn on the screen.
static void calc_wall_distance_and_height(t_player *player, t_ray *ray)
{
    // Compute perpendicular distance to avoid fisheye effect
    if (ray->side == 0)
        ray->perpWallDist = (ray->mapX - player->pos_x + (1 - ray->stepX) / 2) / ray->rayDirX;
    else
        ray->perpWallDist = (ray->mapY - player->pos_y + (1 - ray->stepY) / 2) / ray->rayDirY;

    // Calculate wall height based on distance
    ray->lineHeight = (int)(WIN_HEIGHT / ray->perpWallDist);

    // Determine start and end points of the wall line to draw
    ray->drawStart = -ray->lineHeight / 2 + WIN_HEIGHT / 2;
    if (ray->drawStart < 0)
        ray->drawStart = 0;

    ray->drawEnd = ray->lineHeight / 2 + WIN_HEIGHT / 2;
    if (ray->drawEnd >= WIN_HEIGHT)
        ray->drawEnd = WIN_HEIGHT - 1;
}

// Fills the top half of the screen with the ceiling color
// and the bottom half with the floor color.
static void draw_background(t_game *game)
{
    int x;
    int y;

    // Draw ceiling
    y = -1;
    while (++y < WIN_HEIGHT / 2)
    {
        x = -1;
        while (++x < WIN_WIDTH)
            ft_put_pixel(game, x, y, game->texture.ceilling);
    }

    // Draw floor
    y = WIN_HEIGHT / 2;
    while (y < WIN_HEIGHT)
    {
        x = -1;
        while (++x < WIN_WIDTH)
            ft_put_pixel(game, x, y, game->texture.floor);
        y++;
    }
}



// Main raycasting function — draws the entire 3D scene.
void raycasting(t_game *game)
{
    int x;
    t_ray ray;

    x = -1;
    draw_background(game); // Draw ceiling and floor before walls

    // For each vertical stripe on the screen
    while (++x < WIN_WIDTH)
    {
        // Initialize the ray based on player position and camera plane
        init_ray(&ray, game, x);

        // Initialize DDA step and distances
        init_ray_step(&ray, game);

        // Perform DDA algorithm to find wall collision
        perform_dda(game, &ray);

        // Calculate perpendicular wall distance and height
        calc_wall_distance_and_height(&game->player, &ray);

        // Draw the vertical wall slice
        draw_ray_column(game, x, &ray);
    }
}

