/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:09:37 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/14 15:05:42 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				ft_check_di(t_mcon *mcon, long long n)
{
	if (n < 0)
		mcon->dsign = '-';
	else if (mcon->fl->plus)
		mcon->dsign = '+';
	else if (mcon->fl->space)
		mcon->dsign = ' ';
	if (mcon->fl->plus == 1 && mcon->fl->zero == 0 && mcon->fl->space == 0)
		mcon->width--;
	if (mcon->fl->plus == 0 && mcon->fl->zero == 0 && mcon->fl->space == 1)
		mcon->width--;
	if (n < 0 && mcon->fl->plus == 0 && mcon->fl->zero == 0 &&
														mcon->fl->space == 0)
		mcon->width--;
	if (mcon->fl->plus && mcon->fl->space && mcon->fl->zero < 1)
		mcon->width--;
}

static long long int	ft_len_di(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n && ++i)
		n /= 10;
	return (i);
}

static void				ft_write_di_str(char *tmp, int len, long long int n)
{
	unsigned long long int	num;
	int						neg;
	int						i;

	i = 0;
	neg = 1;
	if (n < 0)
		neg = -1;
	num = (unsigned long long int)(n *= neg);
	while (num && (tmp[--len] = num % 10 + '0'))
		num /= 10;
	while (len > 0)
		(tmp[--len] = '0');
}

static void				ft_write_di_prin(t_mcon *mcon, char *tmp, int len)
{
	if (mcon->fl->zero && mcon->dsign && (mcon->width--))
	{
		mcon->fl->precis == 0 ? mcon->point =
								ft_strjoin(mcon->point, &mcon->dsign) : 0;
		mcon->fl->precis == 0 ? mcon->dsign = 0 : 0;
	}
	if (mcon->fl->minus)
	{
		if (mcon->dsign)
			mcon->point = ft_strjoin(mcon->point, &mcon->dsign);
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
	if (mcon->dsign)
		mcon->point = ft_strjoin(mcon->point, &mcon->dsign);
	mcon->point = ft_strjoin(mcon->point, tmp);
}

void					ft_write_di(t_mcon *mcon, long long n)
{
	char	*tmp;
	int		len;

	len = ft_len_di(n);
	while (mcon->num_prec > len && len++)
		mcon->fl->zero = 0;
	ft_check_di(mcon, n);
	tmp = ft_strnew(len);
	ft_write_di_str(tmp, len, n);
	if (mcon->fl->precis && ft_strcmp(tmp, "0") == 0)
	{
		while (*tmp)
			*tmp = '\0';
		len = 0;
	}
	ft_write_di_prin(mcon, tmp, len);
	free(tmp);
}
