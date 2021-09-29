#include "simulator.h"

int	ft_get_order_id(t_order *order, const char *s1, const char *s2);
int	ft_get_order_side(t_order *order, const char *s1, const char *s2);
int	ft_get_order_qty(t_order *order, const char *s1, const char *s2);
int	ft_get_order_price(t_order *order, const char *s1, const char *s2);

void	ft_ex_order_func(int f, t_order *order, const char *s1, const char *s2)
{
	static int (*run_func[])(t_order *, const char *, const char *) = {
			&ft_get_order_id,
			&ft_get_order_side,
			ft_get_order_qty,
			ft_get_order_price
	};

	(run_func[f])(order, s1, s2);
}

int	ft_get_order_id(t_order *order, const char *s1, const char *s2)
{
	order->id = ft_atoi_n(s1, s2 - s1);
	return (0);
}

int	ft_get_order_side(t_order *order, const char *s1, const char *s2)
{
	order->side = *s1;
	s2 += 0;
	return (0);
}

int	ft_get_order_qty(t_order *order, const char *s1, const char *s2)
{
	order->qty = ft_atoi_n(s1, s2 - s1);
	return (0);
}

int	ft_get_order_price(t_order *order, const char *s1, const char *s2)
{
	order->price_d = ft_atoi_n(s1, s2 - s1);
	while (*s1 && *s1 != '.')
		++s1;
	if (*s1 && *(++s1))
	{
		order->price_f += (*s1 - '0') * 10;
		if (*s1 && *(++s1))
			order->price_f += *s1 - '0';
	}
	order->price = order->price_d * 100 + order->price_f;
	return (0);
}