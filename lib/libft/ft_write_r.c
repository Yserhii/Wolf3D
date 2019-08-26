/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:17:01 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/19 18:17:03 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_wri_non_pri_next(int c, char *tmp)
{
	if (c == 18 || c == 19)
		tmp = (c == 18 ? ft_strdup("dc2") : ft_strdup("dc3"));
	else if (c == 20 || c == 21)
		tmp = (c == 20 ? ft_strdup("dc4") : ft_strdup("nak"));
	else if (c == 22 || c == 21)
		tmp = (c == 22 ? ft_strdup("syn") : ft_strdup("etb"));
	else if (c == 24 || c == 25)
		tmp = (c == 24 ? ft_strdup("can") : ft_strdup("em"));
	else if (c == 26 || c == 27)
		tmp = (c == 26 ? ft_strdup("sub") : ft_strdup("esc"));
	else if (c == 28 || c == 29)
		tmp = (c == 28 ? ft_strdup("fs") : ft_strdup("gs"));
	else if (c == 30 || c == 31)
		tmp = (c == 30 ? ft_strdup("rs") : ft_strdup("us"));
	return (tmp);
}

static char		*ft_wri_non_pri(int c)
{
	char	*tmp;

	tmp = NULL;
	if (c == 0 || c == 1)
		tmp = (c == 0 ? ft_strdup("nul") : ft_strdup("soh"));
	else if (c == 2 || c == 3)
		tmp = (c == 2 ? ft_strdup("stx") : ft_strdup("etx"));
	else if (c == 4 || c == 5)
		tmp = (c == 4 ? ft_strdup("eot") : ft_strdup("enq"));
	else if (c == 6 || c == 7)
		tmp = (c == 6 ? ft_strdup("ack") : ft_strdup("bel"));
	else if (c == 8 || c == 9)
		tmp = (c == 8 ? ft_strdup("bs") : ft_strdup("ht"));
	else if (c == 10 || c == 11)
		tmp = (c == 10 ? ft_strdup("nf") : ft_strdup("vt"));
	else if (c == 12 || c == 13)
		tmp = (c == 12 ? ft_strdup("bp") : ft_strdup("cr"));
	else if (c == 14 || c == 15)
		tmp = (c == 15 ? ft_strdup("so") : ft_strdup("si"));
	else if (c == 16 || c == 17)
		tmp = (c == 16 ? ft_strdup("dle") : ft_strdup("dc1"));
	else
		tmp = ft_wri_non_pri_next(c, tmp);
	return (tmp);
}

void			ft_write_r(t_mcon *mcon, int c)
{
	int		len;
	char	*tmp;

	tmp = ft_wri_non_pri(c);
	if (tmp == NULL)
		return ;
	len = mcon->width;
	if (mcon->fl->minus)
	{
		mcon->point = ft_strjoin(mcon->point, tmp);
		while (1 < len--)
			mcon->point = ft_strnjoin(mcon->point, " ", 1);
		free(tmp);
		return ;
	}
	else if (mcon->fl->zero)
		while (1 < len--)
			mcon->point = ft_strnjoin(mcon->point, "0", 1);
	else
		while (1 < len--)
			mcon->point = ft_strnjoin(mcon->point, " ", 1);
	mcon->point = ft_strjoin(mcon->point, tmp);
	free(tmp);
}
