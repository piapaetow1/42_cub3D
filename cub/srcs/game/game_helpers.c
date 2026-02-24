/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:29:48 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/21 10:40:20 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_floor_and_ceiling(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_mlx_pixel_put(cub, x, y, cub->textures.colors[1]);
			x++;
		}
		y++;
	}
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_mlx_pixel_put(cub, x, y, cub->textures.colors[0]);
			x++;
		}
		y++;
	}
}

int	floor_alt(double x)
{
	if (x >= 0)
		return ((int)x);
	else
		return ((int)(x - 1));
}

void	ft_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->img_data + (y * cub->size_line + x * (cub->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_close_window(t_cub *cub)
{
	mlx_destroy_image(cub->mlx_ptr, cub->textures.no);
	mlx_destroy_image(cub->mlx_ptr, cub->textures.so);
	mlx_destroy_image(cub->mlx_ptr, cub->textures.ea);
	mlx_destroy_image(cub->mlx_ptr, cub->textures.we);
	mlx_destroy_image(cub->mlx_ptr, cub->img_ptr);
	if (cub->win_ptr)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	mlx_destroy_display(cub->mlx_ptr);
	free(cub->mlx_ptr);
	ft_free_map(cub);
	free(cub);
	exit (0);
	return (0);
}

// int	ft_key_hook(int keycode, t_cub *cub)
// {
// 	if (keycode == XK_Escape)
// 	{
// 		ft_close_window(cub);
// 		cub->win_ptr = NULL;
// 		exit (0);
// 	}
// 	else if (keycode == XK_Left || keycode == XK_Right 
// 		|| keycode == 119 || keycode == 97
// 		|| keycode == 115 || keycode == 100)
// 		move_player (cub);
// 	return (0);
// }
