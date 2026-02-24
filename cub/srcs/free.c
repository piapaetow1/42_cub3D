/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hreusing <hreusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:22:41 by hreusing          #+#    #+#             */
/*   Updated: 2025/07/04 17:57:15 by hreusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_map(t_cub *cub)
{
	free(cub->player);
	if (!cub || !cub->map)
		return ;
	if (cub->map)
		ft_free_array(cub->map);
	if (cub->config_lines)
		ft_free_array(cub->config_lines);
	if (cub->file_content)
		ft_free_array(cub->file_content);
	if (cub->map_fd >= 0)
		close(cub->map_fd);
	if (cub->textures.paths[0] || cub->textures.paths[1] 
		||cub->textures.paths[2] || cub->textures.paths[3])
		ft_free_textures(cub->textures.paths);
	if (cub->padded)
		ft_free_array(cub->padded);
}

void	ft_free_textures(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < 5)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
}

void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_error(char *message, t_cub *cub)
{
	ft_free_map(cub);
	free(cub);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_and_exit(char *message, t_cub *cub, char **array)
{
	ft_free_array(array);
	ft_error(message, cub);
}
