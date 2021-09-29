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
	return (0);
}

int	ft_loop(t_sim *sim)
{
	int			i;
	t_order		order;

	i = 15;
	while (!ft_get_request(sim, &order) && i--)
	{
		//ft_ex_request(sim);
	}
	return (0);
}
