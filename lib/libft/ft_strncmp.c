/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:51:27 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:22:08 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && n > i)
		i++;
	if (i != n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (((unsigned char *)s1)[i - 1] - ((unsigned char *)s2)[i - 1]);
}
