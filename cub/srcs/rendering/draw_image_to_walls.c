/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image_to_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbohme <pbohme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:44:30 by pbohme            #+#    #+#             */
/*   Updated: 2025/08/21 10:40:20 by pbohme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_texture(t_cub *cub, t_camera *cam)
{
	if (cam->side == 0)
	{
		if (cam->ray_dir_x > 0)
			cam->tex = cub->textures.we;
		else
			cam->tex = cub->textures.ea;
	}
	else
	{
		if (cam->ray_dir_y > 0)
			cam->tex = cub->textures.no;
		else
			cam->tex = cub->textures.so;
	}
}

void	calculate_texture(t_cub *cub, t_camera *cam)
{
	cam->data = (mlx_get_data_addr(cam->tex, &(cam->tex_bpp), \
		&(cam->tex_size_line), &(cam->tex_endian)));
	if (cam->side == 0)
		cam->wall_x = cub->player->y + cam->perp_wall_dist * cam->ray_dir_y;
	else
		cam->wall_x = cub->player->x + cam->perp_wall_dist * cam->ray_dir_x;
	cam->wall_x -= floor_alt(cam->wall_x);
	cam->tex_width = cub->width;
	cam->tex_height = cub->height;
	cam->tex_x = (int)(cam->wall_x * (double)cam->tex_width);
	if ((cam->side == 0 && cam->ray_dir_x < 0) || (cam->side == 1 
			&& cam->ray_dir_y > 0))
		cam->tex_x = cam->tex_width - cam->tex_x -1;
	if (cam->tex_x < 0)
		cam->tex_x = 0;
	else if (cam->tex_x >= cam->tex_width)
		cam->tex_x = cam->tex_width - 1;
}

void	draw_vertical_lines(t_cub *cub, t_camera *cam, int x)
{
	int		y;
	int		d;
	int		offset;
	int		color;
	char	*dst;

	y = cam->draw_start;
	while (y < cam->draw_end)
	{
		d = y * 256 - HEIGHT * 128 + cam->line_height * 128;
		cam->tex_y = ((d * cam->tex_height) / cam->line_height) / 256;
		if (cam->tex_y < 0)
			cam->tex_y = 0;
		else if (cam->tex_y >= cam->tex_height)
			cam->tex_y = cam->tex_height - 1;
		offset = cam->tex_y * cam->tex_size_line + cam->tex_x * \
			(cam->tex_bpp / 8);
		color = *(int *)(cam->data + offset);
		dst = cub->img_data + (y * cub->size_line + x * (cub->bpp / 8));
		*(int *)dst = color;
		y++;
	}
}

void	draw_wall(t_cub *cub, t_camera *cam, int x)
{
	set_texture(cub, cam);
	calculate_texture(cub, cam);
	draw_vertical_lines(cub, cam, x);
}

void	find_and_draw_wall(t_cub *cub, t_camera *cam, int x)
{
	if (cam->side == 0)
		cam->perp_wall_dist = (cam->map_x - cub->player->x \
			+ (1 - cam->step_x) / 2) / cam->ray_dir_x;
	else
		cam->perp_wall_dist = (cam->map_y - cub->player->y \
			+ (1 - cam->step_y) / 2) / cam->ray_dir_y;
	cam->line_height = (int)(HEIGHT / (cam->perp_wall_dist));
	cam->draw_start = -(cam->line_height) / 2 + HEIGHT / 2;
	if (cam->draw_start < 0)
		cam->draw_start = 0;
	cam->draw_end = cam->line_height / 2 + HEIGHT / 2;
	if (cam->draw_end >= HEIGHT)
		cam->draw_end = HEIGHT -1;
	draw_wall(cub, cam, x);
}
