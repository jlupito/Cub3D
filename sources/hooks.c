
#include <../includes/cub3d.h>

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	// if (keysym == XK_Left)
	// if (keysym == XK_Right)
	// if (keysym == XK_Up)
	// if (keysym == XK_Down)
	return (0);
}

int	handle_buttonpress(t_data *data)
{
	// int	i;

	// i = 0;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
}
