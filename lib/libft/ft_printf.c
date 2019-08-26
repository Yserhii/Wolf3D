/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:47:55 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/23 12:47:56 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strlen_for_print(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static int		ft_end(t_allstr *all)
{
	int		count;

	ft_putstr_fd(all->allstr, all->fd);
	count = ft_strlen_for_print(all->allstr) + all->count;
	free(all->allstr);
	free(all);
	return (count);
}

static void		ft_print_format(char *str, t_allstr *all, va_list argc)
{
	while (*str != '\0')
	{
		*str == '{' ? str = ft_collor(str, all) : 0;
		if (*str == '%' && *(str + 1) == '\0')
			break ;
		if (*str == '%' && *(str + 1) != '%')
			str = ft_print_con(str, all, argc);
		else if (*str == '%' && *(str + 1) == '%' &&
			(all->allstr = ft_strnjoin(all->allstr, str, 1)))
			str += 2;
		else
		{
			all->allstr = ft_strnjoin(all->allstr, str, 1);
			str++;
		}
	}
}

int				ft_printf(const char *format, ...)
{
	t_allstr	*all;
	va_list		argc;
	char		*str;
	int			count;

	va_start(argc, format);
	str = (char *)format;
	all = ft_memalloc(sizeof(t_allstr));
	all->fd = 1;
	ft_print_format(str, all, argc);
	count = (*(char *)format != '\0' ? ft_end(all) : 0);
	va_end(argc);
	return (count);
}
