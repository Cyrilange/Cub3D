#include "cub3D.h"

void	error_function(const char *message)
{
	printf(RED"%s \n"RESET, message);
	exit(EXIT_FAILURE);
}

void	*check_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_function("Error: Memory allocation failed.");
	return (ptr);
}