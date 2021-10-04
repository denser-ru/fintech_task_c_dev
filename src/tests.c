#include "simulator.h"
#include <stdio.h>

void	print_orders(t_list *root)
{
	t_list	*cur;
	t_order	*order;

	cur = root;
	while (cur)
	{
		order = (t_order *)cur->content;
		printf("---,%d,%c,%d,%d.%d\n", order->id, order->side, order->qty, order->price_d, order->price_f);
		cur = cur->next;
	}
}