/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:07:26 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:17:45 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if ((char *)dst > (char *)src)
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	else if ((char *)dst <= (char *)src)
		while (len--)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	return (dst);
}
