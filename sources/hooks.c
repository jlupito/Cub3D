
#include <../includes/cub3d.h>

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == XK_Left)
	{
		data->ray->old_dir_x = data->ray->dir_x;
		data->ray->dir_x = data->ray->dir_x * cos(ROTSPEED) - data->ray->dir_y * sin(ROTSPEED);
		data->ray->dir_y = data->ray->old_dir_x * sin(ROTSPEED) + data->ray->dir_y * cos(ROTSPEED);
		data->ray->old_plane_x = data->ray->plane_x;
		data->ray->plane_x = data->ray->plane_x * cos(ROTSPEED) - data->ray->plane_y * sin(ROTSPEED);
		data->ray->plane_y = data->ray->old_plane_x * sin(ROTSPEED) + data->ray->plane_y * cos(ROTSPEED);
	}
	if (keysym == XK_Right)
	{
		data->ray->old_dir_x = data->ray->dir_x;
		data->ray->dir_x = data->ray->dir_x * cos(-ROTSPEED) - data->ray->dir_y * sin(-ROTSPEED);
		data->ray->dir_y = data->ray->old_dir_x * sin(-ROTSPEED) + data->ray->dir_y * cos(-ROTSPEED);
		data->ray->old_plane_x = data->ray->plane_x;
		data->ray->plane_x = data->ray->plane_x * cos(-ROTSPEED) - data->ray->plane_y * sin(-ROTSPEED);
		data->ray->plane_y = data->ray->old_plane_x * sin(-ROTSPEED) + data->ray->plane_y * cos(-ROTSPEED);
	}
	if (keysym == XK_Up)
	{
		if (data->ray->world_map[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				+ data->ray->dir_x * MOVESPEED)] == false)
			data->ray->pos_x += data->ray->dir_x * MOVESPEED;
		if (data->ray->world_map[(int)(data->ray->pos_y + data->ray->dir_y
				* MOVESPEED)][(int)(data->ray->pos_x)] == false)
			data->ray->pos_y += data->ray->dir_y * MOVESPEED;
	}
	if (keysym == XK_Down)
	{
		if (data->ray->world_map[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				- data->ray->dir_x * MOVESPEED)] == false)
			data->ray->pos_x -= data->ray->dir_x * MOVESPEED;
		if (data->ray->world_map[(int)(data->ray->pos_y + data->ray->dir_y
				* MOVESPEED)][(int)(data->ray->pos_x)] == false)
			data->ray->pos_y -= data->ray->dir_y * MOVESPEED;
	}
	return (0);
}

int	handle_buttonpress(t_data *data)
{
	// int	i;

	// i = 0;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
}
