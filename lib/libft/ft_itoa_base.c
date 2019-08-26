/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 11:36:14 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/23 11:37:27 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n && ++i)
		n /= base;
	return (i);
}

static int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

char		*ft_itoa_base(int n, int base)
{
	int		len;
	char	*tmp;

	len = ft_len(n, base);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp[len] = '\0';
	if (n == 0 && (tmp[0] = n + '0'))
		return (tmp);
	if (n < 0)
		tmp[0] = '-';
	while (n)
	{
		tmp[len - 1] = (ft_abs(n % base) < 10) ? ft_abs(n % base) + '0'
									: ft_abs(n % base) + 'A' - 10;
		n /= base;
		len--;
	}
	return (tmp);
}
