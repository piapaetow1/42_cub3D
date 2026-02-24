/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:44:12 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/14 11:09:35 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	ft_create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	ft_parse_nbr(const char *line, int *i, int *rgb, int type_rg)
{
	if (!line[*i] || line[*i] == '\n')
		return (-1);
	while (ft_is_whitespace(line[*i]))
		(*i)++;
	*rgb = ft_atoi(&line[*i]);
	if (*rgb < 0 || *rgb > 255)
		return (-1);
	while (line[*i] && ft_isdigit(line[*i]))
		(*i)++;
	while (ft_is_whitespace(line[*i]))
		(*i)++;
	if (type_rg == 1 && line[*i] != ',')
		return (-1);
	else
		(*i)++;
	return (0);
}

// int ft_parse_rgb(const char *line, int *r, int *g, int *b)
// {
// 	int i = 0;
// 	while (ft_is_whitespace(line[i]) || line[i] == 'C' || line[i] == 'F')
// 		i++;
// 	*r = ft_atoi(&line[i]);
// 	while (line[i] && line[i] != ',') 
// 		i++;
// 	if (line[i++] != ',') 
// 		return (-1);
// 	*g = ft_atoi(&line[i]);
// 	while (line[i] && line[i] != ',') 
// 		i++;
// 	if (line[i++] != ',') 
// 		return (-1);
// 	*b = ft_atoi(&line[i]);
// 	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
// 		return (-1);
// 	return (0);
// }

int	ft_parse_rgb(const char *line, int *r, int *g, int *b)
{
	int	i;

	i = 0;
	while (ft_is_whitespace(line[i]) || line[i] == 'C' || line[i] == 'F')
		i++;
	if (ft_parse_nbr(line, &i, r, 1) == -1)
		return (-1);
	if (ft_parse_nbr(line, &i, g, 1) == -1)
		return (-1);
	if (ft_parse_nbr(line, &i, b, 0) == -1)
		return (-1);
	if (line[i] && line[i] != '\n')
		return (-1);
	return (0);
}
