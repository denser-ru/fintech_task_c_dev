#include "simulator.h"
#include <stdio.h>

static void	do_trans(t_sim *sim, t_list **root, t_list *cur, t_order *order);
static int	put_trade(t_sim *sim, t_order *order_1, t_order *order_2, int qty);

int	ft_order_s_ex(t_sim *sim, t_order *order)
{
	t_list	*cur;

	cur = sim->b_orders;
	if (!order)
		return (1);
	while (cur && order->qty && ((t_order *)cur->content)->price >= order->price)
	{
		do_trans(sim, &sim->b_orders, cur, order);
		cur = cur->next;
	}
	if (order->qty)
		ft_order_add(sim, order, order->side);
	if (cur && !((t_order *)cur->content)->qty)
		ft_lstcut(&sim->b_orders, cur, ft_lstdelcontent);
	return (0);
}

int	ft_order_b_ex(t_sim *sim, t_order *order)
{
	t_list	*cur;

	cur = sim->s_orders;
	if (!order)
		return (1);
	while (cur && order->qty && ((t_order *)cur->content)->price <= order->price)
	{
		do_trans(sim, &sim->s_orders, cur, order);
		cur = cur->next;
	}
	if (order->qty)
		ft_order_add(sim, order, order->side);
	return (0);
}

static void	do_trans(t_sim *sim, t_list **root, t_list *cur, t_order *order)
{
	if (((t_order *)cur->content)->qty > order->qty)
	{
		((t_order *)cur->content)->qty -= order->qty;
		order->qty = 0;
		put_trade(sim, (t_order *)cur->content, order, order->qty);
	}
	else if (((t_order *)cur->content)->qty == order->qty)
	{
		put_trade(sim, (t_order *)cur->content, order, order->qty);
		order->qty = 0;
		ft_lstcut(root, cur, ft_lstdelcontent);
	}
	else
	{
		order->qty -= ((t_order *)cur->content)->qty;
		put_trade(sim, (t_order *)cur->content, order,
				  ((t_order *)cur->content)->qty);
		ft_lstcut(root, cur, ft_lstdelcontent);
	}
//	if (!((t_order *)cur->content)->qty)
//		ft_lstcut(root, cur, ft_lstdelcontent);
}

static int	put_trade(t_sim *sim, t_order *order_1, t_order *order_2, int qty)
{
	t_order *order;

	if (order_1->side == 'S')
		order = order_1;
	else
		order = order_2;
	printf("T,%d,%c,%d,%d,%d,%d.%d\n", (int)sim->transactions, order_1->side,
		order_1->id, order_2->id, qty, order->price_d, order->price_f);
	++sim->transactions;
	return (0);
}