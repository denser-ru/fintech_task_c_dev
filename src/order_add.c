#include "simulator.h"

static void	ft_order_insert(t_sim *sim, t_list **root, t_list *new,
							   t_list *prev);
static t_list	*find_insertion_point(t_list **prev, t_list *cur, t_order *order,
									   char side);

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
	cur = find_insertion_point(&prev, cur, order, side);
	if (!sim->test_i)
		sim->test_i += 0;
	ft_order_insert(sim, root, order_list, prev);
	return (0);
}

static void	ft_order_insert(t_sim *sim, t_list **root, t_list *new, t_list *prev)
{
	if (FT_DEV && ft_condition_check(sim))
	{
		ft_putstr("\n+++++\nВставка: ");
		ft_print_order(new->content, " ---> ");
		ft_putstr(".....\n");
	}
	if (prev)
	{
		new->next = prev->next;
		prev->next = new;
		return ;
	}
	else if (*root)
		new->next = *root;
	*root = new;
	if (FT_DEV && ft_condition_check(sim))
		ft_print_orders_all(sim);
}

static t_list	*find_insertion_point(t_list **prev, t_list *cur, t_order *order,
										char side)
{
	while (cur && ((side == 'S'
					&& order->price > ((t_order *)cur->content)->price)
				   ||
				   (side == 'B'
					&& order->price < ((t_order *)cur->content)->price)))
	{
		*prev = cur;
		cur = cur->next;
	}
	while (cur && cur->next && order->price == ((t_order *)cur->content)->price
		   && order->id > ((t_order *)cur->content)->id)
	{
		*prev = cur;
		cur = cur->next;
	}
	return (cur);
}