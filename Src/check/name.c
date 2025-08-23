#include "cub3D.h"

void check_name(char *file)
{
    int len;

    len = ft_strlen(file);
    if (len < 4 || ft_strncmp(&file[len - 4], ".cub", 4) != 0)
        error_function("Error: Invalid file name. Expected a .cub file\n");
}