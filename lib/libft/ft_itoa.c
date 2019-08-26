/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:35:27 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:12:18 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		a;
	size_t	i;

	a = n;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (a != 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*tmp;

	len = ft_len(n) - 1;
	if ((tmp = ft_strnew(ft_len(n))) != NULL)
	{
		if (n < 0)
			tmp[0] = '-';
		if (n == 0)
		{
			tmp[0] = n + '0';
			return (tmp);
		}
		while (n != 0)
		{
			tmp[len] = ft_abs(n % 10) + '0';
			n /= 10;
			len--;
		}
		return (tmp);
	}
	return (NULL);
}
