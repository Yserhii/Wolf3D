/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 13:32:38 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:23:26 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strncpy(tmp, &s[start], len);
	tmp[len] = '\0';
	return (tmp);
}
