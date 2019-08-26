/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:26:16 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/13 14:26:18 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static inline void		print_with_text_add(t_wolf *wolf, int x, int y)
{
	int		d;
	int		tex;

	tex = wolf->vis.tex_num;
	if (wolf->vis.side == 0 && wolf->vis.ray_dir_x > 0)
		tex = wolf->vis.tex_num + (wolf->vis.tex_num < 4 ? 1 : -1);
	else if (wolf->vis.side == 0 && wolf->vis.ray_dir_x < 0)
		tex = wolf->vis.tex_num + (wolf->vis.tex_num < 4 ? 2 : -2);
	else if (wolf->vis.side == 1 && wolf->vis.ray_dir_y > 0)
		tex = wolf->vis.tex_num + (wolf->vis.tex_num < 4 ? 3 : -3);
	while (++y < wolf->vis.draw_end)
	{
		d = y * 256 - WIN_HEIGHT * 128 + wolf->vis.line_height * 128;
		wolf->vis.tex_y = ((d * wolf->img->h) / wolf->vis.line_height) / 256;
		if (wolf->texturs_addr[tex] != NULL)
			wolf->color = *(int *)(wolf->texturs_addr[tex] +
					((wolf->img->h * wolf->vis.tex_y + wolf->vis.tex_x) * 4));
		else
			choose_wall_color(wolf);
		if (wolf->vis.side == 1)
			wolf->color = (wolf->color >> 1) & 8355711;
		print_one_pixel(x, y, wolf);
	}
}

void					print_with_text(t_wolf *wolf, int x)
{
	wolf->vis.tex_num = wolf->map[wolf->vis.map_x][wolf->vis.map_y] - 1;
	if (wolf->vis.side == 0)
		wolf->vis.wall_x = wolf->vect->pos_y +
						wolf->vis.perp_wall_dist * wolf->vis.ray_dir_y;
	else
		wolf->vis.wall_x = wolf->vect->pos_x +
						wolf->vis.perp_wall_dist * wolf->vis.ray_dir_x;
	wolf->vis.wall_x -= floor((wolf->vis.wall_x));
	wolf->vis.tex_x = (int)(wolf->vis.wall_x * (double)wolf->img->w);
	if (wolf->vis.side == 0 && wolf->vis.ray_dir_x > 0)
		wolf->vis.tex_x = wolf->img->w - wolf->vis.tex_x - 1;
	if (wolf->vis.side == 1 && wolf->vis.ray_dir_y < 0)
		wolf->vis.tex_x = wolf->img->w - wolf->vis.tex_x - 1;
	print_with_text_add(wolf, x, wolf->vis.draw_start - 1);
}
