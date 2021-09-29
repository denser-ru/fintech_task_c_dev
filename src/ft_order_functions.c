#include "simulator.h"

int	ft_get_order_id(t_order *order, char *s1, char *s2);
int	ft_get_order_side(t_order *order, char *s1, char *s2);
int	ft_get_order_qty(t_order *order, char *s1, char *s2);
int	ft_get_order_price(t_order *order, char *s1, char *s2);

void	ft_ex_order_func(int f, t_order *order, char *s1, char *s2)
{
	static int (*run_func[])(t_order *, char *, char *) = {
			&ft_get_order_id,
			&ft_get_order_side,
			ft_get_order_qty,
			ft_get_order_price
	};

	(run_func[f])(order, s1, s2);
}

int	ft_get_order_id(t_order *order, char *s1, char *s2)
{
	order->id = ft_atoi_n(s1, s2 - s1);
	ft_putstr("id: ");
	ft_putnbr(order->id);
	return (0);
}

int	ft_get_order_side(t_order *order, char *s1, char *s2)
{
	order->side = *s1;
	ft_putstr("; side: ");
	ft_putchar(order->side);
	s2 += 0;
	return (0);
}

int	ft_get_order_qty(t_order *order, char *s1, char *s2)
{
	order->qty = ft_atoi_n(s1, s2 - s1);
	ft_putstr("; qty: ");
	ft_putnbr(order->qty);
	return (0);
}

int	ft_get_order_price(t_order *order, char *s1, char *s2)
{
	order->price = (float)ft_atoi_n(s1, s2 - s1);
	while (*s1 && *s1 != '.')
		++s1;
	if (*s1 && *(++s1))
	{
		order->price += (float)(*s1 - '0') / 10;
		if (*s1 && *(++s1))
			order->price += (float)(*s1 - '0') / 100;
	}
	ft_putstr("; price: ");
	ft_putnbr((int)order->price);
	ft_putchar('.');
	ft_putnbr((int)((order->price - (int)order->price) * 100));
	ft_putchar('\n');
	return (0);
}