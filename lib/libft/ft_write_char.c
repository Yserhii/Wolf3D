/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:10:07 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/14 15:10:17 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_char_null(t_allstr *all, int len, t_mcon *mcon)
{
	char	c;

	c = (mcon->fl->zero > 0 ? '0' : ' ');
	if (mcon->fl->minus > 0)
	{
		ft_putstr_fd(all->allstr, all->fd);
		write(1, "\0", 1);
		all->count = ft_strlen_for_print(all->allstr) + 1;
		while (all->allstr != NULL && *all->allstr != '\0')
			*all->allstr = '\0';
		while (1 < len--)
			all->allstr = ft_strnjoin(all->allstr, &c, 1);
	}
	else
	{
		while (1 < len--)
			all->allstr = ft_strnjoin(all->allstr, &c, 1);
		ft_putstr_fd(all->allstr, all->fd);
		write(1, "\0", 1);
		all->count = ft_strlen_for_print(all->allstr) + 1;
		while (all->allstr != NULL && *all->allstr != '\0')
			*all->allstr = '\0';
	}
}

void		ft_write_char(t_mcon *mcon, char c, t_allstr *all)
{
	int		len;

	len = mcon->width;
	if (c == 0)
	{
		ft_write_char_null(all, len, mcon);
		return ;
	}
	if (mcon->fl->minus)
	{
		mcon->point = ft_strnjoin(mcon->point, &c, 1);
		while (1 < len--)
			mcon->point = ft_strnjoin(mcon->point, " ", 1);
		return ;
	}
	else if (mcon->fl->zero)
		while (1 < len--)
			mcon->point = ft_strnjoin(mcon->point, "0", 1);
	else
		while (1 < len--)
			mcon->point = ft_strnjoin(mcon->point, " ", 1);
	mcon->point = ft_strnjoin(mcon->point, &c, 1);
}
