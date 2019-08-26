/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:12:13 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/14 15:12:21 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_len_o(unsigned long long int n, t_mcon *mcon)
{
	int		i;
	int		k;

	i = 0;
	k = (mcon->con == 'o' ? 8 : 2);
	if (n == 0)
		return (1);
	while (n && ++i)
		n /= k;
	return (i);
}

static void				ft_write_o_str(char *tmp, int len,
									unsigned long long int n, t_mcon *mcon)
{
	int		k;

	k = (mcon->con == 'o' ? 8 : 2);
	while (n && (tmp[--len] = n % k + '0'))
		n /= k;
	while (len > 0)
		(tmp[--len] = '0');
	if (mcon->fl->hesh > 0 && tmp[0] != '0' && (mcon->fl->hesh = 5))
		mcon->width--;
}

static void				ft_write_o_prin(t_mcon *mcon, char *tmp, int len)
{
	if (mcon->fl->precis && ft_strcmp(tmp, "0") == 0 && mcon->fl->hesh == 0)
	{
		tmp = "";
		len = 0;
	}
	if (mcon->fl->minus)
	{
		if (mcon->fl->hesh == 5)
			mcon->point = ft_strnjoin(mcon->point, "0", 1);
		mcon->point = ft_strjoin(mcon->point, tmp);
		while (len < mcon->width--)
			mcon->point = ft_strnjoin(mcon->point, " ", 1);
		return ;
	}
	if (mcon->fl->zero && mcon->fl->precis == 0)
		while (len < mcon->width--)
			mcon->point = ft_strnjoin(mcon->point, "0", 1);
	else
		while (len < mcon->width--)
			mcon->point = ft_strnjoin(mcon->point, " ", 1);
	if (mcon->fl->hesh == 5)
		mcon->point = ft_strnjoin(mcon->point, "0", 1);
	mcon->point = ft_strjoin(mcon->point, tmp);
}

void					ft_write_o(t_mcon *mcon, unsigned long long n)
{
	char	*tmp;
	int		len;

	len = ft_len_o(n, mcon);
	while (mcon->num_prec > len && len++)
		mcon->fl->zero = 0;
	tmp = ft_strnew(len);
	ft_write_o_str(tmp, len, n, mcon);
	ft_write_o_prin(mcon, tmp, len);
	free(tmp);
}
