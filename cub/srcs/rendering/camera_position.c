/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:39:03 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/08 17:41:27 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_starting_distances(t_cub *cub, t_camera *cam)
{
	if (cam->ray_dir_x < 0)
	{
		cam->step_x = -1;
		cam->side_dist_x = (cub->player->x - cam->map_x) * cam->delta_dist_x;
	}
	else
	{
		cam->step_x = 1;
		cam->side_dist_x = (cam->map_x + 1.0 - cub->player->x) * \
			cam->delta_dist_x;
	}
	if (cam->ray_dir_y < 0)
	{
		cam->step_y = -1;
		cam->side_dist_y = (cub->player->y - cam->map_y) * cam->delta_dist_y;
	}
	else
	{
		cam->step_y = 1;
		cam->side_dist_y = (cam->map_y + 1.0 - cub->player->y) * \
			cam->delta_dist_y;
	}
}

void	init_cam_position(t_cub *cub, t_camera *cam, int x)
{
	cam->camera_x = 2 * x / (double)WIDTH -1;
	cam->ray_dir_x = cub->player->dir_x + cub->player->plane_x * cam->camera_x;
	cam->ray_dir_y = cub->player->dir_y + cub->player->plane_y * cam->camera_x;
	cam->map_x = (int)cub->player->x;
	cam->map_y = (int)cub->player->y;
	if (cam->ray_dir_x == 0)
		cam->delta_dist_x = 1e30;
	else
		cam->delta_dist_x = fabs(1 / cam->ray_dir_x);
	if (cam->ray_dir_y == 0)
		cam->delta_dist_y = 1e30;
	else
		cam->delta_dist_y = fabs(1 / cam->ray_dir_y);
	set_starting_distances(cub, cam);
}
