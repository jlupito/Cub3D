
#include <../includes/cub3d.h>

int	check_args(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (EXIT_FAILURE);
	i = 0;
	while (argv[i] != '.' && argv[i])
		i++;
	if (argv[i + 1] == 'c' && argv[i + 2] == 'u'
		&& argv[i + 3] == 'b' && argv[i + 4] == '\0')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
