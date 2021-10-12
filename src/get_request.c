#include "simulator.h"
#include <stdio.h>

static int	ft_get_order(t_sim *sim, t_order *order);
static int	ft_get_cancel(t_sim *sim, t_order *order);

int	ft_get_request(t_sim *sim, t_order *order)
{
	size_t	size;
	int 	len;

	size = 0;
	sim->read_line = NULL;
	if (FT_DEV && ++sim->test_i == FT_STOP)
		ft_err_exit(sim, "(dev) STOP", 1);
	len = getline(&sim->read_line, &size, stdin);
	if (len == -1)
	{
		ft_strdel(&sim->read_line);
		return (1);
	}
	*(sim->read_line + --len) = '\0';
	ft_bzero(order, sizeof(t_order));
	if (*sim->read_line == 'O')
		ft_get_order(sim, order);
	else if (*sim->read_line == 'C')
		ft_get_cancel(sim, order);
	else
		ft_err_exit(sim, "ошибка формата ввода данных", 1);
	ft_strdel(&sim->read_line);
	return (0);
}

static int	ft_get_order(t_sim *sim, t_order *order)
{
	char		*s1;
	char		*s2;
	int			f;

	s1 = sim->read_line + 2;
	s2 = s1;
	order->type = 'O';
	f = 0;
	while (*s2 && f < 4)
	{
		if (*s2 == ',')
		{
			ft_ex_order_func(f, order, s1, s2);
			++f;
			s1 = s2 + 1;
		}
		s2++;
	}
	if (f < 3 || ft_ex_order_func(f, order, s1, s2))
		ft_err_exit(sim, "ошибка формата ввода данных", 1);
	return (0);
}

static int	ft_get_cancel(t_sim *sim, t_order *order)
{
	char	*s;

	s = sim->read_line;
	order->type = 'C';
	order->side = 'C';
	if (!*(++s) || !*(++s))
		ft_err_exit(sim, "ошибка формата ввода данных", 1);
	order->id = ft_atoi(s);
	return (0);
}
