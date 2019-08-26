/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:39:58 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:23:19 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_printword(char const *s, char c, char **src, size_t countword)
{
	size_t i;
	size_t a;
	size_t gc;

	i = 0;
	gc = 0;
	while (s[i] && countword > gc)
	{
		a = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			src[gc][a] = s[i];
			a++;
			i++;
		}
		src[gc][a] = '\0';
		gc++;
	}
	return (src);
}

static char	**ft_memery(char const *s, char c, char **src, size_t countword)
{
	size_t	i;
	size_t	countletter;
	size_t	gc;

	i = 0;
	gc = 0;
	while (s[i] && countword > gc)
	{
		countletter = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			countletter++;
			i++;
		}
		if (!(src[gc] = (char*)malloc(sizeof(char) * (countletter + 1))))
			return (NULL);
		gc++;
	}
	src[gc] = NULL;
	return (ft_printword(s, c, src, countword));
}

char		**ft_strsplit(char const *s, char c)
{
	int		countword;
	char	**src;
	int		i;
	int		gc;

	i = 0;
	gc = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
	{
		if (!(src = (char**)malloc(sizeof(char*) * 1)))
			return (NULL);
		if (!(src[gc] = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		src[0] = NULL;
		return (src);
	}
	countword = ft_countword(s, c);
	if (countword == 0 ||
			!(src = (char**)malloc(sizeof(char*) * (countword + 1))))
		return (NULL);
	return (ft_memery(s, c, src, countword));
}
