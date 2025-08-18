#include "cub3D.h"

static void add_line_to_map(t_map *map, char *line)
{
    int h;
    char **new_map;
    int i;

    i = -1;
    new_map = check_malloc(sizeof(char *) * (h + 1));
    h = map->map_height;
    while (++i < h)
        new_map[i] = map->map[i]; // past previous lines
    new_map[h] = strdup(line);   // add new lines
    if (map->map)
        free(map->map);
    map->map = new_map;
    map->map_height++;
    map->map_width = ft_strlen(line); // if all lines are same size
}


void parse_map_file(const char *filename, t_game *game)
{
    int     fd;
    char    *line;

    line = get_next_line(fd);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_function("Error : cannot open map file");
    while (line)
    {
        if (ft_strncmp(line, "NO ", 3) == 0)
            game->texture.no_path = ft_strdup(line + 3);
        else if (ft_strncmp(line, "SO ", 3) == 0)
            game->texture.so_path = ft_strdup(line + 3);
        else if (line[0] == 'F')
            game->texture.floor = parse_color(line + 2);
        else if (line[0] == 'C')
            game->texture.ceilling = parse_color(line + 2);
        else if (line[0] == '1' || line[0] == '0' || line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W')
            add_line_to_map(game, line);
        free(line);
    }
}