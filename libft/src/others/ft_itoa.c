/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 23:29:54 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:38:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static void	get_nb_size(unsigned int *nb, int nbr, unsigned int *size)
{
	if (nbr < 0)
		*nb = (unsigned int)(nbr * -1);
	else
		*nb = (unsigned int)nbr;
	size = 0;
	while (*nb >= 10)
	{
		*nb /= 10;
		++size;
	}
}

char	*ft_itoa(int nbr)
{
	char			*str;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	size;

	get_nb_size(&nb, nbr, &size);
	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1 + (int)(nbr < 0)));
	if (!(str))
		return (0);
	str[i] = '-';
	if (nbr < 0 && str[i])
		size++;
	i = size - 1;
	while (nb >= 10)
	{
		str[i--] = (char)(nb % 10 + '0');
		nb /= 10;
	}
	str[i] = (char)(nb % 10 + '0');
	str[size] = '\0';
	return (str);
}
