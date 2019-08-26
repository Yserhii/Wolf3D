/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:03:30 by yserhii           #+#    #+#             */
/*   Updated: 2019/07/11 15:03:32 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static void		valid_line_map(char *str, t_wolf *wolf)
{
	if (str == NULL || ft_strlen(str) == 0)
		ft_error(4);
	if (wolf->x_map == 0)
		wolf->x_map = ft_countword(str, ' ');
	else if (wolf->x_map != ft_countword(str, ' '))
		ft_error(4);
	(wolf->x_map > 100) ? ft_error(6) : 0;
	while (ft_strchr("0123456789", *str) && *str)
	{
		str++;
		if (str != '\0' && *str == ' ')
			str++;
		else
			break ;
	}
	if (*str != '\0')
		ft_error(4);
}

static void		write_to_arr(t_wolf *wolf, char **map)
{
	char	**tmp;
	int		y;
	int		x;

	y = -1;
	wolf->map = ft_memalloc(sizeof(int) * wolf->y_map);
	while (++y < wolf->y_map)
	{
		x = -1;
		wolf->map[y] = ft_memalloc(sizeof(int) * wolf->x_map);
		tmp = ft_strsplit(map[y], ' ');
		while (tmp[++x])
		{
			wolf->map[y][x] = ft_atoi(tmp[x]);
			if (wolf->map[y][x] == 0 && (y == 0 || x == 0 ||
					(x == wolf->x_map - 1) || (y == wolf->y_map - 1)))
				ft_error(4);
			if (wolf->map[y][x] == 0 && POS_X == 0 && POS_Y == 0)
			{
				POS_Y = (double)x + 0.5;
				POS_X = (double)y + 0.5;
			}
		}
		ft_arreydel(tmp);
	}
}

void			read_map(int fd, t_wolf *wolf)
{
	char	*line;
	char	*str;
	char	**map;
	int		res;

	str = NULL;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		wolf->y_map > 100 ? ft_error(6) : wolf->y_map++;
		valid_line_map(line, wolf);
		str = ft_strjoin(str, line);
		str = ft_strjoin(str, "\n");
		ft_strdel(&line);
	}
	wolf->y_map == 0 ? ft_error(4) : ft_strdel(&line);
	map = ft_strsplit(str, '\n');
	free(str);
	write_to_arr(wolf, map);
	if ((wolf->vect->pos_x || wolf->vect->pos_y) == 0)
		ft_error(4);
	ft_arreydel(map);
}
