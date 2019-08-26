/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:53:12 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:22:49 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (needle[0] == '\0' || needle == haystack)
		return (&((char *)haystack)[i]);
	while (haystack[i] != '\0' && len > i)
	{
		if (haystack[i] == needle[0] &&
				ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0
				&& ft_strlen(needle) <= (len - i))
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
