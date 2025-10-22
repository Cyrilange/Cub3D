/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 16:39:43 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-26 16:39:43 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_textures(t_texture *textures)
{
	textures->no = NULL;
	textures->no_path = NULL;
	textures->so = NULL;
	textures->so_path = NULL;
	textures->ea = NULL;
	textures->ea_path = NULL;
	textures->we = NULL;
	textures->we_path = NULL;
	textures->ceilling = 0;
	textures->floor = 0;
}
