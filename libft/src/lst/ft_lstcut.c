/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 01:03:07 by cayako            #+#    #+#             */
/*   Updated: 2019/10/26 01:11:42 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static t_list	*ft_lstcut_check(t_list **root, t_list *cut,
							t_list **prev, void (*del)(void *, size_t))
{
	if (*root == cut)
	{
		if (!cut->next)
		{
			ft_lstdelone(&cut, del);
			*root = NULL;
			return (NULL);
		}
		*prev = cut->next;
		*root = *prev;
	}
	else
		*prev = *root;
	if (*root && *root == cut->next)
	{
		ft_lstdelone(&cut, del);
		return (NULL);
	}
	return (*root);
}

void	ft_lstcut(t_list **root, t_list *cut, void (*del)(void *, size_t))
{
	t_list			*prev;
	t_list			*cur;
	t_list			*next;

	cur = ft_lstcut_check(root, cut, &prev, del);
	next = NULL;
	while (cur)
	{
		if (cur == cut)
		{
			prev->next = next;
			ft_lstdelone(&cut, del);
			return ;
		}
		prev = cur;
		cur = cur->next;
		if (cur)
			next = cur->next;
		else
			next = NULL;
	}
}
