/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:31:41 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/15 14:31:42 by yserhii          ###   ########.fr       */
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

void					open_tex_for_menu(t_wolf *wolf)
{
	int		i;
	char	*tmp;
	char	*tmp_itoa;

	i = -1;
	while (++i < 6)
	{
		tmp = ft_strdup("./menu/menu_");
		tmp_itoa = ft_itoa(i);
		tmp = ft_strjoin(tmp, tmp_itoa);
		ft_strdel(&tmp_itoa);
		tmp = ft_strjoin(tmp, ".xpm");
		wolf->menu[i] = mlx_xpm_file_to_image(wolf->img->mlx_ptr,
										tmp, &wolf->img->w, &wolf->img->h);
		if (wolf->menu[i] == NULL)
		{
			ft_strdel(&tmp);
			ft_error(5);
		}
		wolf->menu_addr[i] = mlx_get_data_addr(wolf->menu[i],
				&wolf->img->bpp, &wolf->img->size_line, &wolf->img->endian);
		ft_strdel(&tmp);
	}
}

void					menu(void)
{
	t_wolf	*wolf;

	wolf = ft_memalloc(sizeof(t_wolf));
	wolf->vect = ft_memalloc(sizeof(t_vect));
	wolf->img = init_img();
	wolf->menu_flag = 1;
	wolf->menu_index = 0;
	wolf->img->w_menu = 1080;
	wolf->img->h_menu = 1080;
	key_init(wolf);
	open_tex_for_menu(wolf);
	mlx_put_image_to_window(wolf->img->mlx_ptr,
				wolf->img->mlx_win, wolf->menu[wolf->menu_index], 0, 0);
	mlx_loop(wolf->img->mlx_ptr);
}
