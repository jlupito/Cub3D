
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

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(data, j++, i, color);
		++i;
	}
}

int	render(t_data *data)
{	
	if (data->win_ptr == NULL)
		return (-1);
	while (data->ray->x < WIN_WIDTH)
	{
		data->ray->camera_x = 2 * data->ray->x / (double)WIN_WIDTH - 1;
		data->ray->ray_dir_x = data->ray->dir_x + data->ray->plane_x * data->ray->camera_x;
		data->ray->ray_dir_y = data->ray->dir_y + data->ray->plane_y * data->ray->camera_x;
		data->ray->map_x = (int)data->ray->pos_x;
		data->ray->map_y = (int)data->ray->pos_y;
		if (data->ray->ray_dir_x == 0)
			data->ray->delta_dist_x = 10000;
		else
			data->ray->delta_dist_x = fabs(1 / data->ray->ray_dir_x);
		if (data->ray->ray_dir_y == 0)
			data->ray->delta_dist_y = 10000;
		else
			data->ray->delta_dist_y = fabs(1 / data->ray->ray_dir_y);
		data->ray->hit = 0;
		if (data->ray->ray_dir_x < 0)
		{
			data->ray->step_x = -1;
			data->ray->side_dist_x = (data->ray->pos_x - data->ray->map_x) * data->ray->delta_dist_x;
		}
		else
		{
			data->ray->step_x = 1;
			data->ray->side_dist_x = (data->ray->map_x + 1.0 - data->ray->pos_x) * data->ray->delta_dist_x;
		}
		if(data->ray->ray_dir_y < 0)
		{
			data->ray->step_y = -1;
			data->ray->side_dist_y = (data->ray->pos_y - data->ray->map_y) * data->ray->delta_dist_y;
		}
		else
		{
			data->ray->step_y = 1;
			data->ray->side_dist_y = (data->ray->map_y + 1.0 - data->ray->pos_y) * data->ray->delta_dist_y;
		}
		while (data->ray->hit == 0)
		{
			if (data->ray->side_dist_x < data->ray->side_dist_y)
			{
				data->ray->side_dist_x += data->ray->delta_dist_x;
				data->ray->map_x += data->ray->step_x;
				data->ray->side = 0;
			}
			else
			{
				data->ray->side_dist_y += data->ray->delta_dist_y;
				data->ray->map_y += data->ray->step_y;
				data->ray->side = 1;
			}
		if (data->ray->world_map[data->ray->map_x][data->ray->map_y] > 0)
			data->ray->hit = 1;
		}
		if (data->ray->side == 0)
			data->ray->perp_wall_dist = (data->ray->side_dist_x - data->ray->delta_dist_x);
		else
			data->ray->perp_wall_dist = (data->ray->side_dist_y - data->ray->delta_dist_y);
		data->ray->line_height = (int)(WIN_HEIGHT / data->ray->perp_wall_dist);
		data->ray->draw_start = -data->ray->line_height / 2 + WIN_HEIGHT / 2;
		if (data->ray->draw_start < 0)
			data->ray->draw_start = 0;
		data->ray->draw_end = data->ray->line_height / 2 + WIN_HEIGHT / 2;
		if (data->ray->draw_end >= WIN_HEIGHT)
			data->ray->draw_end = WIN_HEIGHT - 1;
		data->ray->x++;
	}
	// render_background(data, BLACK_PIX);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
	return (0);
}

int	start_game(t_data *data)
{
	data->ray->world_map[24][24]=
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	data->ray->pos_x = 22;
	data->ray->pos_y = 12;  //x and y start position
	data->ray->dir_x = -1;
	data->ray->dir_y = 0; //initial direction vector
  	data->ray->plane_x = 0;
	data->ray->plane_y = 0.66; //the 2d raycaster version of camera plane

  	data->ray->time = 0; //time of current frame
  	data->ray->old_time = 0; //time of previous frame
	
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win_ptr)
		return (free(data->win_ptr), EXIT_FAILURE);
	data->mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	mlx_loop_hook(data->mlx_ptr, &render, &data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data->win_ptr, 17, 0, handle_buttonpress, &data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}

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
	start_game(data);
	// print_map(data);
	free_all(data);
	return (0);
}
