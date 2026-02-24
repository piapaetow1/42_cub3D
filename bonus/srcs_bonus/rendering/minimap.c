/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:04:14 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/18 15:32:48 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_square(int x, int y, int color, t_cub **cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			ft_mlx_pixel_put((*cub), x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_player_on_map(t_cub *cub)
{
	int	px;
	int	py;
	int	dy;
	int	dx;

	px = cub->player->x * MINIMAP_SCALE;
	py = cub->player->y * MINIMAP_SCALE;
	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			ft_mlx_pixel_put(cub, px + dx, py + dy, 0x6B1610);
			dx++;
		}
		dy++;
	}
}

int	is_char_on_map(char c)
{
	if (c == '0' || c == 'W' || c == 'S' || c == 'N'
		|| c == 'E')
		return (1);
	return (0);
}

void	check_if_open(t_cub *cub, int x, int y)
{
	if (cub->doors_open == 1)
		draw_square(x * MINIMAP_SCALE, y * MINIMAP_SCALE, \
			0x9CB59E, &cub);
	else
		draw_square(x * MINIMAP_SCALE, y * MINIMAP_SCALE, \
			0x525E53, &cub);
}

void	draw_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->map_rows)
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '1')
				draw_square(x * MINIMAP_SCALE, y * MINIMAP_SCALE, \
					0x667668, &cub);
			else if (cub->map[y][x] == 'D')
				check_if_open(cub, x, y);
			else if (is_char_on_map(cub->map[y][x]) == 1)
				draw_square(x * MINIMAP_SCALE, y * MINIMAP_SCALE, \
					0x9CB59E, &cub);
			x++;
		}
		y++;
	}
	draw_player_fov(cub);
	draw_player_on_map(cub);
}
