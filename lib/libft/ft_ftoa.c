/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:44:27 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/11 12:44:29 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_ftoa_zero(int len, char *tmp, int i, t_mcon *mcon)
{
	while (mcon->zerofload-- > 0)
		tmp[++i] = '0';
	len--;
	while (len-- >= 0)
		tmp[++i] = '0';
	return (tmp);
}

char			*ft_ftoa(long double n, t_mcon *mcon)
{
	int				len;
	int				i;
	char			*tmp;
	long double		ntmp;
	long double		delitel;

	i = 0;
	len = 1;
	delitel = 1;
	n < 0 ? n *= -1 : 0;
	ntmp = n;
	mcon->zerocheckminus ? i = 1 : 0;
	(mcon->fl->plus > 0 || mcon->fl->zero > 0) ? i = 0 : 0;
	while (ntmp >= 10 && (delitel *= 10) && (len++))
		ntmp /= 10;
	tmp = ft_strnew(len + i + mcon->zerocheck + mcon->zerofload);
	i == 1 ? tmp[0] = '-' : 0;
	i = (i == 1 ? 0 : -1);
	while (mcon->zerocheck > 0 && (tmp[++i] = '0'))
		mcon->zerocheck--;
	while (n >= 1 && (ntmp = n) && (ntmp /= delitel) &&
		(tmp[++i] = ((long long)ntmp % 10) + '0') && (--len) &&
								(n -= ((long long)ntmp * delitel)))
		delitel /= 10;
	return (ft_ftoa_zero(len, tmp, i, mcon));
}
