/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:06:05 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/11 15:06:06 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

void		print_one_pixel(double x, double y, t_wolf *wolf)
{
	int i;

	if ((x >= 0 && x < WIN_WIDTH) && (y >= 0 && y < WIN_HEIGHT))
	{
		i = (y * WIN_WIDTH) + x;
		((t_color *)wolf->img->addr)[i].r = ((wolf->color >> 16) & 0xFF);
		((t_color *)wolf->img->addr)[i].g = ((wolf->color >> 8) & 0xFF);
		((t_color *)wolf->img->addr)[i].b = ((wolf->color) & 0xFF);
		if (wolf->beer == 1)
			((t_color *)wolf->img->addr)[i].a = 200;
	}
}

void		choose_wall_color(t_wolf *wolf)
{
	if (wolf->vis.side == 0 && wolf->vis.ray_dir_x > 0)
		wolf->color = wolf->map[wolf->vis.map_x][wolf->vis.map_y] < 4 ?
														0xff0000 : 0x00ff00;
	else if (wolf->vis.side == 0 && wolf->vis.ray_dir_x < 0)
		wolf->color = wolf->map[wolf->vis.map_x][wolf->vis.map_y] < 4 ?
														0xffff00 : 0x0000ff;
	else if (wolf->vis.side == 1 && wolf->vis.ray_dir_y > 0)
		wolf->color = wolf->map[wolf->vis.map_x][wolf->vis.map_y] < 4 ?
														0x00ffff : 0xffffff;
	else
		wolf->color = wolf->map[wolf->vis.map_x][wolf->vis.map_y] < 4 ?
														0xf0f0f0 : 0x0f0f0f;
	if (wolf->vis.side == 1)
		wolf->color = wolf->color / 2;
}
