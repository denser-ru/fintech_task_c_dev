#ifndef SIMULATOR_H
#define SIMULATOR_H

# include "libft.h"
# include "get_next_line.h"

typedef struct s_sim	t_sim;
typedef struct s_order	t_order;

struct s_sim
{
	char	*read_line;
	t_order	*orders;
};

struct s_order
{
	int		id;
	char	side;
	int		qty;
	float	price;
};

/*
** get_request.c
*/
int	ft_get_request(t_sim *sim);

/*
** ft_order_functions.c
*/
void	ft_ex_order_func(int f, t_order *order, char *s1, char *s2);

/*
** ft_exit.c
*/
int			ft_err_exit(t_sim *sim, char *msg, int err);

#endif