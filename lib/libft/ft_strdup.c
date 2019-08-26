/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:11:11 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:20:31 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	s2 = ft_strnew(ft_strlen(s1));
	if (s2 == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
