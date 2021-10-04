#include "simulator.h"

int	ft_init(t_sim **sim);
int	ft_loop(t_sim *sim);

int main()
{
	t_sim	*sim;

	if (ft_init(&sim))
		return (1);
	ft_loop(sim);
	ft_sim_mem_clear(&sim);
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

void	ft_sim_mem_clear(t_sim **sim)
{
	ft_lstdel(&(*sim)->s_orders, ft_lstdelcontent);
	ft_lstdel(&(*sim)->b_orders, ft_lstdelcontent);
	ft_strdel(&(*sim)->read_line);
	free(*sim);
	*sim = NULL;
}