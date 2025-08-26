/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 16:39:57 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-26 16:39:57 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line/get_next_line_bonus.h"

static void add_line_to_map(t_map *map, char *line)
{
    int     h;
    char    **new_map;
    int     i;
    int     line_len;
    char    *trimmed_line;

    trimmed_line = ft_strtrim(line, " \t\n\r");
    if (!trimmed_line)
        return;  
    line_len = ft_strlen(trimmed_line);
    h = map->map_height;  
    new_map = check_malloc(sizeof(char *) * (h + 2));
    i = -1;
    while (++i < h)
        new_map[i] = map->map[i];    
    new_map[h] = ft_strdup(trimmed_line);
    new_map[h + 1] = NULL;  
    free(trimmed_line);
    free(map->map);  
    map->map = new_map;
    map->map_height++;  
    if (line_len > map->map_width)
        map->map_width = line_len;
}


static void assign_texture_path(char **destination, const char *line, int offset)
{
    char *path;
    
    path = ft_strtrim(line + offset, " \t\n");
    *destination = ft_strdup(path);
    free(path);
}

static void helper_map_line(t_game *game, char *line)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
        assign_texture_path(&game->texture.no_path, line, 3);
    else if (ft_strncmp(line, "SO ", 3) == 0)
        assign_texture_path(&game->texture.so_path, line, 3);
    else if (ft_strncmp(line, "EA ", 3) == 0)
        assign_texture_path(&game->texture.ea_path, line, 3);
    else if (ft_strncmp(line, "WE ", 3) == 0)
        assign_texture_path(&game->texture.we_path, line, 3);
    else if (line[0] == 'F')
        game->texture.floor = parse_color(line + 2);
    else if (line[0] == 'C')
        game->texture.ceilling = parse_color(line + 2);
    else if (line[0] == '1' || line[0] == '0' || line[0] == 'N' ||
             line[0] == 'S' || line[0] == 'E' || line[0] == 'W')
        add_line_to_map(&game->map, line);
}

void parse_map_file(const char *filename, t_game *game)
{
    int     fd;
    char    *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_function("Error : cannot open map file");
    line = get_next_line(fd);
    while (line)
    {
        helper_map_line(game, line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}