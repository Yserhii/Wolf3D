/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:04:06 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/15 12:04:10 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_num(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	if (c == 'b' || c == 'B')
		return (11);
	if (c == 'c' || c == 'C')
		return (12);
	if (c == 'd' || c == 'D')
		return (13);
	if (c == 'e' || c == 'E')
		return (14);
	if (c == 'f' || c == 'F')
		return (15);
	else
		return (c - 48);
}

int		ft_atoi_base(char *str, int base)
{
	int i;
	int res;

	while (*str && *str != 'x')
		str++;
	if (*str == '\0')
		return (0);
	i = 1;
	res = 0;
	while (str[i] != '\0')
	{
		if (ft_strlen(str) > 1 && i == 0)
			res = base * get_num(str[i++]);
		else if (ft_strlen(str) > 1 && i > 0)
			res *= base;
		res += get_num(str[i]);
		i++;
	}
	return (res);
}
