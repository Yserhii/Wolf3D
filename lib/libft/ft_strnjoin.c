/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:44:44 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/23 14:44:46 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*tmp;
	char	*pointers1;
	size_t	i;

	if (s2 == NULL || n == 0)
		return (NULL);
	if (s1 == NULL)
		return (ft_strndup(s2, n));
	pointers1 = s1;
	i = (ft_strlen(s1) + ft_strlen(s2));
	tmp = ft_strnew(i);
	ft_strcpy(tmp, s1);
	ft_strncat(tmp, s2, n);
	free(pointers1);
	return (tmp);
}
