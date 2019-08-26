/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:15:29 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/23 13:15:31 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_norm_check_col(char *str, t_allstr *all)
{
	ft_strncmp(str, "{black}", 7) == 0 ?
						all->color = ft_strdup("\e[30m") : 0;
	ft_strncmp(str, "{red}", 5) == 0 ?
						all->color = ft_strdup("\e[31m") : 0;
	ft_strncmp(str, "{green}", 7) == 0 ?
						all->color = ft_strdup("\e[32m") : 0;
	ft_strncmp(str, "{yellow}", 8) == 0 ?
						all->color = ft_strdup("\e[33m") : 0;
	ft_strncmp(str, "{blue}", 6) == 0 ?
						all->color = ft_strdup("\e[34m") : 0;
	ft_strncmp(str, "{magenta}", 9) == 0 ?
						all->color = ft_strdup("\e[35m") : 0;
	ft_strncmp(str, "{cyan}", 6) == 0 ?
						all->color = ft_strdup("\e[36m") : 0;
	ft_strncmp(str, "{white}", 7) == 0 ?
						all->color = ft_strdup("\e[37m") : 0;
}

static char		*ft_norm_collor(char *str, t_allstr *all)
{
	int		i;

	i = 0;
	ft_norm_check_col(str, all);
	while (all->color != NULL && *str != '}' && (i = 1))
		str++;
	all->color != NULL ? str++ : 0;
	i > 0 ? all->allstr = ft_strnjoin(all->allstr, all->color, 5) : 0;
	i > 0 ? free(all->color) : 0;
	i > 0 ? all->color = NULL : 0;
	return (str);
}

char			*ft_collor(char *str, t_allstr *all)
{
	char	*point;

	point = str;
	if (ft_strncmp(str, "{eoc}", 5) == 0)
	{
		all->allstr = ft_strjoin(all->allstr, "\x1B[0m");
		return (str + 5);
	}
	else
		str = ft_norm_collor(str, all);
	if (str == point)
	{
		all->allstr = ft_strnjoin(all->allstr, str, 1);
		str++;
	}
	return (str);
}
