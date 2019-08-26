/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:23:12 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/14 15:23:15 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_len_x(unsigned long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n && ++i)
		n /= 16;
	return (i);
}

static void				ft_write_x_str(char *tmp, int len,
									unsigned long long int n, t_mcon *mcon)
{
	char	l;
	int		check;

	check = 0;
	if (mcon->zeroinxo == 1)
		check = 1;
	l = (mcon->con == 'X' ? 'A' : 'a');
	n == 0 ? mcon->fl->hesh = 0 : 0;
	mcon->fl->hesh ? mcon->width -= 2 : 0;
	while (n && (tmp[--len] = (n % 16) < 10 ? n % 16 + '0' : n % 16 + l - 10))
		n /= 16;
	while (len > 0)
		(tmp[--len] = '0');
	if (mcon->zeroinxo != 1 && tmp[0] != '\0')
		check = 1;
	if (mcon->fl->hesh && (mcon->fl->zero || mcon->fl->minus) && check == 1)
	{
		mcon->point = (mcon->con == 'X' ? ft_strnjoin(mcon->point, "0X", 2) :
											ft_strnjoin(mcon->point, "0x", 2));
		mcon->fl->hesh = 0;
	}
}

static void				ft_write_x_prin(t_mcon *mcon, char *tmp, int len)
{
	if (mcon->fl->precis && ft_strcmp(tmp, "0") == 0)
	{
		tmp = "";
		len = 0;
	}
	if (mcon->fl->minus)
	{
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
	if (mcon->fl->hesh)
		mcon->point = (mcon->con == 'X' ? ft_strnjoin(mcon->point, "0X", 2) :
											ft_strnjoin(mcon->point, "0x", 2));
	mcon->point = ft_strjoin(mcon->point, tmp);
}

void					ft_write_x(t_mcon *mcon, unsigned long long n)
{
	char	*tmp;
	int		len;

	len = ft_len_x(n);
	while (mcon->num_prec > len && len++)
	{
		mcon->fl->zero = 0;
		mcon->zeroinxo = 1;
	}
	if (mcon->fl->hesh && mcon->fl->zero && mcon->fl->precis == 1)
	{
		mcon->fl->zero = 0;
		mcon->zeroinxo = 1;
	}
	tmp = ft_strnew(len);
	ft_write_x_str(tmp, len, n, mcon);
	ft_write_x_prin(mcon, tmp, len);
	free(tmp);
}
