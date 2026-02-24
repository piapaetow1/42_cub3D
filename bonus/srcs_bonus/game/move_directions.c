/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:12:13 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/14 16:12:38 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	walk_door(char c, t_cub *cub)
{
	if (c == 'D' && cub->doors_open == 0)
		return (1);
	return (0);
}

void	move_forward(t_cub *cub, double mv_s)
{
	int	x;
	int	y;	
	int	new_x;
	int	new_y;

	x = (int)(cub->player->x);
	y = (int)(cub->player->y);
	new_x = (int)(cub->player->x + cub->player->dir_x * mv_s);
	new_y = (int)(cub->player->y + cub->player->dir_y * mv_s);
	if (cub->map[y][new_x] != '1' && walk_door(cub->map[y][new_x], cub) == 0)
		cub->player->x += cub->player->dir_x * mv_s;
	if (cub->map[new_y][x] != '1' && walk_door(cub->map[new_y][x], cub) == 0)
		cub->player->y += cub->player->dir_y * mv_s;
}

void	move_backward(t_cub *cub, double mv_s)
{
	int	x;
	int	y;	
	int	new_x;
	int	new_y;

	x = (int)(cub->player->x);
	y = (int)(cub->player->y);
	new_x = (int)(cub->player->x - cub->player->dir_x * mv_s);
	new_y = (int)(cub->player->y - cub->player->dir_y * mv_s);
	if (cub->map[y][new_x] != '1' && walk_door(cub->map[y][new_x], cub) == 0)
		cub->player->x -= cub->player->dir_x * mv_s;
	if (cub->map[new_y][x] != '1' && walk_door(cub->map[new_y][x], cub) == 0)
		cub->player->y -= cub->player->dir_y * mv_s;
}

void	move_right(t_cub *cub, double mv_s)
{
	int		new_x;
	int		new_y;
	double	right_x;
	double	right_y;

	right_x = cub->player->plane_x;
	right_y = cub->player->plane_y;
	new_x = (int)(cub->player->x + right_x * mv_s);
	new_y = (int)(cub->player->y + right_y * mv_s);
	if (cub->map[(int)(cub->player->y)][new_x] != '1')
		cub->player->x += right_x * mv_s;
	if (cub->map[new_y][(int)(cub->player->x)] != '1')
		cub->player->y += right_y * mv_s;
}

void	move_left(t_cub *cub, double mv_s)
{
	int		new_x;
	int		new_y;
	double	left_x;
	double	left_y;

	left_x = -cub->player->plane_x;
	left_y = -cub->player->plane_y;
	new_x = (int)(cub->player->x + left_x * mv_s);
	new_y = (int)(cub->player->y + left_y * mv_s);
	if (cub->map[(int)(cub->player->y)][new_x] != '1')
		cub->player->x += left_x * mv_s;
	if (cub->map[new_y][(int)(cub->player->x)] != '1')
		cub->player->y += left_y * mv_s;
}
