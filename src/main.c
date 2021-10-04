#include "simulator.h"

int	ft_init(t_sim **sim);
int	ft_loop(t_sim *sim);

int main()
{
	t_sim	*sim;

	if (ft_init(&sim))
		return (1);
	ft_loop(sim);
	ft_putendl("END");
	return 0;
}

int	ft_init(t_sim **sim)
{
	*sim = (t_sim *)ft_memalloc(sizeof(t_sim));
	if (!*sim)
		return (1);
	++(*sim)->transactions;
	return (0);
}

int	ft_loop(t_sim *sim)
{
	t_order		order;

	while (!ft_get_request(sim, &order))
		ft_ex_request(sim, &order);
	return (0);
}
