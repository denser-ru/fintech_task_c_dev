#ifndef SIMULATOR_H
#define SIMULATOR_H

# include "libft.h"
# include "get_next_line.h"

typedef struct s_sim	t_sim;
typedef struct s_order	t_order;

struct s_sim
{
	char		*read_line;
	t_list		*s_orders;
	t_list		*b_orders;
	size_t		transactions;
	t_putmem	buf[FT_PUTMEM];
};

struct s_order
{
	int		id;
	char	type;
	char	side;
	int		qty;
	int		price;
	int		price_d;
	int		price_f;
};

/*
** get_request.c
*/
int		ft_get_request(t_sim *sim, t_order *order);

/*
** get_request.c
*/
int		ft_ex_request(t_sim *sim, t_order *order);
t_list	*ft_find_order(t_list *root, int id);

/*
** order_s_add.c
*/
int		ft_order_add(t_sim *sim, t_order *order, char side);

/*
** ft_order_functions.c
*/
void	ft_ex_order_func(int f, t_order *order, const char *s1, const char *s2);

/*
** order_ex.c
*/
int		ft_order_s_ex(t_sim *sim, t_order *order);
int		ft_order_b_ex(t_sim *sim, t_order *order);

/*
** ft_exit.c
*/
int		ft_err_exit(t_sim *sim, char *msg, int err);

#endif