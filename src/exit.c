#include "simulator.h"

int	ft_err_exit(t_sim *sim, char *msg, int err)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(msg, 2);
	free(sim);
	exit(err);
}