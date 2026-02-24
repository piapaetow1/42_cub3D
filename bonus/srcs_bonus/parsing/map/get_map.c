/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:20:01 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/21 10:42:44 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	ft_is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(ft_is_whitespace(line[i]) || line[i] == '\0' || line[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	while (line[i])
	{
		if (!(line[i] == '0' || line[i] == '1'\
			||line[i] == 'N' || line[i] == 'S'\
			|| line[i] == 'E' || line[i] == 'W'\
			|| line[i] == ' ' || line[i] == '\t'\
			|| line[i] == '\n' || line[i] == 'D'))
			return (0);
		i++;
	}
	return (1);
}

// if (line[i] == '0' || line[i] == '1' ||
// 	line[i] == 'N' || line[i] == 'S' ||
// 	line[i] == 'E' || line[i] == 'W')
// 		has_map_char = 1;
// else if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
// 	return (0);

// int	ft_is_map_line(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
// 		i++;
// 	if (line[i] == '\0' || line[i] == '\n')
// 		return (0);
// 	while (line[i])
// 	{
// 		if (!(line[i] == '0' || line[i] == '1' ||
// 			  line[i] == 'N' || line[i] == 'S' ||
// 			  line[i] == 'E' || line[i] == 'W' ||
// 			  line[i] == ' ' || line[i] == '\t' ||
// 			  line[i] == '\n'))
// 			return (0);
// 		// if (line[i] == '0' || line[i] == '1' ||
// 		// 	line[i] == 'N' || line[i] == 'S' ||
// 		// 	line[i] == 'E' || line[i] == 'W')
// 		// 		has_map_char = 1;
// 		// else if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
// 		// 	return (0);
// 		i++;
// 	}
// 	return (1);
// }

void	ft_config_and_split_map(t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	while (cub->file_content[i] && !ft_is_map_line(cub->file_content[i]))
		i++;
	cub->config_lines = ft_calloc((i + 1), sizeof(char *));
	if (!cub->config_lines)
		ft_error("Error: Memory allocation failed for config lines\n", cub);
	j = -1;
	while (++j < i)
		cub->config_lines[j] = ft_strdup(cub->file_content[j]);
	cub->config_lines[j] = NULL;
	cub->map_rows = cub->file_line_count - i;
	cub->map = ft_calloc((cub->map_rows + 1), sizeof(char *));
	if (!cub->map)
		ft_error("Error: Memory allocation failed for map rows\n", cub);
	j = -1;
	while (++j < cub->map_rows)
		cub->map[j] = ft_strdup(cub->file_content[i + j]);
	cub->map[j] = NULL;
	ft_get_config(cub);
}

void	ft_fill_map_content(t_cub *cub, char *filename)
{
	int		i;

	cub->map_fd = open(filename, O_RDONLY);
	cub->file_content = malloc(sizeof(char *) * (cub->file_line_count + 1));
	if (!cub->file_content)
		ft_error("Error: Memory allocation failed for file content\n", cub);
	i = 0;
	while (i < cub->file_line_count)
		cub->file_content[i++] = get_next_line(cub->map_fd);
	cub->file_content[i] = NULL;
}

int	ft_get_map(char *filename, t_cub *cub)
{
	char	*line;

	if (ft_check_filename(filename) == 1)
		ft_error("Error: Programm accepts only .cub files\n", cub);
	cub->map_fd = open(filename, O_RDONLY);
	if (cub->map_fd == -1)
		ft_error("Error: map does not exist\n", cub);
	line = get_next_line(cub->map_fd);
	if (!line)
		ft_error("Error: file is empty\n", cub);
	cub->file_line_count = 1;
	while (line)
	{
		free(line);
		line = get_next_line(cub->map_fd);
		if (line)
			cub->file_line_count++;
	}
	close(cub->map_fd);
	ft_fill_map_content(cub, filename);
	ft_config_and_split_map(cub);
	free(line);
	ft_check_map(cub);
	return (0);
}
