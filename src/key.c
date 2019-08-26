/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:49:52 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/09 16:49:54 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static int			x(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

static int			menu_select(t_wolf *wolf)
{
	if (wolf->menu_index == 1)
		wolf->menu_index = 3;
	else if (wolf->menu_index == 2)
		exit(1);
	else if (wolf->menu_index >= 3)
	{
		select_read_map(wolf);
		wolf->menu_index = 0;
	}
	else if (wolf->menu_index == 0)
	{
		if (wolf->map_flag == 0 &&
				((wolf->fd = open("./map/map_1.wolf", O_RDONLY)) < 1))
			ft_error(3);
		read_map(wolf->fd, wolf);
		visual(wolf);
		return (1);
	}
	return (0);
}

static int			esc(int keycode, t_wolf *wolf)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == MENU_DOWN)
	{
		wolf->menu_index++;
		if (wolf->menu_index == 3)
			wolf->menu_index = 0;
		else if (wolf->menu_index == 6)
			wolf->menu_index = 3;
	}
	else if (keycode == MENU_UP)
	{
		wolf->menu_index--;
		if (wolf->menu_index == -1)
			wolf->menu_index = 2;
		else if (wolf->menu_index == 2)
			wolf->menu_index = 5;
	}
	else if (keycode == MENU_SELECT)
		if (menu_select(wolf) == 1)
			return (0);
	mlx_put_image_to_window(wolf->img->mlx_ptr,
				wolf->img->mlx_win, wolf->menu[wolf->menu_index], 0, 0);
	return (0);
}

static int			mouse(int x, int y, t_wolf *wolf)
{
	(void)y;
	if (!wolf->menu_flag)
	{
		if (x > wolf->mouse_x)
			key(MOVE_RIGHT, wolf);
		else if (x < wolf->mouse_x)
			key(MOVE_LEFT, wolf);
		wolf->mouse_x = x;
	}
	return (0);
}

void				key_init(t_wolf *wolf)
{
	if (!wolf->menu_flag)
	{
		mlx_hook(wolf->img->mlx_win, 2, X_MASK, key, wolf);
		mlx_hook(wolf->img->mlx_win, 6, X_MASK, mouse, wolf);
		mlx_hook(wolf->img->mlx_win, 17, X_MASK, x, wolf);
	}
	else if (wolf->menu_flag)
	{
		mlx_hook(wolf->img->mlx_win, 2, X_MASK, esc, wolf);
		mlx_hook(wolf->img->mlx_win, 17, X_MASK, x, wolf);
	}
}
