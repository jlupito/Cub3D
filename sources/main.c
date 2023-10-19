
#include <../includes/cub3d.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > WIN_HEIGHT - 1 || x < 0 || x > WIN_WIDTH - 1)
		return ;
	pixel = (img->addr + (y * img->line_len + x * \
		(img->bpp / 8)));
	*(unsigned int *)pixel = color;
}

void	draw_line(t_ray *ray, t_data *data, int x, int color)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
		my_mlx_pixel_put(data->img, x, y++, color);
	while (y < ray->draw_end)
		my_mlx_pixel_put(data->img, x, y++, color);
	while (y < WIN_HEIGHT)
		my_mlx_pixel_put(data->img, x, y++, color);
}

int	render(t_data *data)
{	
	int	x;

	x = 0;
	printf("tu arrives ici?\n");
	printf("cam x apres: %f\n", data->ray->camera_x);
	printf("pos x apres: %f\n", data->ray->pos_x);
	while (x < WIN_WIDTH)
	{
		ray_throw(data, x);
		step_side_dist(data);
		perform_dda(data);
		prep_drawing(data);
		draw_line(data->ray, data, x, get_color(data->ray));
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
	return (0);
}

int	game_loop(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win_ptr)
		return (free(data->win_ptr), EXIT_FAILURE);
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		return (1);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data->win_ptr, 17, 0, handle_buttonpress, &data);
	printf("cam x avant: %f\n", data->ray->camera_x);
	printf("pos x avant: %f\n", data->ray->pos_x);
	mlx_loop_hook(data->mlx_ptr, &render, &data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}

int	start_game(t_data *data)
{
	data->ray->world_map[0] = ft_strdup("111111111111111111111111");
	data->ray->world_map[1] = ft_strdup("100000000000000000000001");
	data->ray->world_map[2] = ft_strdup("100000000000000000000001");
	data->ray->world_map[3] = ft_strdup("100000222220000303030001");
	data->ray->world_map[4] = ft_strdup("100000200020000000000001");
	data->ray->world_map[5] = ft_strdup("100000200020000300030001");
	data->ray->world_map[6] = ft_strdup("100000220220000303030001");
	data->ray->world_map[7] = ft_strdup("100000000000000000000001");
	data->ray->world_map[8] = ft_strdup("144444444000000000000001");
	data->ray->world_map[9] = ft_strdup("140400004000000000000001");
	data->ray->world_map[10] = ft_strdup("140000504000000000000001");
	data->ray->world_map[11] = ft_strdup("140444444000000000000001");
	data->ray->world_map[12] = ft_strdup("140000000000000000000001");
	data->ray->world_map[13] = ft_strdup("111111111111111111111111");
	data->ray->world_map[14] = NULL;
	
	data->ray->pos_x = 14;
	data->ray->pos_y = 8;  //x and y start position
	data->ray->dir_x = -1;
	data->ray->dir_y = 0; //initial direction vector
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	(void)ac;
	(void)av;
	// if (check_args(ac, av))
	// 	return (EXIT_FAILURE);
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (EXIT_FAILURE);
	if (init_data(data))
		return (free_all(data), EXIT_FAILURE);
	// if (save_data(av[1], data, 0))
	// 	return (free_all(data), EXIT_FAILURE);
	// if (save_data(av[1], data, 1))
	// 	return (free_all(data), EXIT_FAILURE);
	start_game(data);
	game_loop(data);
	// print_map(data);
	free_all(data);
	return (0);
}
