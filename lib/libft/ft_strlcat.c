/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:38:03 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:21:28 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendst;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (dstsize <= lendst)
		return (lensrc + dstsize);
	while (dst[i] && (dstsize - 1))
		i++;
	while ((dstsize - 1) > i && *src)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (lendst + lensrc);
}
