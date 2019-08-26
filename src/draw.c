/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:03:17 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/11 15:03:19 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static inline void		init_for_dda(t_wolf *wolf, int x)
{
	wolf->vis.camera_x = 2 * x / (double)WIN_WIDTH - 1;
	wolf->vis.ray_dir_x = wolf->vect->dir_x +
							wolf->vect->plane_x * wolf->vis.camera_x;
	wolf->vis.ray_dir_y = wolf->vect->dir_y +
							wolf->vect->plane_y * wolf->vis.camera_x;
	wolf->vis.map_x = (int)wolf->vect->pos_x;
	wolf->vis.map_y = (int)wolf->vect->pos_y;
	wolf->vis.delta_dist_x = fabs(1 / wolf->vis.ray_dir_x);
	wolf->vis.delta_dist_y = fabs(1 / wolf->vis.ray_dir_y);
	wolf->vis.hit = 0;
	if (wolf->vis.ray_dir_x < 0 && (wolf->vis.step_x = -1))
		wolf->vis.side_dist_x = (wolf->vect->pos_x - wolf->vis.map_x)
												* wolf->vis.delta_dist_x;
	else if ((wolf->vis.step_x = 1))
		wolf->vis.side_dist_x = (wolf->vis.map_x + 1.0 - wolf->vect->pos_x)
												* wolf->vis.delta_dist_x;
	if (wolf->vis.ray_dir_y < 0 && (wolf->vis.step_y = -1))
		wolf->vis.side_dist_y = (wolf->vect->pos_y - wolf->vis.map_y)
												* wolf->vis.delta_dist_y;
	else if ((wolf->vis.step_y = 1))
		wolf->vis.side_dist_y = (wolf->vis.map_y + 1.0 - wolf->vect->pos_y)
												* wolf->vis.delta_dist_y;
}

static inline void		dda(t_wolf *wolf)
{
	while (wolf->vis.hit == 0)
	{
		if (wolf->vis.side_dist_x < wolf->vis.side_dist_y)
		{
			wolf->vis.side_dist_x += wolf->vis.delta_dist_x;
			wolf->vis.map_x += wolf->vis.step_x;
			wolf->vis.side = 0;
		}
		else
		{
			wolf->vis.side_dist_y += wolf->vis.delta_dist_y;
			wolf->vis.map_y += wolf->vis.step_y;
			wolf->vis.side = 1;
		}
		if (wolf->map[wolf->vis.map_x][wolf->vis.map_y] > 0)
			wolf->vis.hit = 1;
	}
}

static inline void		calcul_star_end_point_and_draw_map(t_wolf *wolf, int x)
{
	if (wolf->vis.side == 0)
		wolf->vis.perp_wall_dist = (wolf->vis.map_x - wolf->vect->pos_x
					+ (1.0 - wolf->vis.step_x) / 2.0) / wolf->vis.ray_dir_x;
	else
		wolf->vis.perp_wall_dist = (wolf->vis.map_y - wolf->vect->pos_y +
						(1.0 - wolf->vis.step_y) / 2.0) / wolf->vis.ray_dir_y;
	wolf->vis.line_height = (int)(WIN_HEIGHT / wolf->vis.perp_wall_dist);
	wolf->vis.draw_start = -wolf->vis.line_height / 2.0 + WIN_HEIGHT / 2.0;
	if (wolf->vis.draw_start < 0)
		wolf->vis.draw_start = 0;
	wolf->vis.draw_end = wolf->vis.line_height / 2.0 + WIN_HEIGHT / 2.0;
	if (wolf->vis.draw_end >= WIN_HEIGHT)
		wolf->vis.draw_end = WIN_HEIGHT - 1.0;
	print_with_text(wolf, x);
	print_floor_ceiling(wolf, x);
}

void					draw(t_wolf *wolf)
{
	int		x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		init_for_dda(wolf, x);
		dda(wolf);
		calcul_star_end_point_and_draw_map(wolf, x);
	}
	mlx_put_image_to_window(wolf->img->mlx_ptr,
					wolf->img->mlx_win, wolf->img->ptr, 0, 0);
}
