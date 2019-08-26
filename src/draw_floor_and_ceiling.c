/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:26:34 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/13 14:26:36 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static inline void		print_floor_ceiling_add(t_wolf *wolf, int x, int y)
{
	while (++y < WIN_HEIGHT)
	{
		wolf->vis.current_dist = WIN_HEIGHT / (2.0 * y - WIN_HEIGHT);
		wolf->vis.weight = (wolf->vis.current_dist - wolf->vis.dist_player) /
								(wolf->vis.dist_wall - wolf->vis.dist_player);
		wolf->vis.current_floor_x = wolf->vis.weight * wolf->vis.floor_x_wall +
								(1.0 - wolf->vis.weight) * wolf->vect->pos_x;
		wolf->vis.current_floor_y = wolf->vis.weight * wolf->vis.floor_y_wall +
								(1.0 - wolf->vis.weight) * wolf->vect->pos_y;
		wolf->vis.floor_tex_x = (int)(wolf->vis.current_floor_x *
										wolf->img->w_cel) % wolf->img->w_cel;
		wolf->vis.floor_tex_y = (int)(wolf->vis.current_floor_y *
										wolf->img->h_cel) % wolf->img->h_cel;
		wolf->color = (wolf->texturs_addr[9] != NULL) ?
			((*(int *)(wolf->texturs_addr[9] + ((wolf->img->h_cel
			* wolf->vis.floor_tex_y + wolf->vis.floor_tex_x) * 4))) >> 1)
			& 8355711 : 0x75bbfd;
		print_one_pixel(x, y - 1, wolf);
		wolf->color = (wolf->texturs_addr[10] != NULL) ?
			*(int *)(wolf->texturs_addr[10] + ((wolf->img->h_cel
			* wolf->vis.floor_tex_y + wolf->vis.floor_tex_x) * 4)) : 0xf0db7d;
		print_one_pixel(x, WIN_HEIGHT - y - 1, wolf);
	}
}

void					print_floor_ceiling(t_wolf *wolf, int x)
{
	if (wolf->vis.side == 0 && wolf->vis.ray_dir_x > 0)
	{
		wolf->vis.floor_x_wall = wolf->vis.map_x;
		wolf->vis.floor_y_wall = wolf->vis.map_y + wolf->vis.wall_x;
	}
	else if (wolf->vis.side == 0 && wolf->vis.ray_dir_x < 0)
	{
		wolf->vis.floor_x_wall = wolf->vis.map_x + 1.0;
		wolf->vis.floor_y_wall = wolf->vis.map_y + wolf->vis.wall_x;
	}
	else if (wolf->vis.side == 1 && wolf->vis.ray_dir_y > 0)
	{
		wolf->vis.floor_x_wall = wolf->vis.map_x + wolf->vis.wall_x;
		wolf->vis.floor_y_wall = wolf->vis.map_y;
	}
	else
	{
		wolf->vis.floor_x_wall = wolf->vis.map_x + wolf->vis.wall_x;
		wolf->vis.floor_y_wall = wolf->vis.map_y + 1.0;
	}
	wolf->vis.dist_wall = wolf->vis.perp_wall_dist;
	wolf->vis.dist_player = 0.0;
	if (wolf->vis.draw_end < 0)
		wolf->vis.draw_end = WIN_HEIGHT;
	print_floor_ceiling_add(wolf, x, wolf->vis.draw_end);
}
