
#include <../includes/cub3d.h>

void	img_pix_put(t_data *cub, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = cub->bpp - 8;
	pixel = cub->addr + (y * cub->line_len + x * (cub->bpp / 8));
	while (i >= 0)
	{
		if (cub->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (cub->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_background(t_data *cub, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(cub, j++, i, color);
		++i;
	}
}

int	render(t_data *cub)
{	
	if (cub->win_ptr == NULL)
		return (-1);
	render_background(cub, BLACK_PIXEL);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mlx_img, 0, 0);
	return (0);
}

int	window(t_data cub)
{
	cub.mlx_ptr = mlx_init();
	if (!cub.mlx_ptr)
		return (-1);
	cub.win_ptr = mlx_new_window(cub.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub");
	if (!cub.win_ptr)
		return (free(cub.win_ptr), -1);
	cub.mlx_img = mlx_new_image(cub.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	cub.addr = mlx_get_data_addr(cub.mlx_img, &cub.bpp,
			&cub.line_len, &cub.endian);
	mlx_loop_hook(cub.mlx_ptr, &render, &cub);
	mlx_hook(cub.win_ptr, KeyPress, KeyPressMask, handle_keypress, &cub);
	mlx_hook(cub.win_ptr, 17, 0, handle_buttonpress, &cub);
	mlx_loop(cub.mlx_ptr);
	mlx_destroy_image(cub.mlx_ptr, cub.mlx_img);
	mlx_destroy_display(cub.mlx_ptr);
	free(cub.mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	cub;
	int		i;

	i = 0;
	/* PARSING
	if (argc != 2)
	{
		error_message(4);
		return (-1);
	}
	else if (check_map(argv[1]) == -1)
		return (-1);
	fill_map(argv[1], &cub);*/
	window(cub);
	return (0);
}
