/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <yserhii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:18:58 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:16:45 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if ((tmp = (t_list*)malloc(sizeof(t_list))) != NULL)
	{
		if (content == NULL)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		else
		{
			if (!(tmp->content = malloc(content_size)))
				return (NULL);
			ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
		}
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}
