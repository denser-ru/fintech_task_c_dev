/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:45:05 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	nbr;
	int					neg;

	while (ft_iswhitespace(*str))
		str++;
	neg = 1;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		if (nbr > 9223372036854775807 && neg == 1)
			return (-1);
		else if (nbr > 9223372036854775808LLU && neg == -1)
			return (0);
		str++;
	}
	return ((int)nbr * neg);
}
