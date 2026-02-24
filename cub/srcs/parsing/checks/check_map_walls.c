/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hreusing <hreusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:35:16 by hreusing          #+#    #+#             */
/*   Updated: 2025/07/04 17:54:07 by hreusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_create_padded_map(t_cub *cub, int max_len)
{
	int		i;
	int		j;

	cub->padded = malloc((cub->map_rows + 1) * sizeof(char *));
	i = -1;
	if (!cub->padded)
		ft_error("Error: Memory allocation failed for padded map\n", cub);
	while (++i < cub->map_rows)
	{
		cub->padded[i] = malloc((max_len + 1) * sizeof(char));
		if (!cub->padded[i])
			ft_error("Error: Memory allocation failed for padded row\n", cub);
		j = 0;
		while (cub->map[i][j])
		{
			cub->padded[i][j] = cub->map[i][j];
			j++;
		}
		while (j < max_len)
			cub->padded[i][j++] = ' ';
		cub->padded[i][j] = '\0';
	}
	cub->padded[cub->map_rows] = NULL;
}

char	**ft_create_visited(t_cub *cub, int max_len)
{
	char	**visited;
	int		i;

	i = 0;
	visited = malloc((cub->map_rows + 1) * sizeof(char *));
	if (!visited)
		ft_error("Error: Memory allocation failed for visited\n", cub);
	while (i < cub->map_rows)
	{
		visited[i] = calloc(max_len + 1, sizeof(char));
		if (!visited[i])
		{
			ft_free_array(visited);
			ft_error("Error: Memory allocation failed for visited row\n", cub);
		}
		i++;
	}
	visited[cub->map_rows] = NULL;
	return (visited);
}

int	ft_check_walls(t_cub *cub)
{
	int		max_len;
	int		len;
	int		i;
	char	**visited;

	max_len = 0;
	len = 0;
	i = 0;
	while (i < cub->map_rows)
	{
		len = ft_strlen(cub->map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	cub->map_cols = max_len;
	ft_create_padded_map(cub, max_len);
	visited = ft_create_visited(cub, max_len);
	ft_prep_flood_fill(cub, visited);
	return (0);
}

int	ft_check_map_lines(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		if (!ft_is_map_line(cub->map[i]))
			break ;
		i++;
	}
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (!ft_is_whitespace(cub->map[i][j]) && cub->map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
