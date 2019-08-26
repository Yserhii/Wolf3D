/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:48:46 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/09 16:48:48 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

void	ft_error(int n)
{
	if (n == 1)
		ft_printf("No such file\n");
	else if (n == 2)
		ft_printf("usage: ./wolf3d [map_name.wolf]\n");
	else if (n == 3)
		ft_printf("Invalid map\n");
	else if (n == 4)
		ft_printf("Invalid map\n");
	else if (n == 5)
		ft_printf("Menu was delete, use ./wofl3d [map_name.wolf]\n");
	else if (n == 6)
		ft_printf("Map is greater 100 x 100\n");
	exit(0);
}

void	select_read_map(t_wolf *wolf)
{
	char	*tmp;
	char	*tmp_itoa;

	tmp = ft_strdup("./map/map_");
	tmp_itoa = ft_itoa(wolf->menu_index - 2);
	tmp = ft_strjoin(tmp, tmp_itoa);
	tmp = ft_strjoin(tmp, ".wolf");
	ft_strdel(&tmp_itoa);
	if ((wolf->fd = open(tmp, O_RDONLY)) < 1)
	{
		ft_strdel(&tmp);
		ft_error(3);
	}
	ft_strdel(&tmp);
	wolf->map_flag = 1;
}

int		main(int ac, char **av)
{
	int				fd;
	t_wolf			*wolf;

	if ((fd = open(av[1], O_RDONLY)) < 3)
	{
		menu();
		return (0);
	}
	if (ac != 2 || !(ft_strstr(av[1], ".wolf")))
		ft_error(2);
	wolf = ft_memalloc(sizeof(t_wolf));
	wolf->vect = ft_memalloc(sizeof(t_vect));
	read_map(fd, wolf);
	visual(wolf);
	return (0);
}
