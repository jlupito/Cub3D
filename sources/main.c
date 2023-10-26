
#include <../includes/cub3d.h>

int	game_loop(t_data *data)
{
	render(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, handle_buttonpress, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	game_init(t_data *data)  // AJout des protections sur la MLX
{
	int	i;

	i = -1;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), EXIT_FAILURE);
	while (++i < 5)
	{
		if (i == 0)
		{
			data->img[i].img_ptr = mlx_new_image(data->mlx_ptr,
					WIN_WIDTH, WIN_HEIGHT);
			if (!data->img[i].img_ptr)
				return (free(data->mlx_ptr), EXIT_FAILURE);
		}
		else
		{
			data->img[i].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->img[i].path, &data->img[i].width, &data->img[i].height);
			if (!data->img[i].img_ptr)
			{
				while (i-- >= 0)
					free(data->img[i].img_ptr);
				return (free(data->mlx_ptr), EXIT_FAILURE); // autres images ? a free ? LEAK.
			}
		}
		data->img[i].addr = mlx_get_data_addr(data->img[i].img_ptr,
			&data->img[i].bpp, &data->img[i].line_len, &data->img[i].endian);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av))
		return (EXIT_FAILURE);
	if (init_data(&data))
		return (free_all(&data), EXIT_FAILURE);
	if (save_data(av[1], &data, 0))
		return (free_all(&data), EXIT_FAILURE);
	if (save_data(av[1], &data, 1))
		return (free_all(&data), EXIT_FAILURE);
	if (parsing(&data))
		return (free_all(&data), EXIT_FAILURE);
	if (game_init(&data))
		return (free_all(&data), EXIT_FAILURE);
	game_loop(&data);
	return (EXIT_SUCCESS);
}
