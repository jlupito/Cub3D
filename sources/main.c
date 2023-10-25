
#include <../includes/cub3d.h>

int	game_loop(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, handle_buttonpress, data);
	render(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	game_init(t_data *data)  // PROTEGER LA MLX : si on perd les droits sur une texture
{
	int	i;

	i = -1;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), EXIT_FAILURE);
	// printf("pos x: %f, pos y : %f\n", data->ray->pos_x, data->ray->pos_y);
	while (++i < 5)
	{
		if (i == 0)
			data->img[i].img_ptr = mlx_new_image(data->mlx_ptr,
					WIN_WIDTH, WIN_HEIGHT);
		else
			data->img[i].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
					data->img[i].path, &data->img[i].width, &data->img[i].height);
		data->img[i].addr = mlx_get_data_addr(data->img[i].img_ptr,
				&data->img[i].bpp, &data->img[i].line_len, &data->img[i].endian);
		// printf("img.height [%d]\n", data->img[i].height);
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
	// if (game_init(&data))
	// 	return (free_all(&data), EXIT_FAILURE);
	// game_loop(&data);
	return (EXIT_SUCCESS);
}
