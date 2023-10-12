
#include <../includes/cub3d.h>

int	handle_keypress(int keysym, t_data *cub)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
		cub->win_ptr = NULL;
	}
	// if (keysym == XK_Left)
	// if (keysym == XK_Right)
	// if (keysym == XK_Up)
	// if (keysym == XK_Down)
	return (0);
}

int	handle_buttonpress(t_data *cub)
{
	// int	i;

	// i = 0;
	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	cub->win_ptr = NULL;
	mlx_destroy_image(cub->mlx_ptr, cub->mlx_img);
	mlx_destroy_display(cub->mlx_ptr);
	free(cub->mlx_ptr);
	exit (0);
}
