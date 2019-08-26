/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_nan_ifn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:48:58 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/19 14:49:03 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_f_inf(t_mcon *mcon)
{
	mcon->fl->zero = 0;
	mcon->num_prec = 4;
	if (mcon->zerocheckminus == 1 || mcon->fl->plus)
	{
		if (mcon->zerocheckminus == 1)
			(mcon->con == 'f') ? ft_write_str(mcon, "-inf") :
												ft_write_str(mcon, "-INF");
		else
			mcon->con == 'f' ? ft_write_str(mcon, "+inf") :
												ft_write_str(mcon, "+INF");
		return ;
	}
	else if (mcon->fl->plus == 0 && mcon->fl->space && mcon->fl->minus)
		mcon->con == 'f' ? ft_write_str(mcon, " inf") :
												ft_write_str(mcon, " INF");
	else
	{
		mcon->num_prec = 4;
		mcon->con == 'f' ? ft_write_str(mcon, "inf") :
												ft_write_str(mcon, "INF");
	}
}
