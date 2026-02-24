/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:28:18 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/21 10:42:44 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_is_readable_file(char *path, t_cub *cub)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: %s: %s\n", path, strerror(errno));
		ft_free_map(cub);
		free(cub);
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (1);
}

int	ft_check_filename(char	*filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			if (!(filename[i + 1] == 'c' && filename[i + 2] == 'u' \
			&& filename[i + 3] == 'b' && !(filename[i + 4])))
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (1);
}
