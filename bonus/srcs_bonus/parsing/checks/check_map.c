/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:32:54 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/14 11:08:28 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	ft_count_rows(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
	{
		if (ft_is_empty_line(cub->map[i]))
			break ;
		i++;
	}
	return (i);
}

int	ft_count_cols(t_cub *cub)
{
	int	i;
	int	j;
	int	len;
	int	max_len;

	i = 0;
	max_len = 0;
	while (cub->map[i])
	{
		len = 0;
		j = 0;
		while (ft_is_whitespace(cub->map[i][j]))
			j++;
		while (cub->map[i][j])
		{
			if (ft_is_whitespace(cub->map[i][j]))
				break ;
			len++;
			j++;
		}
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

int	ft_is_map_too_small(t_cub *cub)
{
	if (ft_count_rows(cub) < 3)
		return (1);
	if (ft_count_cols(cub) < 3)
		return (1);
	return (0);
}

void	ft_check_map(t_cub *cub)
{
	if (cub->map_rows == 0)
		ft_error("Error: map is missing\n", cub);
	if (ft_is_map_too_small(cub))
		ft_error("Error: map is too small\n", cub);
	if (ft_check_map_chars(cub))
		ft_error("Error: more than one player\n", cub);
	if (ft_check_map_lines(cub))
		ft_error("Error: invalid lines after map\n", cub);
	if (ft_check_walls(cub))
		ft_error("Error: Walls not closed\n", cub);
	if (ft_check_internal_holes(cub))
		ft_error("Error: map has open hole\n", cub);
}
