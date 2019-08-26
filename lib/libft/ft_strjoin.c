/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 13:47:24 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:21:19 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	size_t	i;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	i = (ft_strlen(s1) + ft_strlen(s2));
	tmp = ft_strnew(i);
	ft_strcpy(tmp, s1);
	ft_strcpy(&tmp[ft_strlen(s1)], s2);
	free(s1);
	return (tmp);
}
