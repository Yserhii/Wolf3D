/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:05:18 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/23 19:05:20 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int			ft_change_type_d(t_mcon *mcon, va_list argc)
{
	if (mcon->mod == hh)
		return ((char)va_arg(argc, int));
	if (mcon->mod == h)
		return ((short)va_arg(argc, int));
	if (mcon->mod == ll)
		return (va_arg(argc, long long));
	if (mcon->mod == l)
		return (va_arg(argc, long));
	if (mcon->mod == j)
		return (va_arg(argc, intmax_t));
	if (mcon->mod == z)
		return (va_arg(argc, size_t));
	if (mcon->mod == t)
		return (va_arg(argc, ptrdiff_t));
	return (va_arg(argc, int));
}

unsigned long long int	ft_change_type_du(t_mcon *mcon, va_list argc)
{
	if (mcon->mod == hh)
		return ((unsigned char)va_arg(argc, unsigned int));
	if (mcon->mod == h)
		return ((unsigned short)va_arg(argc, unsigned int));
	if (mcon->mod == ll)
		return (va_arg(argc, unsigned long long));
	if (mcon->mod == l)
		return (va_arg(argc, unsigned long));
	if (mcon->mod == j)
		return (va_arg(argc, uintmax_t));
	if (mcon->mod == z)
		return (va_arg(argc, size_t));
	if (mcon->mod == t)
		return (va_arg(argc, ptrdiff_t));
	return (va_arg(argc, unsigned int));
}

long double				ft_change_type_f(t_mcon *mcon, va_list argc)
{
	if (mcon->mod == L)
		return (va_arg(argc, long double));
	else
		return (va_arg(argc, double));
}
