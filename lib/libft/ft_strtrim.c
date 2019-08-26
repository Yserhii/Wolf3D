/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:52:56 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:23:31 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
	{
		tmp = (char *)malloc(sizeof(char));
		tmp[0] = '\0';
		return (tmp);
	}
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	if (!(tmp = (char*)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	ft_strncpy(tmp, &s[i], (len - i));
	tmp[len - i] = '\0';
	return (tmp);
}
