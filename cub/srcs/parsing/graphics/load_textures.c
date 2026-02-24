/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:51:02 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/21 10:40:20 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_load_assets_as_img(t_cub *cub)
{
	cub->textures.no = mlx_xpm_file_to_image(cub->mlx_ptr, \
	cub->textures.paths[0], &cub->width, &cub->height);
	if (cub->textures.no == NULL)
		return (1);
	cub->textures.so = mlx_xpm_file_to_image(cub->mlx_ptr, \
	cub->textures.paths[1], &cub->width, &cub->height);
	if (cub->textures.so == NULL)
		return (1);
	cub->textures.we = mlx_xpm_file_to_image(cub->mlx_ptr, \
	cub->textures.paths[2], &cub->width, &cub->height);
	if (cub->textures.we == NULL)
		return (1);
	cub->textures.ea = mlx_xpm_file_to_image(cub->mlx_ptr, \
	cub->textures.paths[3], &cub->width, &cub->height);
	if (cub->textures.ea == NULL)
		return (1);
	return (0);
}

void	ft_open_images(t_cub *cub)
{
	if (ft_load_assets_as_img(cub) == 1)
		ft_error("Error: failed to open xpm\n", cub);
}
