#include "simulator.h"

static int	ft_get_order(t_sim *sim);
static int	ft_get_cancel(t_sim *sim);

int	ft_get_request(t_sim *sim)
{
	if (!get_next_line(0, &sim->read_line))
		return (1);
	if (*sim->read_line == 'O')
		ft_get_order(sim);
	else if (*sim->read_line == 'C')
		ft_get_cancel(sim);
	else
		ft_err_exit(sim, "ошибка формата ввода данных", 1);
	return (0);
}

static int	ft_get_order(t_sim *sim)
{
	char		*s1;
	char		*s2;
	int			f;
	t_order		*order;

	s1 = sim->read_line;
	if (!s1)
		return (1);
	order = (t_order *)ft_memalloc(sizeof(t_order));
	if (!order)
		ft_err_exit(sim, "ошибка виделения памяти malloc()", 1);
	s1 += 2;
	s2 = s1;
	f = 0;
	while (*s2)
	{
		if (*s2 == ',')
		{
			ft_ex_order_func(f, order, s1, s2);
			++f;
			s1 = s2 + 1;
		}
		s2++;
	}
	ft_ex_order_func(f, order, s1, s2);
	return (0);
}

static int	ft_get_cancel(t_sim *sim)
{
	ft_putstr("cancel: ");
	ft_putendl(sim->read_line + 1);
	return (0);
}
