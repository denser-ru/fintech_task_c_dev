#include "simulator.h"
#include <stdio.h>

static void	do_trans(t_sim *sim, t_list **root, t_list *cur, t_order *order);
static int	put_trade(t_sim *sim, int id_1, t_order *order, int qty);

int	ft_order_s_ex(t_sim *sim, t_order *order)
{
	t_list	*cur;

	cur = sim->b_orders;
	if (!order)
		return (1);
	while (order->qty && ((t_order *)cur->content)->price <= order->price)
		do_trans(sim, &sim->b_orders, cur, order);
	if (order->qty)
		ft_order_add(sim, order, order->side);
	return (0);
}

int	ft_order_b_ex(t_sim *sim, t_order *order)
{
	t_list	*cur;

	cur = sim->s_orders;
	if (!order)
		return (1);
	while (order->qty && ((t_order *)cur->content)->price <= order->price)
		do_trans(sim, &sim->s_orders, cur, order);
	if (order->qty)
		ft_order_add(sim, order, order->side);
	return (0);
}

static void	do_trans(t_sim *sim, t_list **root, t_list *cur, t_order *order)
{
	if (((t_order *)cur->content)->qty > order->qty)
	{
		((t_order *)cur->content)->qty -= order->qty;
		put_trade(sim, ((t_order *)cur->content)->id, order, order->qty);
	}
	else if (((t_order *)cur->content)->qty == order->qty)
	{
		put_trade(sim, ((t_order *)cur->content)->id, order, order->qty);
		ft_lstcut(root, cur, ft_lstdelcontent);
	}
	else
	{
		order->qty -= ((t_order *)cur->content)->qty;
		put_trade(sim, ((t_order *)cur->content)->id, order,
				  ((t_order *)cur->content)->qty);
		ft_lstcut(root, cur, ft_lstdelcontent);
	}
}

static int	put_trade(t_sim *sim, int id_1, t_order *order, int qty)
{
	printf("T,%d,%c,%d,%d,%d,%d.%d\n", (int)sim->transactions, order->side,
		id_1, order->id, order->qty, order->price_d, order->price_f);
}