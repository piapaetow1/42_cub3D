/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_holes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:32:04 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/14 11:07:59 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	ft_flood_check_hole(t_cub *cub, char **visited, int x, int y)
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
}

int	ft_check_internal_holes(t_cub *cub)
{
	int		x;
	int		y;
	char	**visited;

	y = 0;
	visited = ft_create_visited(cub, cub->map_cols);
	if (!visited)
		ft_error("Error: Memory allocation failed for visited\n", cub);
	while (y < cub->map_rows)
	{
		x = 0;
		while (x < cub->map_cols)
		{
			if (!visited[y][x] && cub->padded[y][x] == ' ')
				ft_flood_fill(cub, visited, x, y);
			x++;
		}
		y++;
	}
	if (!ft_check_visited(cub, cub->padded, visited))
		return (1);
	return (0);
}
