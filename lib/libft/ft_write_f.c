/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 12:41:22 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/14 15:05:51 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	str_toogeth(t_mcon *mcon, int prec, char *nb, long double num)
{
	if (num == 0)
	{
		if (mcon->fl->plus < 1 && mcon->fl->zero < 1)
			mcon->zerocheckminus == 1 ? nb = ft_strjoin(nb, "-") : 0;
		nb = ft_strjoin(nb, ft_memset(ft_strnew((mcon->num_prec + 1)), '0',
														(mcon->num_prec + 1)));
	}
	else
		nb = ft_ftoa(num, mcon);
	if (mcon->num_prec == 0 && mcon->fl->hesh == 0)
		mcon->strtmp = ft_strdup(nb);
	else
		mcon->strtmp = ft_str_prec(nb, prec, (mcon->fl->precis != 0 ?
						prec + mcon->num_prec : prec + 6), mcon->fl->hesh);
	free(nb);
}

static	void	ft_write_f_str(t_mcon *mcon, long double n)
{
	int				prec;
	char			*nb;
	char			*tmp;
	long double		num;

	nb = NULL;
	if (n < 0 || mcon->zerocheckminus == 1)
		mcon->sign = ft_strndup("-", 1);
	else
		mcon->sign = ft_strndup("+", 1);
	tmp = ft_ftoa(n, mcon);
	prec = ft_strlen(tmp);
	mcon->fl->precis != 0 ? 0 : (mcon->num_prec = 6);
	num = ft_len_f(n, mcon->num_prec, mcon);
	if (mcon->precfload == 1)
		prec++;
	str_toogeth(mcon, prec, nb, num);
	free(tmp);
}

static void		ft_write_f_width_minus(t_mcon *mcon)
{
	if (ft_strncmp(mcon->sign, "-", 1) == 0 &&
							(mcon->fl->zero > 0 || mcon->fl->plus > 0))
		mcon->point = ft_strjoin(mcon->point, "-");
	if (mcon->zerocheckminus == 0 &&
							(mcon->fl->plus > 0 || mcon->fl->space > 0))
		mcon->fl->plus > 0 ?
	mcon->point = ft_strjoin(mcon->point, mcon->sign) :
							(mcon->point = ft_strjoin(mcon->point, " "));
	mcon->point = ft_strjoin(mcon->point, mcon->strtmp);
	print_prec_width(mcon);
	if (mcon->fl->space && mcon->fl->plus && mcon->fl->minus == 0)
		(mcon->point = ft_strjoin(mcon->point, " "));
}

static void		ft_write_f_width(t_mcon *mcon)
{
	int		check;

	check = 0;
	if (mcon->fl->zero == 0 && (check = 1))
		print_prec_width(mcon);
	if (mcon->zerocheckminus == 0 &&
							(mcon->fl->plus || mcon->fl->space))
		mcon->fl->plus == 1 ?
					mcon->point = ft_strjoin(mcon->point, mcon->sign) :
							(mcon->point = ft_strjoin(mcon->point, " "));
	if (ft_strncmp(mcon->sign, "-", 1) == 0 &&
							(mcon->fl->zero > 0 || mcon->fl->plus > 0))
		mcon->point = ft_strjoin(mcon->point, "-");
	check == 0 ? print_prec_width(mcon) : 0;
	mcon->point = ft_strjoin(mcon->point, mcon->strtmp);
}

void			ft_write_f(t_mcon *mcon, long double n)
{
	ft_write_f_str(mcon, n);
	if (mcon->fl->minus)
		ft_write_f_width_minus(mcon);
	else
		ft_write_f_width(mcon);
	free(mcon->sign);
	free(mcon->strtmp);
}
