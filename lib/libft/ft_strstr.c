/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:15:02 by yserhii           #+#    #+#             */
/*   Updated: 2018/11/05 10:24:08 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i])
		if (haystack[i] == needle[0] &&
				(ft_strncmp(&haystack[i], needle, ft_strlen(needle))) == 0)
			return (&((char *)haystack)[i]);
	return (NULL);
}
