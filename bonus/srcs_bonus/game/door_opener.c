/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:00:23 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/14 19:02:34 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	door_opener(t_cub *cub)
{
	int	px;
	int	py;	

	px = (int)cub->player->x;
	py = (int)cub->player->y;
	if (cub->map[py][px] == 'D' && cub->doors_open == 1)
		return ;
	if (cub->doors_open == 0)
		cub->doors_open = 1;
	else if (cub->doors_open == 1)
		cub->doors_open = 0;
}
