/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:13:50 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:14:17 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*point;

	point = *alst;
	if (alst == NULL || new == NULL)
		return ;
	while (point->next)
		point = point->next;
	point->next = new;
}
