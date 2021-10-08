#include "simulator.h"

void ft_print_order(t_order *order, char *pref)
{
	t_putmem	*buf;

	buf = (t_putmem *) ft_memalloc(sizeof(t_putmem));
	ft_putstr_mem(buf, pref);
	ft_putnstr_mem(buf, "id:", 3);
	ft_putnbr_mem(buf, order->id);
	ft_putchar_mem(buf, ',');
	ft_putchar_mem(buf, order->side);
	ft_putchar_mem(buf, ',');
	ft_putnbr_mem(buf, order->qty);
	ft_putchar_mem(buf, ',');
	ft_putnstr_mem(buf, order->price_s, order->price_len);
	ft_putchar_mem(buf, '\n');
	ft_putnstr(buf->mem, buf->count);
	free(buf);
}

void	ft_print_orders(t_list *root)
{
	t_list	*cur;
	t_order	*order;

	cur = root;
	while (cur)
	{
		order = (t_order *)cur->content;
		ft_print_order(order, " -- " );
		cur = cur->next;
	}
}

void	ft_print_orders_all(t_sim *sim)
{
	ft_putstr("B oredrs:\n");
	ft_print_orders(sim->b_orders);
	ft_putstr("S oredrs:\n");
	ft_print_orders(sim->s_orders);
	ft_putstr("=====\n");
}

void	ft_lstcut_test(t_sim *sim, t_list **root, t_list *cut, void (*del)(void *, size_t))
{
	if (FT_DEV && ft_condition_check(sim))
	{
		ft_putstr("\n-----\nУдаление: ");
		ft_print_order(cut->content, " ---> ");
		ft_putstr(".....\n");
	}
	ft_lstcut(root, cut, del);
	if (FT_DEV && ft_condition_check(sim))
	{
		ft_putstr("B oredrs:\n");
		ft_print_orders(sim->b_orders);
		ft_putstr("S oredrs:\n");
		ft_print_orders(sim->s_orders);
	}
}

int		ft_condition_check(t_sim *sim)
{
	if (FT_STOP_TRANS && sim->transactions == FT_STOP_TRANS)
		return (1);
	return (0);
}