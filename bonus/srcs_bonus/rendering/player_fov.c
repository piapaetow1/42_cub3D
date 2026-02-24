/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:29:18 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/18 14:57:24 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	setup_fov(t_cub *cub, t_fov *fov)
{
	fov->start_angle = atan2(cub->player->dir_y, cub->player->dir_x) \
		- FOV_ANGLE / 2;
	fov->end_angle = fov->start_angle + FOV_ANGLE;
	fov->angle = fov->start_angle;
	fov->step = 0.005;
}

void	assign_rays(t_cub *cub, t_fov *fov, double dist)
{
	fov->ray_x = cub->player->x + cos(fov->angle) * dist;
	fov->ray_y = cub->player->y + sin(fov->angle) * dist;
	fov->map_x = (int)fov->ray_x;
	fov->map_y = (int)fov->ray_y;
}

int	check_wall_collision(t_cub *cub, t_fov *fov)
{
	if (fov->map_y < 0 || fov->map_y >= cub->map_rows || fov->map_x < 0 
		|| fov->map_x >= (int)strlen(cub->map[fov->map_y]))
		return (1);
	if (cub->map[fov->map_y][fov->map_x] == '1'
		|| (cub->map[fov->map_y][fov->map_x] == 'D' && cub->doors_open == 0)) 
		return (1);
	return (0);
}

void	draw_player_fov(t_cub *cub)
{
	t_fov	*fov;
	double	dist;

	fov = malloc(sizeof(t_fov));
	if (!fov)
	{
		ft_close_window(cub);
		return ;
	}
	setup_fov(cub, fov);
	while (fov->angle <= fov->end_angle)
	{
		dist = 0;
		while (dist < 10)
		{
			assign_rays(cub, fov, dist);
			if (check_wall_collision(cub, fov) == 1)
				break ;
			ft_mlx_pixel_put(cub, fov->ray_x * MINIMAP_SCALE, \
				fov->ray_y * MINIMAP_SCALE, 0xBDDBBF);
			dist += 0.02;
		}
		fov->angle += fov->step;
	}
	free(fov);
}
