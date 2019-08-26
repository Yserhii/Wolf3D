/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:45:24 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/15 13:45:26 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static inline void		move_forward(t_wolf *wolf)
{
	ft_bzero(wolf->img->addr, WIN_HEIGHT * WIN_WIDTH * 4);
	if ((int)(POS_X + DIR_X * MOVE_SPEED) < wolf->y_map &&
			(int)(POS_X + DIR_X * MOVE_SPEED) >= 0 &&
			(int)POS_Y < wolf->x_map && (int)POS_Y >= 0 &&
			wolf->map[(int)(POS_X + DIR_X * MOVE_SPEED)][(int)POS_Y] == 0)
		POS_X += DIR_X * MOVE_SPEED;
	if ((int)POS_X < wolf->y_map && (int)POS_X >= 0 &&
			(int)(POS_Y + DIR_Y * MOVE_SPEED) < wolf->x_map &&
			(int)(POS_Y + DIR_Y * MOVE_SPEED) >= 0 &&
			wolf->map[(int)POS_X][(int)(POS_Y + DIR_Y * MOVE_SPEED)] == 0)
		POS_Y += DIR_Y * MOVE_SPEED;
	draw(wolf);
}

static inline void		move_backward(t_wolf *wolf)
{
	ft_bzero(wolf->img->addr, WIN_HEIGHT * WIN_WIDTH * 4);
	if ((int)(POS_X - DIR_X * MOVE_SPEED) < wolf->y_map &&
			(int)(POS_X - DIR_X * MOVE_SPEED) >= 0 &&
			(int)POS_Y < wolf->x_map && (int)POS_Y >= 0 &&
			wolf->map[(int)(POS_X - DIR_X * MOVE_SPEED)][(int)POS_Y] == 0)
		POS_X -= DIR_X * MOVE_SPEED;
	if ((int)POS_X < wolf->y_map && (int)POS_X >= 0 &&
			(int)(POS_Y - DIR_Y * MOVE_SPEED) < wolf->x_map &&
			(int)(POS_Y - DIR_Y * MOVE_SPEED) >= 0 &&
			wolf->map[(int)POS_X][(int)(POS_Y - DIR_Y * MOVE_SPEED)] == 0)
		POS_Y -= DIR_Y * MOVE_SPEED;
	draw(wolf);
}

static inline void		walking_right(t_wolf *wolf)
{
	ft_bzero(wolf->img->addr, WIN_HEIGHT * WIN_WIDTH * 4);
	if ((int)(POS_X + PLANE_X * MOVE_SPEED) < wolf->y_map &&
			(int)(POS_X + PLANE_X * MOVE_SPEED) >= 0 &&
			(int)POS_Y < wolf->x_map &&
			(int)POS_Y >= 0 &&
			wolf->map[(int)(POS_X + PLANE_X * MOVE_SPEED)][(int)POS_Y] == 0)
		POS_X += PLANE_X * MOVE_SPEED;
	if ((int)POS_X < wolf->y_map &&
			(int)POS_X >= 0 &&
			(int)(POS_Y + PLANE_Y * MOVE_SPEED) < wolf->x_map &&
			(int)(POS_Y + PLANE_Y * MOVE_SPEED) >= 0 &&
			wolf->map[(int)POS_X][(int)(POS_Y + PLANE_Y * MOVE_SPEED)] == 0)
		POS_Y += PLANE_Y * MOVE_SPEED;
	draw(wolf);
}

static inline void		walking_left(t_wolf *wolf)
{
	ft_bzero(wolf->img->addr, WIN_HEIGHT * WIN_WIDTH * 4);
	if ((int)(POS_X - PLANE_X * MOVE_SPEED) < wolf->y_map &&
			(int)(POS_X - PLANE_X * MOVE_SPEED) >= 0 &&
			(int)POS_Y < wolf->x_map &&
			(int)POS_Y >= 0 &&
			wolf->map[(int)(POS_X - PLANE_X * MOVE_SPEED)][(int)POS_Y] == 0)
		POS_X -= PLANE_X * MOVE_SPEED;
	if ((int)POS_X < wolf->y_map &&
			(int)POS_X >= 0 &&
			(int)(POS_Y - PLANE_Y * MOVE_SPEED) < wolf->x_map &&
			(int)(POS_Y - PLANE_Y * MOVE_SPEED) >= 0 &&
			wolf->map[(int)POS_X][(int)(POS_Y - PLANE_Y * MOVE_SPEED)] == 0)
		POS_Y -= PLANE_Y * MOVE_SPEED;
	draw(wolf);
}

int						key(int keycode, t_wolf *wolf)
{
	keycode == ESC ? exit(0) : 0;
	if (keycode == MOVE_SLOW)
		MOVE_SPEED = MOVE_SPEED == 0.13 ? 0.26 : 0.13;
	if (keycode == BEER)
		wolf->beer = wolf->beer == 0 ? 1 : 0;
	(keycode == MOVE_FORWARD || keycode == 13) ? move_forward(wolf) : 0;
	(keycode == MOVE_BACKWARD || keycode == 1) ? move_backward(wolf) : 0;
	keycode == WALKING_RIGTH ? walking_right(wolf) : 0;
	keycode == WALKING_LEFT ? walking_left(wolf) : 0;
	if (keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
	{
		wolf->vis.old_dir_x = DIR_X;
		wolf->vis.old_plane_x = PLANE_X;
		ft_bzero(wolf->img->addr, WIN_HEIGHT * WIN_WIDTH * 4);
		wolf->vis.turn = (keycode == MOVE_RIGHT || keycode == 2) ?
												-TURN_SPEED : TURN_SPEED;
		DIR_X = DIR_X * cos(wolf->vis.turn) - DIR_Y * sin(wolf->vis.turn);
		DIR_Y = wolf->vis.old_dir_x * sin(wolf->vis.turn) +
												DIR_Y * cos(wolf->vis.turn);
		PLANE_X = PLANE_X * cos(wolf->vis.turn) - PLANE_Y * sin(wolf->vis.turn);
		PLANE_Y = wolf->vis.old_plane_x * sin(wolf->vis.turn) +
												PLANE_Y * cos(wolf->vis.turn);
		draw(wolf);
	}
	return (0);
}
