/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:56:57 by hreusing          #+#    #+#             */
/*   Updated: 2025/08/21 10:41:32 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_init_player(t_cub *cub)
{
	cub->player = malloc(sizeof(t_player));
	if (!cub->player)
		ft_error("Error: malloc failed for player\n", cub);
	cub->player->prev_mouse_x = WIDTH / 2;
}

void	ft_init_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 7)
		cub->textures.paths[i++] = NULL;
	i = 0;
	while (i < 3)
	{
		cub->textures.no[i] = NULL;
		cub->textures.so[i] = NULL;
		cub->textures.we[i] = NULL;
		cub->textures.ea[i] = NULL;
		i++;
	}
	cub->textures.dor = NULL;
	cub->textures.colors[0] = -1;
	cub->textures.colors[1] = -1;
}

void	ft_init_keys(t_cub *cub)
{
	cub->keys.w = 0;
	cub->keys.a = 0;
	cub->keys.s = 0;
	cub->keys.d = 0;
	cub->keys.left = 0;
	cub->keys.right = 0;
}

void	ft_init_cub(t_cub *cub)
{
	cub->mlx_ptr = NULL;
	cub->win_ptr = NULL;
	cub->img_ptr = NULL;
	cub->img_data = NULL;
	cub->config_lines = NULL;
	cub->map = NULL;
	cub->map_fd = -1;
	cub->file_line_count = 0;
	cub->map_rows = 0;
	cub->error = 0;
	cub->file_content = NULL;
	cub->texture_count = 0;
	cub->color_count = 0;
	cub->width = TILE_SIZE;
	cub->height = TILE_SIZE;
	cub->player_count = 0;
	cub->padded = NULL;
	cub->doors_open = 0;
	cub->anim_active = 0;
	cub->anim_frame = 0;
	cub->anim_frame_delay = 0;
	ft_init_textures(cub);
	ft_init_keys(cub);
	ft_init_player(cub);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = NULL;
	if (argc == 2)
	{
		cub = malloc(sizeof(t_cub));
		if (!cub)
		{
			perror("Error: allocating memory for cub");
			return (1);
		}
		ft_init_cub(cub);
		if (ft_get_map(argv[1], cub) == 1)
		{
			free(cub);
			exit(EXIT_FAILURE);
		}
		init_game(&cub);
		ft_free_map(cub);
	}
	else
		printf("Error: program needs two arguments\n");
	free(cub);
	return (0);
}

	// int i = 0;
	// 	while (cub->map[i])
	// 	{
	// 		printf("map:%s", cub->map[i]);
	// 		i++;
	// 	}