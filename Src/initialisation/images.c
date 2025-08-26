/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 16:39:28 by csalamit          #+#    #+#             */
/*   Updated: 2025-08-26 16:39:28 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_image(t_game *game)
{
	game->img.img = NULL;
	game->img.img_width = 0;
	game->img.img_height = 0;
}
