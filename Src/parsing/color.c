/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:14:10 by csalamit          #+#    #+#             */
/*   Updated: 2025/10/27 12:19:53 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

static unsigned int	create_color(int r, int g, int b)
{
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	if (b > 255)
		b = 255;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

unsigned int	parse_color(char *s)
{
	int		r;
	int		g;
	int		b;
	char	**split;
	char	*trim;
	int		i;

	trim = ft_strtrim(s, " \t\n");
	split = ft_split(trim, ',');
	free(trim);
	if (!split || !split[0] || !split[1] || !split[2])
		error_function("Error: invalid color format");
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (create_color(r, g, b));
}


