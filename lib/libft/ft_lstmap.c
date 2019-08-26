/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:20:23 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:16:37 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*lstcpy;
	t_list	*tmp1;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	lstcpy = lst;
	tmp = f(lstcpy);
	tmp1 = tmp;
	lstcpy = lstcpy->next;
	while (lstcpy)
	{
		tmp->next = f(lstcpy);
		tmp = tmp->next;
		lstcpy = lstcpy->next;
	}
	tmp->next = NULL;
	return (tmp1);
}
