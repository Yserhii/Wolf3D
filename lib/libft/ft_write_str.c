/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:22:33 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/14 15:22:36 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_write_str(t_mcon *mcon, char *str)
{
	int		i;
	int		len;

	!str ? str = "(null)" : 0;
	i = ft_strlen(str);
	i == 0 ? mcon->fl->minus = 1 : 0;
	len = ((mcon->num_prec < i && mcon->fl->precis == 1) ? mcon->num_prec : i);
	if (mcon->fl->minus)
	{
		(mcon->fl->precis && mcon->num_prec == 0 && len == 0) ? 0 :
					(mcon->point = ft_strnjoin(mcon->point, str, len));
		while (len < mcon->width--)
			mcon->point = ft_strnjoin(mcon->point, " ", 1);
		return ;
	}
	else if (mcon->fl->zero)
		while (len < mcon->width--)
			mcon->point = ft_strnjoin(mcon->point, "0", 1);
	else
		while (len < mcon->width--)
			mcon->point = ft_strnjoin(mcon->point, " ", 1);
	(mcon->fl->precis && mcon->num_prec == 0 && len == 0) ? 0 :
					(mcon->point = ft_strnjoin(mcon->point, str, len));
	return ;
}
