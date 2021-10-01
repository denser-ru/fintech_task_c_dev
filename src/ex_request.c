#include "simulator.h"
#include <stdio.h>

static int ft_ex_order_s(t_sim *sim, t_order *order);
static int ft_ex_order_b(t_sim *sim, t_order *order);
static int ft_ex_order_c(t_sim *sim, int id);

int	ft_ex_request(t_sim *sim, t_order *order)
{
	sim += 0;
	order += 0;
	if (order->type == 'O')
	{
		if (order->side == 'S')
			return (ft_ex_order_s(sim, order));
		else
			return (ft_ex_order_b(sim, order));
	}
	else
		return (ft_ex_order_c(sim, order->id));
}

static int ft_ex_order_s(t_sim *sim, t_order *order)
{
	if (!sim->s_orders)
		sim->price_s_min = order->price;
	if (order->price > sim->price_b_max)
		return (ft_order_add(sim, order, 'S'));
	else
		return (ft_order_s_ex(sim, order));
}

static int ft_ex_order_b(t_sim *sim, t_order *order)
{
	if (!sim->b_orders)
		sim->price_b_max = order->price;
	if (order->price < sim->price_s_min)
		return (ft_order_add(sim, order, 'B'));
	else
		return (ft_order_b_ex(sim, order));
}

t_list	*ft_find_order(t_list *root, int id)
{
	t_list	*cur;

	if (!root)
		return (NULL);
	cur = root;
	while (cur)
	{
		if (((t_order *)cur)->id == id)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

static int ft_ex_order_c(t_sim *sim, int id)
{
	t_list	*order_list;

	order_list = ft_find_order(sim->s_orders, id);
	if (!order_list)
		return (1);
	ft_lstcut(&sim->s_orders, order_list, ft_lstdelcontent);
	return (0);
}