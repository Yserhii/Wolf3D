/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:03:42 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/11 15:03:43 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static inline t_img		*init_img(void)
{
	t_img	*img;

	img = ft_memalloc(sizeof(t_img));
	img->mlx_ptr = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx_ptr, WIN_WIDTH,
														WIN_HEIGHT, "WOLF3D");
	img->ptr = mlx_new_image(img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
												&img->size_line, &img->endian);
	return (img);
}

static inline void		read_textur(t_wolf *wolf)
{
	int		i;
	char	*tmp;
	char	*tmp_itoa;

	i = -1;
	while (++i < 11)
	{
		tmp = ft_strdup("./tex/");
		tmp_itoa = ft_itoa(i);
		tmp = ft_strjoin(tmp, tmp_itoa);
		tmp = ft_strjoin(tmp, ".xpm");
		if (i < 8)
			wolf->texturs[i] = mlx_xpm_file_to_image(wolf->img->mlx_ptr,
										tmp, &wolf->img->w, &wolf->img->h);
		else
			wolf->texturs[i] = mlx_xpm_file_to_image(wolf->img->mlx_ptr,
									tmp, &wolf->img->w_cel, &wolf->img->h_cel);
		if (wolf->texturs[i] != NULL)
			wolf->texturs_addr[i] = mlx_get_data_addr(wolf->texturs[i],
				&wolf->img->bpp, &wolf->img->size_line, &wolf->img->endian);
		ft_strdel(&tmp_itoa);
		ft_strdel(&tmp);
	}
}

void					visual(t_wolf *wolf)
{
	if (!wolf->menu_flag)
		wolf->img = init_img();
	wolf->vect->dir_x = -1;
	wolf->vect->dir_y = 0;
	wolf->vect->plane_x = 0;
	wolf->vect->plane_y = 0.66;
	wolf->vect->move_speed = 0.13 * 1;
	wolf->vect->turn_speed = 0.13 * 0.3;
	wolf->img->w = 64;
	wolf->img->h = 64;
	wolf->img->w_cel = 512;
	wolf->img->h_cel = 512;
	read_textur(wolf);
	draw(wolf);
	if (!wolf->menu_flag)
	{
		key_init(wolf);
		mlx_loop(wolf->img->mlx_ptr);
	}
	wolf->menu_flag = 0;
	key_init(wolf);
}
