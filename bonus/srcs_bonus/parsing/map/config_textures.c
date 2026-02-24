/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:21:58 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/14 11:09:13 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	ft_is_texture_code(char *line, int pos)
{
	if ((line[pos] == 'N' && line[pos + 1] == 'O')
		&& ft_is_whitespace(line[pos + 2]))
		return (0);
	else if ((line[pos] == 'S' && line[pos + 1] == 'O')
		&& ft_is_whitespace(line[pos + 2]))
		return (1);
	else if ((line[pos] == 'W' && line[pos + 1] == 'E')
		&& ft_is_whitespace(line[pos + 2]))
		return (2);
	else if ((line[pos] == 'E' && line[pos + 1] == 'A')
		&& ft_is_whitespace(line[pos + 2]))
		return (3);
	else if ((line[pos] == 'D' && line[pos + 1] == 'O')
		&& ft_is_whitespace(line[pos + 2]))
		return (4);
	return (-1);
}

int	ft_has_xpm_extension(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '.')
		{
			if (!(path[i + 1] == 'x' && path[i + 2] == 'p' \
			&& path[i + 3] == 'm' && !(path[i + 4])))
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_texture_exists(t_cub *cub, int code)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (i == code || !cub->textures.paths[i])
		{
			i++;
			continue ;
		}
		if (ft_strncmp(cub->textures.paths[i], cub->textures.paths[code], \
			ft_strlen(cub->textures.paths[code])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_find_texture(t_cub *cub, char *conf_line, int pos, int code)
{
	int	len;

	while (conf_line[pos] && ft_is_whitespace(conf_line[pos]))
		pos++;
	if (!conf_line[pos] || conf_line[pos] == '\n')
		ft_error("Error: texture path missing\n", cub);
	if (cub->textures.paths[code])
		return (1);
	cub->textures.paths[code] = ft_strdup(&conf_line[pos]);
	if (!cub->textures.paths[code])
		ft_error("Error: Memory allocation failed for texture path\n", cub);
	len = ft_strlen(cub->textures.paths[code]);
	while (len > 0 && (cub->textures.paths[code][len - 1] == '\n' 
		|| ft_is_whitespace(cub->textures.paths[code][len - 1])))
		cub->textures.paths[code][--len] = '\0';
	if (ft_is_dir(cub->textures.paths[code]))
		ft_error("Error: texture path is directory, not a file\n", cub);
	if (!ft_is_readable_file(cub->textures.paths[code], cub))
		ft_error("Error: texture path does not exist\n", cub);
	if (ft_has_xpm_extension(cub->textures.paths[code]))
		ft_error("Error: texture file has no .xpm extension\n", cub);
	if (ft_texture_exists(cub, code))
		ft_error("Error: texture path already exists\n", cub);
	cub->texture_count++;
	return (0);
}

int	ft_get_texture(t_cub *cub, char *conf_line)
{
	int	i;
	int	texture_code;

	i = 0;
	texture_code = -1;
	while (conf_line[i])
	{
		if (ft_is_whitespace(conf_line[i]))
		{
			i++;
			continue ;
		}
		texture_code = ft_is_texture_code(conf_line, i);
		if (texture_code >= 0)
		{
			if (cub->textures.paths[texture_code] != NULL)
				ft_error("Error: duplicate texture\n", cub);
			i += 3;
			if (ft_find_texture(cub, conf_line, i, texture_code))
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}
