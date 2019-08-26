/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:17:21 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:16:20 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst == NULL || del == NULL)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
