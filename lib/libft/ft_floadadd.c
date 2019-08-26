/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floadadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:10:32 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/15 15:10:33 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_len_f_add(long double k, long double n, t_mcon *mcon)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (k >= 1 && (++i))
		k /= 10;
	while (n >= 1 && (++j))
		n /= 10;
	if (i != j)
		mcon->precfload = 1;
}

long double		ft_len_f(long double n, int prec, t_mcon *mcon)
{
	int			i;
	int			j;
	int			neg;
	long double	k;

	neg = (n < 0 ? -1 : 1);
	n *= neg;
	i = -1;
	j = 0;
	k = n;
	while (k >= 1 && (++j))
		k /= 10;
	while (++i < prec && j++ <= 19)
	{
		if ((long long)n == 0 && mcon->num_prec > 0)
			mcon->zerocheck++;
		n *= 10;
	}
	while (++i <= prec + 1)
		mcon->zerofload++;
	k = n;
	n = ((long long)n % 2 != 0 ? n + 0.5 : n + 0.499);
	ft_len_f_add(k, n, mcon);
	n *= neg;
	return (n);
}

char			*ft_str_prec(char *s1, int dot, int end, int hash)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = -1;
	tmp = ft_strnew(ft_strlen(s1) + 1);
	while (s1[++i] != '\0')
	{
		tmp[j++] = s1[i];
		if (i == dot - 1 && end > 0 && (tmp[j++] = '.'))
			hash = 0;
		if (i >= (end - 1))
		{
			if (hash == 1 && tmp[j - 1] != '.')
				tmp[j++] = '.';
			break ;
		}
	}
	if (hash == 1 && tmp[j - 1] != '.')
		tmp[j] = '.';
	return (tmp);
}

void			print_prec_width(t_mcon *mcon)
{
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	tmp = mcon->strtmp;
	len = ft_strlen(tmp) + mcon->fl->plus;
	if ((mcon->fl->space && mcon->fl->plus == 0))
		len++;
	if (mcon->zerocheckminus && mcon->fl->minus && mcon->fl->zero)
		len++;
	if (mcon->fl->minus)
		mcon->fl->zero = 0;
	if ((ft_strncmp(mcon->sign, "-", 1) == 0) && mcon->fl->zero > 0
						&& mcon->fl->plus == 0 && mcon->fl->space == 0)
		len++;
	if (mcon->fl->precis > 0 && mcon->width > 0)
		while (mcon->width - ++i > len)
			mcon->fl->zero == 1 ? mcon->point = ft_strjoin(mcon->point, "0") :
								(mcon->point = ft_strjoin(mcon->point, " "));
	else
		while (mcon->width - ++i > len && mcon->width > 0)
			mcon->fl->zero == 1 ? mcon->point = ft_strjoin(mcon->point, "0") :
								(mcon->point = ft_strjoin(mcon->point, " "));
}
