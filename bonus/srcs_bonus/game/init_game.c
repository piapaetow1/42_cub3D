/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:29:19 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/18 15:30:57 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == 119)
		cub->keys.w = 1;
	else if (keycode == 97)
		cub->keys.a = 1;
	else if (keycode == 115)
		cub->keys.s = 1;
	else if (keycode == 100)
		cub->keys.d = 1;
	else if (keycode == XK_Left)
		cub->keys.left = 1;
	else if (keycode == XK_Right)
		cub->keys.right = 1;
	else if (keycode == XK_Escape)
		ft_close_window(cub);
	else if (keycode == XK_Return || keycode == 65421)
	{
		cub->anim_active = 1;
		cub->anim_frame = 0;
	}
	else if (keycode == 32)
		door_opener(cub);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == 119)
		cub->keys.w = 0;
	else if (keycode == 97)
		cub->keys.a = 0;
	else if (keycode == 115)
		cub->keys.s = 0;
	else if (keycode == 100)
		cub->keys.d = 0;
	else if (keycode == XK_Left)
		cub->keys.left = 0;
	else if (keycode == XK_Right)
		cub->keys.right = 0;
	return (0);
}

void	init_game(t_cub **cub)
{
	init_player(*cub);
	(*cub)->mlx_ptr = mlx_init();
	if (!(*cub)->mlx_ptr)
	{
		ft_free_map(*cub);
		exit (1);
	}
	(*cub)->win_ptr = mlx_new_window((*cub)->mlx_ptr, WIDTH, HEIGHT, "CUBE");
	if (!(*cub)->win_ptr)
	{
		mlx_destroy_display((*cub)->mlx_ptr);
		free((*cub)->mlx_ptr);
		ft_free_map(*cub);
		exit (1);
	}
	ft_open_images(*cub);
	mlx_hook((*cub)->win_ptr, KeyPress, KeyPressMask, key_press, (*cub));
	mlx_hook((*cub)->win_ptr, KeyRelease, KeyReleaseMask, key_release, (*cub));
	mlx_mouse_hook((*cub)->win_ptr, mouse_move_hook, *cub);
	mlx_hook((*cub)->win_ptr, 17, 0, &ft_close_window, (*cub));
	(*cub)->img_ptr = mlx_new_image((*cub)->mlx_ptr, WIDTH, HEIGHT);
	(*cub)->img_data = mlx_get_data_addr((*cub)->img_ptr, &(*cub)->bpp, \
		&(*cub)->size_line, &(*cub)->endian);
	mlx_loop_hook((*cub)->mlx_ptr, &render_scene, *cub);
	mlx_loop((*cub)->mlx_ptr);
}
