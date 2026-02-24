/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:55:42 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/18 15:20:12 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render_scene(t_cub *cub)
{
	t_camera	*cam;
	int			x;

	cam = NULL;
	cam = malloc(sizeof(t_camera));
	cam->tex = NULL;
	cam->data = NULL;
	draw_floor_and_ceiling(cub);
	move_player(cub);
	x = 0;
	while (x < WIDTH)
	{
		init_cam_position(cub, cam, x);
		perform_dda(cub, cam);
		find_and_draw_wall(cub, cam, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img_ptr, 0, 0);
	free(cam);
	return (0);
}
