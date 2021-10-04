#include "simulator.h"

int	ft_order_insert(t_list **root, t_list *new, t_list *prev);

int	ft_order_add(t_sim *sim, t_order *order, char side)
{
	t_list	*order_list;
	t_list	*cur;
	t_list	*prev;
	t_list	**root;

	order_list = ft_lstnew(order, sizeof(t_order));
	prev = NULL;
	if (side == 'S')
		root = &sim->s_orders;
	else
		root = &sim->b_orders;
	cur = *root;
	while (cur && ((side == 'S'
			&& order->price > ((t_order *)cur->content)->price)
			||
			(side == 'B'
			 && order->price < ((t_order *)cur->content)->price)))
	{
		prev = cur;
		cur = cur->next;
	}
	ft_order_insert(root, order_list, prev);
	return (0);
}

int	ft_order_insert(t_list **root, t_list *new, t_list *prev)
{
	if (prev)
	{
		if (prev->next)
			new->next = prev->next;
		prev->next = new;
		return (0);
	}
	else if (*root)
		new->next = *root;
	*root = new;
	return (0);
}