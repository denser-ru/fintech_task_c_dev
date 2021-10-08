#include "simulator.h"

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
	if (!sim->b_orders
			|| order->price > ((t_order *)sim->b_orders->content)->price)
		return (ft_order_add(sim, order, 'S'));
	else
		return (ft_order_s_ex(sim, order));
}

static int ft_ex_order_b(t_sim *sim, t_order *order)
{
	if (!sim->s_orders
		|| order->price < ((t_order *)sim->s_orders->content)->price)
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
		if (((t_order *)cur->content)->id == id)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

static int ft_ex_order_c(t_sim *sim, int id)
{
	t_list	*order_list;
	t_list	**root;

	order_list = ft_find_order(sim->s_orders, id);
	if (!order_list)
		order_list = ft_find_order(sim->b_orders, id);
	if (!order_list)
		return (1);
	if (((t_order *)order_list->content)->side == 'S')
		root = &sim->s_orders;
	else
		root = &sim->b_orders;
	ft_lstcut_test(sim, root, order_list, ft_lstdelcontent);
	ft_putnstr_mem(sim->buf, "X,", 2);
	ft_putnbr_mem(sim->buf, id);
	ft_putchar_mem(sim->buf, '\n');
	ft_putnstr(sim->buf->mem, sim->buf->count);
	ft_putmem_reset(sim->buf);
	return (0);
}