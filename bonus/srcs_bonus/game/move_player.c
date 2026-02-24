/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:00:40 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/18 15:32:09 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	player_turn(t_player *pl, int keycode)
{
	double	rot_s;
	double	old_plane_x;
	double	old_dir_x;

	rot_s = 0.01;
	if (keycode == XK_Right)
	{
		old_dir_x = pl->dir_x;
		pl->dir_x = pl->dir_x * cos(rot_s) - pl->dir_y * sin(rot_s);
		pl->dir_y = old_dir_x * sin(rot_s) + pl->dir_y * cos(rot_s);
		old_plane_x = pl->plane_x;
		pl->plane_x = pl->plane_x * cos(rot_s) - pl->plane_y * sin(rot_s);
		pl->plane_y = old_plane_x * sin(rot_s) + pl->plane_y * cos(rot_s);
	}
	else
	{
		old_dir_x = pl->dir_x;
		pl->dir_x = pl->dir_x * cos(-rot_s) - pl->dir_y * sin(-rot_s);
		pl->dir_y = old_dir_x * sin(-rot_s) + pl->dir_y * cos(-rot_s);
		old_plane_x = pl->plane_x;
		pl->plane_x = pl->plane_x * cos(-rot_s) - pl->plane_y * sin(-rot_s);
		pl->plane_y = old_plane_x * sin(-rot_s) + pl->plane_y * cos(-rot_s);
	}
}

void	move_player(t_cub *cub)
{
	double	move_speed;

	move_speed = 0.02;
	if (cub->keys.w)
		move_forward(cub, move_speed);
	if (cub->keys.s)
		move_backward(cub, move_speed);
	if (cub->keys.d)
		move_right(cub, move_speed);
	if (cub->keys.a)
		move_left(cub, move_speed);
	if (cub->keys.left)
		player_turn(cub->player, XK_Left);
	if (cub->keys.right)
		player_turn(cub->player, XK_Right);
}
