/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:24:39 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/14 11:09:09 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	ft_is_area_code(char *line, int pos)
{
	if (line[pos] == 'F' && ft_is_whitespace(line[pos + 1]))
		return (0);
	else if (line[pos] == 'C' && ft_is_whitespace(line[pos + 1]))
		return (1);
	return (-1);
}

int	ft_find_color(t_cub *cub, char *conf_line, int pos, int code)
{
	int	r;
	int	g;
	int	b;

	while (conf_line[pos] && ft_is_whitespace(conf_line[pos]))
		pos++;
	r = -1;
	g = -1;
	b = -1;
	if (ft_parse_rgb(conf_line, &r, &g, &b) == -1)
		return (1);
	cub->textures.colors[code] = ft_create_rgb(r, g, b);
	cub->color_count++;
	return (0);
}

int	ft_get_color(t_cub *cub, char *conf_line)
{
	int	i;
	int	area_code;

	i = 0;
	area_code = -1;
	while (conf_line[i])
	{
		if (ft_is_whitespace(conf_line[i]))
			i++;
		area_code = ft_is_area_code(conf_line, i);
		if (area_code >= 0)
		{
			if (cub->textures.colors[area_code] != -1)
				ft_error("Error: area color already exists\n", cub);
			i += 2;
			if (ft_find_color(cub, conf_line, i, area_code))
				ft_error("Error: Wrong rgb values\n", cub);
			return (0);
		}
		i++;
	}
	return (0);
}
