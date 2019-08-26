/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:30:15 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:10:43 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					check;
	int					i;
	unsigned long int	nbr;

	check = 0;
	i = 0;
	nbr = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			check = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr = nbr * 10 + str[i] - 48;
		if (nbr >= 9223372036854775807 && check == 0)
			return (-1);
		else if (nbr > 9223372036854775807 && check == 1)
			return (0);
		i++;
	}
	return (check ? -nbr : nbr);
}
