/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:59:39 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:16:53 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	tmp = (void*)malloc(sizeof(void*) * size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
