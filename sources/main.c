/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:06 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/08 13:47:08 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av))
		return (EXIT_FAILURE);
	if (init_data(&data))
		return (free_all(&data), EXIT_FAILURE);
	if (save_data(av[1], &data))
		return (free_all2(&data), EXIT_FAILURE);
	if (save_map(av[1], &data))
		return (free_all2(&data), EXIT_FAILURE);
	if (parsing(&data))
		return (free_all(&data), EXIT_FAILURE);
	if (game_init(&data))
		return (free_all(&data), EXIT_FAILURE);
	game_loop(&data);
	return (EXIT_SUCCESS);
}
