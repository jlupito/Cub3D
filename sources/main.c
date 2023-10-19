
#include <../includes/cub3d.h>

// void	img_pix_put(t_data *cub, int x, int y, int color)
// {
// 	char	*pixel;
// 	int		i;

// 	i = cub->bpp - 8;
// 	pixel = cub->addr + (y * cub->line_len + x * (cub->bpp / 8));
// 	while (i >= 0)
// 	{
// 		if (cub->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		else
// 			*pixel++ = (color >> (cub->bpp - 8 - i)) & 0xFF;
// 		i -= 8;
// 	}
// }

// void	render_background(t_data *cub, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WIN_HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WIN_WIDTH)
// 			img_pix_put(cub, j++, i, color);
// 		++i;
// 	}
// }

// int	render(t_data *cub)
// {
// 	if (cub->win_ptr == NULL)
// 		return (-1);
// 	render_background(cub, BLACK_PIX);
// 	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mlx_img, 0, 0);
// 	return (0);
// }

// int	start_game(t_data *data)
// {
// 	data->mlx_ptr = mlx_init();
// 	if (!data->mlx_ptr)
// 		return (EXIT_FAILURE);
// 	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
// 	if (!data->win_ptr)
// 		return (free(data->win_ptr), EXIT_FAILURE);
// 	data->mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
// 	data->img->addr = mlx_get_data_addr(data->mlx_img, &data->img->bpp,
// 			&data->img->line_len, &data->img->endian);
// 	mlx_loop_hook(data->mlx_ptr, &render, &data);
// 	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
// 	mlx_hook(data->win_ptr, 17, 0, handle_buttonpress, &data);
// 	mlx_loop(data->mlx_ptr);
// 	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
// 	mlx_destroy_display(data->mlx_ptr);
// 	free(data->mlx_ptr);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_data	*data;

	if (check_args(ac, av))
		return (EXIT_FAILURE);
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (EXIT_FAILURE);
	if (init_data(data))
		return (free_all(data), EXIT_FAILURE);
	if (save_data(av[1], data, 0))
		return (free_all(data), EXIT_FAILURE);
	if (save_data(av[1], data, 1))
		return (free_all(data), EXIT_FAILURE);
	if (parsing(data))
		return (free_all(data), EXIT_FAILURE);
	// start_game(data);
	print_map(data);
	free_all(data);
	return (0);
}
