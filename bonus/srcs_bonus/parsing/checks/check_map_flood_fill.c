/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_flood_fill.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:21:54 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/14 11:07:51 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	ft_flood_fill(t_cub *cub, char **visited, int x, int y)
{
	if (x < 0 || y < 0 || x >= cub->map_cols || y >= cub->map_rows)
		return ;
	if (visited[y][x])
		return ;
	if (cub->padded[y][x] == '1')
		return ;
	visited[y][x] = 1;
	ft_flood_fill(cub, visited, x + 1, y);
	ft_flood_fill(cub, visited, x - 1, y);
	ft_flood_fill(cub, visited, x, y + 1);
	ft_flood_fill(cub, visited, x, y - 1);
	ft_flood_fill(cub, visited, x + 1, y + 1);
	ft_flood_fill(cub, visited, x - 1, y - 1);
	ft_flood_fill(cub, visited, x + 1, y - 1);
	ft_flood_fill(cub, visited, x - 1, y + 1);
}

int	ft_check_visited(t_cub *cub, char **padded, char **visited)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->map_rows)
	{
		x = 0;
		while (x < cub->map_cols)
		{
			if (visited[y][x] && (padded[y][x] == '0' || padded[y][x] == 'N' ||
				padded[y][x] == 'S' || padded[y][x] == 'E' || 
				padded[y][x] == 'W'))
			{
				ft_free_array(visited);
				return (0);
			}
			x++;
		}
		y++;
	}
	y = 0;
	ft_free_array(visited);
	return (1);
}

void	ft_prep_flood_fill(t_cub *cub, char **visited)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++x < cub->map_cols)
	{
		ft_flood_fill(cub, visited, x, 0);
		ft_flood_fill(cub, visited, x, cub->map_rows - 1);
	}
	while (++y < cub->map_rows)
	{
		ft_flood_fill(cub, visited, 0, y);
		ft_flood_fill(cub, visited, cub->map_cols - 1, y);
	}
	if (!ft_check_visited(cub, cub->padded, visited))
		ft_error("Error: map is open\n", cub);
}
