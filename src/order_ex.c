#include "simulator.h"

int	ft_order_s_ex(t_sim *sim, t_order *order)
{
	sim->price_s_min += 0;
	order->price += 0;
	return (0);
}

int	ft_order_b_ex(t_sim *sim, t_order *order)
{
	sim->price_b_max += 0;
	order->price += 0;
	return (0);
}