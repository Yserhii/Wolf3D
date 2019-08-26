/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_con.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:05:45 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/23 15:05:46 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_mcon		*ft_new_struct(char *str)
{
	t_mcon	*mcon;
	t_fl	*fl;

	mcon = ft_memalloc(sizeof(t_mcon));
	fl = ft_memalloc(sizeof(t_fl));
	mcon->head = str;
	mcon->fl = fl;
	mcon->mod = NOT;
	return (mcon);
}

static void			ft_print_str_char(t_mcon *mcon, va_list argc, t_allstr *all)
{
	if (mcon->con == '%')
		ft_write_char(mcon, '%', all);
	if (mcon->con == 'c')
		ft_write_char(mcon, va_arg(argc, int), all);
	if (mcon->con == 's')
		ft_write_str(mcon, va_arg(argc, char*));
}

static void			ft_print_fload(t_mcon *mcon, va_list argc)
{
	union u_mytype		n;
	__uint64_t			*b;

	n.d = ft_change_type_f(mcon, argc);
	b = (__uint64_t*)&n.d;
	mcon->zerocheckminus = (*b >> 63 == 1 ? 1 : 0);
	if (n.d != n.d)
	{
		mcon->num_prec = 3;
		mcon->fl->zero = 0;
		mcon->con == 'f' ? ft_write_str(mcon, "nan") :
									ft_write_str(mcon, "NAN");
	}
	else if ((n.d * 2) == n.d && n.d != 0)
		ft_f_inf(mcon);
	else
		ft_write_f(mcon, n.d);
}

static void			ft_print_digit(t_mcon *mcon, va_list argc)
{
	union u_mytype		n;

	if (ft_strchr("IDOUB", mcon->con))
	{
		mcon->con += 32;
		mcon->mod = l;
	}
	mcon->con == 'p' ? mcon->mod = l : 0;
	(mcon->con == 'd' || mcon->con == 'i') ?
		n.lli = ft_change_type_d(mcon, argc) :
			(n.ulli = ft_change_type_du(mcon, argc));
	(mcon->con == 'd' || mcon->con == 'i') ? ft_write_di(mcon, n.lli) : 0;
	mcon->con == 'u' ? ft_write_u(mcon, n.ulli) : 0;
	(mcon->con == 'o' || mcon->con == 'b') ? ft_write_o(mcon, n.ulli) : 0;
	(mcon->con == 'X' || mcon->con == 'x') ? ft_write_x(mcon, n.ulli) : 0;
	mcon->con == 'p' ? ft_write_p(mcon, n.ulli) : 0;
}

char				*ft_print_con(char *str, t_allstr *all, va_list argc)
{
	t_mcon		*mcon;

	mcon = ft_new_struct(str);
	str = ft_check_mod(str, mcon, argc);
	if (mcon->con == 's' || mcon->con == 'c' || mcon->con == '%')
		ft_print_str_char(mcon, argc, all);
	else if (mcon->con == 'f' || mcon->con == 'F')
		ft_print_fload(mcon, argc);
	else if (ft_strchr("iIdDoOuUxXpBb", mcon->con))
		ft_print_digit(mcon, argc);
	else if (mcon->con == 'k')
		ft_write_date();
	else if (mcon->con == 'r')
		ft_write_r(mcon, va_arg(argc, int));
	else
		ft_write_char(mcon, mcon->con, all);
	mcon->point ? all->allstr = ft_strjoin(all->allstr, mcon->point) : 0;
	free(mcon->point);
	free(mcon->fl);
	free(mcon);
	return (str);
}
