/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:51:02 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/21 10:41:32 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	load_door_tex(t_cub *cub)
{
	cub->textures.dor = mlx_xpm_file_to_image(cub->mlx_ptr, \
	cub->textures.paths[4], &cub->width, &cub->height);
	if (cub->textures.dor == NULL)
		return (1);
	return (0);
}

int	ft_load_assets_as_img(t_cub *cub)
{
	cub->textures.no[0] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	cub->textures.paths[0], &cub->width, &cub->height);
	if (cub->textures.no[0] == NULL)
		return (1);
	cub->textures.so[0] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	cub->textures.paths[1], &cub->width, &cub->height);
	if (cub->textures.so[0] == NULL)
		return (1);
	cub->textures.we[0] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	cub->textures.paths[2], &cub->width, &cub->height);
	if (cub->textures.we[0] == NULL)
		return (1);
	cub->textures.ea[0] = mlx_xpm_file_to_image(cub->mlx_ptr, \
	cub->textures.paths[3], &cub->width, &cub->height);
	if (cub->textures.ea[0] == NULL)
		return (1);
	if (cub->texture_count == 5)
	{
		if (load_door_tex(cub) == 1)
			return (1);
	}
	if (load_sprites(cub) == 1)
		return (printf("sprites failed\n"), 1);
	return (0);
}

void	ft_open_images(t_cub *cub)
{
	if (ft_load_assets_as_img(cub) == 1)
		ft_error("Error: failed to open xpm\n", cub);
}
