/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:59:57 by yserhii           #+#    #+#             */
/*   Updated: 2019/02/12 13:59:59 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlinks(void *content, size_t content_size)
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
			tmp->content = content;
			tmp->content_size = content_size;
		}
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}
