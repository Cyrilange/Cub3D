#include "cub3D.h"
#include "get_next_line/get_next_line_bonus.h"

/* Add a line to the map */
static void add_line_to_map(t_map *map, char *line)
{
    int     h;
    char    **new_map;
    int     i;

    h = map->map_height;
    new_map = check_malloc(sizeof(char *) * (h + 1));
    i = -1;
    while (++i < h)
        new_map[i] = map->map[i]; // Copy previous lines
    new_map[h] = ft_strdup(line); // Add new line
    if (map->map)
        free(map->map); // Free old map pointer
    map->map = new_map;
    map->map_height++;
    map->map_width = ft_strlen(line); // Assuming all lines same size
}
static void helper_map_line(t_game *game, char *line)
{
    char *path;

    if (ft_strncmp(line, "NO ", 3) == 0)
    {
        path = ft_strtrim(line + 3, " \t\n");
        game->texture.no_path = ft_strdup(path);
        free(path);
    }
    else if (ft_strncmp(line, "SO ", 3) == 0)
    {
        path = ft_strtrim(line + 3, " \t\n");
        game->texture.so_path = ft_strdup(path);
        free(path);
    }
    else if (ft_strncmp(line, "EA ", 3) == 0)
    {
        path = ft_strtrim(line + 3, " \t\n");
        game->texture.ea_path = ft_strdup(path);
        free(path);
    }
    else if (ft_strncmp(line, "WE ", 3) == 0)
    {
        path = ft_strtrim(line + 3, " \t\n");
        game->texture.we_path = ft_strdup(path);
        free(path);
    }
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
