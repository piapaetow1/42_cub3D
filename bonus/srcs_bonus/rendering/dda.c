/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:42:11 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/14 17:38:46 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	is_door(t_camera *cam, int *hit)
{
	cam->is_door = 1;
	*hit = 1;
}

void	step_x(t_camera *cam)
{
	cam->side_dist_x += cam->delta_dist_x;
	cam->map_x += cam->step_x;
	cam->side = 0;
}

void	step_y(t_camera *cam)
{
	cam->side_dist_y += cam->delta_dist_y;
	cam->map_y += cam->step_y;
	cam->side = 1;
}

void	perform_dda(t_cub *cub, t_camera *cam)
{
	int	hit;

	cam->is_door = 0;
	hit = 0;
	while (hit == 0)
	{
		if (cam->side_dist_x < cam->side_dist_y)
			step_x(cam);
		else
			step_y(cam);
		if (cub->map[cam->map_y][cam->map_x] == '1')
			hit = 1;
		else if (cub->map[cam->map_y][cam->map_x] == 'D')
		{
			if (cub->doors_open == 0)
				is_door(cam, &hit);
		}
	}
}
