/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:11:32 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/21 10:40:20 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	load_north(t_cub *cub)
{
	cub->textures.no[1] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	"bonus/textures/north/one.xpm", &cub->width, &cub->height);
	if (cub->textures.no[1] == NULL)
		return (1);
	cub->textures.no[2] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	"bonus/textures/north/two.xpm", &cub->width, &cub->height);
	if (cub->textures.no[2] == NULL)
		return (1);
	return (0);
}

int	load_south(t_cub *cub)
{
	cub->textures.so[1] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	"bonus/textures/south/three.xpm", &cub->width, &cub->height);
	if (cub->textures.so[1] == NULL)
		return (1);
	cub->textures.so[2] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	"bonus/textures/south/four.xpm", &cub->width, &cub->height);
	if (cub->textures.so[2] == NULL)
		return (1);
	return (0);
}

int	load_east(t_cub *cub)
{
	cub->textures.ea[1] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	"bonus/textures/east/five.xpm", &cub->width, &cub->height);
	if (cub->textures.ea[1] == NULL)
		return (1);
	cub->textures.ea[2] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	"bonus/textures/east/six.xpm", &cub->width, &cub->height);
	if (cub->textures.ea[2] == NULL)
		return (1);
	return (0);
}

int	load_west(t_cub *cub)
{
	cub->textures.we[1] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	"bonus/textures/west/seven.xpm", &cub->width, &cub->height);
	if (cub->textures.we[1] == NULL)
		return (1);
	cub->textures.we[2] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	"bonus/textures/west/eight.xpm", &cub->width, &cub->height);
	if (cub->textures.we[2] == NULL)
		return (1);
	return (0);
}

int	load_sprites(t_cub *cub)
{
	if (load_north(cub) == 1 || load_east(cub) == 1
		|| load_west(cub) == 1 || load_south(cub) == 1)
		return (1);
	return (0);
}
