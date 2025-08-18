#include "cub3D.h"


unsigned int    parse_color(char *s)
{
    char        *trim;
    char        **split;
    int         rgb[3];
    unsigned int color;
    int         i;

    trim = ft_strtrim(s, " \t\n");
    split = ft_split(trim, ',');
    free(trim);
    rgb[0] = ft_atoi(split[0]); // R
    rgb[1] = ft_atoi(split[1]); // G
    rgb[2] = ft_atoi(split[2]); // B
    color = ((unsigned int)rgb[0] << 24)
          | ((unsigned int)rgb[1] << 16)
          | ((unsigned int)rgb[2] << 8)
          | 0xFF;
    i = -1;
    while (split[++i])
        free(split[i]);
    free(split);
    return (color);
}
