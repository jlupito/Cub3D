
#include <../includes/cub3d.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av))
		return (EXIT_FAILURE);
	if (init_data(&data))
		return (free_all(&data), EXIT_FAILURE);
	if (save_data(av[1], &data, 0))
		return (free_all2(&data), EXIT_FAILURE);
	if (save_data(av[1], &data, 1))
		return (free_all2(&data), EXIT_FAILURE);
	if (parsing(&data))
		return (free_all(&data), EXIT_FAILURE);
	print_map(&data);
	// print_map(&data);
	// if (game_init(&data))
	// 	return (free_all(&data), EXIT_FAILURE);
	// game_loop(&data);
	return (EXIT_SUCCESS);
}

/*


*/
