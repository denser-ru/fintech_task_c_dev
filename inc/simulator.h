#ifndef SIMULATOR_H
# define SIMULATOR_H

# include "libft.h"
# include "get_next_line.h"

# define	FT_DEV			0
# define	FT_STOP			2200
# define	FT_STOP_TRANS	1234
# define	FT_LINE_BUF		512

typedef struct s_sim	t_sim;
typedef struct s_order	t_order;

struct s_sim
{
	char		read_line[FT_LINE_BUF + 1];
	t_list		*s_orders;
	t_list		*b_orders;
	size_t		transactions;
	int			test_i;
	t_putmem	buf[FT_PUTMEM];
};

struct s_order
{
	int		id;
	char	type;
	char	side;
	int		qty;
	int		price;
	char	price_s[14];
	size_t	price_len;
};

/*
** main.c
*/
void	ft_sim_mem_clear(t_sim **sim);

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
int		ft_ex_order_func(int f, t_order *order, const char *s1, const char *s2);

/*
** order_ex.c
*/
int		ft_order_s_ex(t_sim *sim, t_order *order);
int		ft_order_b_ex(t_sim *sim, t_order *order);

/*
** ft_exit.c
*/
int		ft_err_exit(t_sim *sim, char *msg, int err);

/*
** gnl_l.c
*/
int				gnl_l(int fd, char *line);


/*
** tests.c
*/
void	ft_print_order(t_order *order, char *pref);
void	ft_print_orders(t_list *root);
void	ft_lstcut_test(t_sim *sim, t_list **root, t_list *cut, void (*del)(void *, size_t));
void	ft_print_orders_all(t_sim *sim);
int		ft_condition_check(t_sim *sim);

#endif