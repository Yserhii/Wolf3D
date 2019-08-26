/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_date.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:59:20 by yserhii           #+#    #+#             */
/*   Updated: 2019/01/19 16:59:22 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_write_date(void)
{
	time_t		t;
	struct tm	*today;

	t = time(NULL);
	today = localtime(&t);
	ft_printf("%04d-%02d-%02d", today->tm_year + 1900,
						today->tm_mon + 1, today->tm_mday);
}
