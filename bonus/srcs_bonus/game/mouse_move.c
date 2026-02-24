/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 22:40:03 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/14 11:05:08 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	mouse_move_hook(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
		player_turn(cub->player, XK_Left);
	else if (button == 3)
		player_turn(cub->player, XK_Right);
	else if (button == 4)
		move_forward(cub, 0.1);
	else if (button == 5)
		move_backward(cub, 0.1);
	return (0);
}
