/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:14:29 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/14 15:14:37 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_len_p(unsigned long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n && ++i)
		n /= 16;
	return (i);
}

static void				ft_write_p_str(char *tmp, int len,
								unsigned long long int n, t_mcon *mcon)
{
	if (n == 0 && mcon->fl->precis < 1)
		tmp[0] = '0';
	while (n && (tmp[--len] = (n % 16) < 10 ? n % 16 + 48 : n % 16 + 'a' - 10))
		n /= 16;
	while (len > 0 && mcon->num_prec > 0)
		(tmp[--len] = '0');
}

static void				ft_write_p_prin(t_mcon *mcon, char *tmp, int len)
{
	if (ft_strlen(tmp) == 0 && mcon->fl->precis < 1)
		return ;
	mcon->width -= 2;
	if (mcon->fl->minus)
	{
		mcon->point = ft_strnjoin(mcon->point, "0x", 2);
		mcon->point = ft_strjoin(mcon->point, tmp);
		while (len < mcon->width--)
			mcon->point = ft_strnjoin(mcon->point, " ", 1);
		return ;
	}
	else if (mcon->fl->zero)
	{
		mcon->point = ft_strnjoin(mcon->point, "0x", 2);
		while (len < mcon->width--)
			mcon->point = ft_strnjoin(mcon->point, "0", 1);
	}
	else
	{
		while (len < mcon->width--)
			mcon->point = ft_strnjoin(mcon->point, " ", 1);
		mcon->point = ft_strnjoin(mcon->point, "0x", 2);
	}
	mcon->point = ft_strjoin(mcon->point, tmp);
}

void					ft_write_p(t_mcon *mcon, unsigned long long n)
{
	char	*tmp;
	int		len;

	len = ft_len_p(n);
	while (mcon->num_prec > len && len++)
		mcon->fl->zero = 0;
	tmp = ft_strnew(len);
	ft_write_p_str(tmp, len, n, mcon);
	ft_write_p_prin(mcon, tmp, len);
	free(tmp);
}
