/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:29:29 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:22:41 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, size + 1);
	return (tmp);
}
