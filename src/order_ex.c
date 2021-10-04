#include "simulator.h"

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
		put_trade(sim, (t_order *)cur->content, order, order->qty);
		order->qty = 0;
	}
	else if (((t_order *)cur->content)->qty == order->qty)
	{
		put_trade(sim, (t_order *)cur->content, order, order->qty);
		order->qty = 0;
		ft_lstcut(root, cur, ft_lstdelcontent);
	}
	else
	{
		put_trade(sim, (t_order *)cur->content, order,
				  ((t_order *)cur->content)->qty);
		order->qty -= ((t_order *)cur->content)->qty;
		ft_lstcut(root, cur, ft_lstdelcontent);
	}
}

void	ft_print_trade(t_sim *sim, t_order *order_1, t_order *order_2, int qty)
{
	ft_putnstr_mem(sim->buf, "T,", 2);
	ft_putnbr_mem(sim->buf, sim->transactions);
	ft_putchar_mem(sim->buf, ',');
	ft_putchar_mem(sim->buf, order_1->side);
	ft_putchar_mem(sim->buf, ',');
	ft_putnbr_mem(sim->buf, order_1->id);
	ft_putchar_mem(sim->buf, ',');
	ft_putnbr_mem(sim->buf, order_2->id);
	ft_putchar_mem(sim->buf, ',');
	ft_putnbr_mem(sim->buf, qty);
	ft_putchar_mem(sim->buf, ',');
	ft_putnbr_mem(sim->buf, order_1->price_d);
	ft_putchar_mem(sim->buf, '.');
	if (order_1->price_f > 0 && order_1->price_f  % 10)
		ft_putnbr_mem(sim->buf, order_1->price_f);
	else
		ft_putnbr_mem(sim->buf, order_1->price_f / 10);
	ft_putchar_mem(sim->buf, '\n');
	ft_putnstr(sim->buf->mem, sim->buf->count);
	ft_putmem_reset(sim->buf);
}

static int	put_trade(t_sim *sim, t_order *order_1, t_order *order_2, int qty)
{
	ft_print_trade(sim, order_1, order_2, qty);
	++sim->transactions;
	return (0);
}