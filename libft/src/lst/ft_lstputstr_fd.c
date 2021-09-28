/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 00:51:56 by cayako            #+#    #+#             */
/*   Updated: 2021/06/27 00:57:29 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_lstputstr_fd(t_list *lst, int fd)
{
    if (lst)
        ft_putnstr_fd(lst->content, lst->content_size, fd);
}
