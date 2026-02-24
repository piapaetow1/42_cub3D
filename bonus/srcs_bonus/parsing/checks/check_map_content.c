/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:39:15 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/21 10:46:55 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	ft_is_valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == 'S' || c == 'N' 
		|| c == 'W' || c == 'E' || c == 'D'
		|| ft_is_whitespace(c) || c == '\n');
}

void	ft_check_line_for_player(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_is_valid_map_char(line[i]))
			ft_error("Error: non map char present\n", cub);
		if (line[i] == 'S' || line[i] == 'N'\
			|| line[i] == 'W' || line[i] == 'E')
		{
			cub->player->player_start_view = line[i];
			cub->player_count++;
		}
		i++;
	}
}

char	*ft_check_line_for_whitespace(char *line)
{
	int		i;
	int		j;
	int		len;
	char	*new_line;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	new_line = malloc((len * 4 + 1) * sizeof(char));
	while (line[i])
	{
		if (line[i] == '\t')
		{
			new_line[j++] = ' ';
			new_line[j++] = ' ';
			new_line[j++] = ' ';
			new_line[j++] = ' ';
		}
		else
			new_line[j++] = line[i];
		i++;
	}
	new_line[j] = '\0';
	return (new_line);
}

int	ft_check_map_chars(t_cub *cub)
{
	int		i;
	char	*expanded;

	i = 0;
	while ((cub->map[i]))
	{
		ft_check_line_for_player(cub, cub->map[i]);
		expanded = ft_check_line_for_whitespace(cub->map[i]);
		free(cub->map[i]);
		cub->map[i] = expanded;
		i++;
	}
	if (cub->player_count == 0)
		ft_error("Error: no player in map\n", cub);
	else if (cub->player_count > 1)
		return (1);
	return (0);
}
