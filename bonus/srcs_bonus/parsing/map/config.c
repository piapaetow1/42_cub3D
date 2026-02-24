/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:26:05 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/14 11:09:25 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	ft_get_config(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->config_lines[i])
	{
		if (ft_get_texture(cub, cub->config_lines[i]))
			ft_error("Error: wrong configuration\n", cub);
		if (ft_get_color(cub, cub->config_lines[i]))
			ft_error("Error: wrong rgb\n", cub);
		i++;
	}
	if (cub->texture_count == 0 && cub->color_count == 0)
		ft_error("Error: file has no (correct) configurations\n", cub);
	if (cub->texture_count == 0)
		ft_error("Error: file has no (correct) textures\n", cub);
	if (cub->color_count == 0)
		ft_error("Error: file has no (correct) colors\n", cub);
	if (cub->texture_count != 4 && cub->texture_count != 5)
		ft_error("Error: textures missing\n", cub);
	if (cub->color_count != 2)
		ft_error("Error: one color missing\n", cub);
}
