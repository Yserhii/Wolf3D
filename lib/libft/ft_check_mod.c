/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:12:41 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/23 16:12:42 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*check_flag(char *str, t_mcon *mcon)
{
	while (ft_strchr("#0-+ ", *str) && *str != '\0')
	{
		if (*str == '#')
			mcon->fl->hesh = 1;
		else if (*str == '-')
			mcon->fl->minus = 1;
		else if (*str == '+')
			mcon->fl->plus = 1;
		else if (*str == '0')
			mcon->fl->zero = 1;
		else if (*str == ' ')
			mcon->fl->space = 1;
		str++;
	}
	return (str);
}

static char		*check_width(char *str, t_mcon *mcon, va_list argc)
{
	while (*str == '*')
	{
		mcon->width = va_arg(argc, int);
		str++;
		if (mcon->width < 0)
		{
			mcon->fl->minus = 1;
			mcon->width *= -1;
		}
	}
	if (*str >= '0' && *str <= '9')
	{
		mcon->width = ft_atoi(str);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (!str)
		exit(1);
	return (str);
}

static char		*check_precision(char *str, t_mcon *mcon, va_list argc)
{
	while (*str == '.')
		str++;
	mcon->fl->precis = 1;
	mcon->num_prec = 0;
	while (*str == '*')
	{
		mcon->num_prec = va_arg(argc, int);
		str++;
		if (mcon->num_prec < 0)
		{
			mcon->fl->precis = 0;
			mcon->num_prec = 0;
		}
	}
	if (*str >= '0' && *str <= '9')
	{
		mcon->num_prec = ft_atoi(str);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (!str)
		exit(1);
	return (str);
}

static char		*check_mod(char *str, t_mcon *mcon)
{
	while (ft_strchr("hljzLzjt", *str) && *str != '\0')
	{
		if (mcon->mod == z || mcon->mod == j)
			while (ft_strchr("hljzL", *str) && *str != '\0')
				str++;
		else if (ft_strncmp(str, "ll", 2) == 0 && (mcon->mod = ll))
			str += 2;
		else if (ft_strncmp(str, "hh", 2) == 0 && (mcon->mod = hh))
			str += 2;
		else if (*str == 'l' && (mcon->mod = l))
			str += 1;
		else if (*str == 'h' && (mcon->mod = h))
			str += 1;
		else if (*str == 'L' && (mcon->mod = L))
			str += 1;
		else if (*str == 'j' && (mcon->mod = j))
			str += 1;
		else if (*str == 'z' && (mcon->mod = z))
			str += 1;
		else if (*str == 't' && (mcon->mod = t))
			str += 1;
	}
	return (str);
}

char			*ft_check_mod(char *str, t_mcon *mcon, va_list argc)
{
	str++;
	if (*str == '\0')
		return (str);
	while (ft_strchr("#0-+ *123456789.hljzLzjt", *str) && *str != '\0')
	{
		if (ft_strchr("#0-+ ", *str))
			str = check_flag(str, mcon);
		if (ft_strchr("0123456789*", *str))
			str = check_width(str, mcon, argc);
		if (ft_strchr(".", *str))
			str = check_precision(str, mcon, argc);
		if (ft_strchr("hljzLzjt", *str))
			str = check_mod(str, mcon);
	}
	if (*str == '\0')
		return (str);
	mcon->con = *str;
	return (str + 1);
}
