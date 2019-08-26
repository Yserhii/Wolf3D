/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:25:37 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/14 15:06:35 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_len_u(unsigned long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n && ++i)
		n /= 10;
	return (i);
}

static void				ft_write_u_str(char *tmp, int len,
												unsigned long long int n)
{
	while (n && (tmp[--len] = n % 10 + '0'))
		n /= 10;
	while (len > 0)
		(tmp[--len] = '0');
}

static void				ft_write_u_prin(t_mcon *mcon, char *tmp, int len)
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
	mcon->point = ft_strjoin(mcon->point, tmp);
}

void					ft_write_u(t_mcon *mcon, unsigned long long n)
{
	char	*tmp;
	int		len;

	len = ft_len_u(n);
	while (mcon->num_prec > len && len++)
		mcon->fl->zero = 0;
	tmp = ft_strnew(len);
	ft_write_u_str(tmp, len, n);
	ft_write_u_prin(mcon, tmp, len);
	free(tmp);
}
