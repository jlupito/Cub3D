
#include <../includes/cub3d.h>

int	game_loop(t_data *data)
{
	int	i;

	i = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win_ptr)
		return (free(data->win_ptr), EXIT_FAILURE);
	while (i < 5)
	{
		if (i == 0)
			data->img[i].img_ptr = mlx_new_image(data->mlx_ptr,
					WIN_WIDTH, WIN_HEIGHT);
		else
			data->img[i].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img[i].path, &data->img[i].width, &data->img[i].height);
		data->img[i].addr = mlx_get_data_addr(data->img[i].img_ptr,
			&data->img[i].bpp, &data->img[i].line_len, &data->img[i].endian);
		i++;
	}
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data->win_ptr, 17, 0, handle_buttonpress, &data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img[0].img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}

int	start_game(t_data *data)
{
	// data->ray->world_map[0] = ft_strdup("111111111111111111111111");
	// data->ray->world_map[1] = ft_strdup("100000000000000000000001");
	// data->ray->world_map[2] = ft_strdup("100000000000000000000001");
	// data->ray->world_map[3] = ft_strdup("100000222220000303030001");
	// data->ray->world_map[4] = ft_strdup("100000200020000000000001");
	// data->ray->world_map[5] = ft_strdup("100000200020000300030001");
	// data->ray->world_map[6] = ft_strdup("100000220220000303030001");
	// data->ray->world_map[7] = ft_strdup("100000000000000000000001");
	// data->ray->world_map[8] = ft_strdup("144444444000000000000001");
	// data->ray->world_map[9] = ft_strdup("140400004000000000000001");
	// data->ray->world_map[10] = ft_strdup("140000504000000000000001");
	// data->ray->world_map[11] = ft_strdup("140444444000000000000001");
	// data->ray->world_map[12] = ft_strdup("140000000000000000000001");
	// data->ray->world_map[13] = ft_strdup("111111111111111111111111");
	// data->ray->world_map[14] = NULL;
	
	data->ray->pos_x = 14;
	data->ray->pos_y = 8;  //x and y start position
	data->ray->dir_x = -1;
	data->ray->dir_y = 0; //initial direction vector

	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	// if (check_args(ac, av))
	// 	return (EXIT_FAILURE);
	if (init_data(&data))
		return (free_all(&data), EXIT_FAILURE);
	if (save_data(av[1], &data, 0))
		return (free_all(&data), EXIT_FAILURE);
	// if (save_data(av[1], data, 1))
	// 	return (free_all(data), EXIT_FAILURE);
	start_game(&data);
	game_loop(&data);
	// print_map(data);
	free_all(&data);
	return (0);
}
