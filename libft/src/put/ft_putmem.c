/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:03:40 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_mem(t_putmem *out, char const c)
{
	if (!c)
		return (0);
	if (!out->p)
		out->p = out->mem;
	if (out->p - out->mem + 1 >= FT_PUTMEM)
		return (-1);
	ft_memcpy(out->p, &c, 1);
	++out->count;
	++out->p;
	return (1);
}

int	ft_putstr_mem(t_putmem *out, char const *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!out->p)
		out->p = out->mem;
	if (out->p - out->mem + len >= FT_PUTMEM)
		return (-1);
	ft_memcpy(out->p, s, len);
	out->count += len;
	out->p += len;
	return (len);
}

int	ft_putnstr_mem(t_putmem *out, char const *s, size_t n)
{
	if (!s)
		return (0);
	if (!out->p)
		out->p = out->mem;
	if (out->p - out->mem + n >= FT_PUTMEM)
		return (-1);
	ft_memcpy(out->p, s, n);
	out->count += n;
	out->p += n;
	return ((int)n);
}

inline static void to_mem(t_putmem *out, char s[13], int i)
{
	ft_memcpy(out->p, &s[i + 1], 12 - i);
	out->count += 12 - i;
	out->p += 12 - i;
}

int	ft_putnbr_mem(t_putmem *out, int n)
{
	char	s[13];
	int		i;
	long	ln;

	if (n == 0)
	{
		*out->p = '0';
		return (1);
	}
	i = 11;
	s[12] = '\0';
	if (n < 0)
		ln = -(long)n;
	else
		ln = n;
	while (ln > 0)
	{
		s[i] = '0' + ln % 10;
		ln /= 10;
		--i;
	}
	if (n < 0)
		s[i--] = '-';
	to_mem(out, s, i);
	return (11 - i);
}