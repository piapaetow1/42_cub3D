/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:31:52 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/14 11:05:07 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	set_player_position(t_player *player, char c)
{
	if (c == 'N')
		player_nord(player);
	if (c == 'S')
		player_south(player);
	if (c == 'E')
		player_east(player);
	if (c == 'W')
		player_west(player);
}

void	init_player(t_cub *cub)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' 
				|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				cub->player->x = j + 0.5;
				cub->player->y = i + 0.5;
				c = cub->map[i][j];
				break ;
			}
			j++;
		}
		i++;
	}
	set_player_position(cub->player, c);
}
