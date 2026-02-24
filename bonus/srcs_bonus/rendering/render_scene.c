/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:55:42 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/18 12:57:58 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	perform_anim(t_cub *cub)
{
	cub->anim_frame_delay++;
	if (cub->anim_frame != 0 && cub->anim_frame % 3 == 0)
		cub->anim_frame++;
	if (cub->anim_frame_delay >= 20)
	{
		cub->anim_frame++;
		cub->anim_frame_delay = 0;
		if (cub->anim_frame > 8)
		{
			cub->anim_active = 0;
			cub->anim_frame = 0;
		}
	}
}

int	render_scene(t_cub *cub)
{
	t_camera	*cam;
	int			x;

	cam = NULL;
	cam = malloc(sizeof(t_camera));
	cam->tex = NULL;
	cam->data = NULL;
	cam->is_door = 0;
	draw_floor_and_ceiling(cub);
	move_player(cub);
	if (cub->anim_active)
		perform_anim(cub);
	x = 0;
	while (x < WIDTH)
	{
		init_cam_position(cub, cam, x);
		perform_dda(cub, cam);
		find_and_draw_wall(cub, cam, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img_ptr, 0, 0);
	draw_map(cub);
	free(cam);
	return (0);
}
