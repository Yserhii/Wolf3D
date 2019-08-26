/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:56:17 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:19:51 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (-1);
	if (s1 && !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
