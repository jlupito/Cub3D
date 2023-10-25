
#include <../includes/cub3d.h>

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		free_all(data);
		close_all(data);
		exit (0);
	}
	if (keysym == XK_Right)
	{
		data->ray->old_dir_x = data->ray->dir_x;
		data->ray->dir_x = (data->ray->dir_x * cos(ROTSPEED)) - \
			(data->ray->dir_y * sin(ROTSPEED));
		data->ray->dir_y = (data->ray->old_dir_x * sin(ROTSPEED)) + \
			(data->ray->dir_y * cos(ROTSPEED));
		data->ray->old_plane_x = data->ray->plane_x;
		data->ray->plane_x = (data->ray->plane_x * cos(ROTSPEED)) - \
			(data->ray->plane_y * sin(ROTSPEED));
		data->ray->plane_y = (data->ray->old_plane_x * sin(ROTSPEED)) + \
			(data->ray->plane_y * cos(ROTSPEED));
	}
	if (keysym == XK_Left)
	{
		data->ray->old_dir_x = data->ray->dir_x;
		data->ray->dir_x = (data->ray->dir_x * cos(-ROTSPEED)) - \
			(data->ray->dir_y * sin(-ROTSPEED));
		data->ray->dir_y = (data->ray->old_dir_x * sin(-ROTSPEED)) + \
			(data->ray->dir_y * cos(-ROTSPEED));
		data->ray->old_plane_x = data->ray->plane_x;
		data->ray->plane_x = (data->ray->plane_x * cos(-ROTSPEED)) - \
			(data->ray->plane_y * sin(-ROTSPEED));
		data->ray->plane_y = (data->ray->old_plane_x * sin(-ROTSPEED)) + \
			(data->ray->plane_y * cos(-ROTSPEED));
	}
	if (keysym == XK_w)
	{
		printf("pos_x dans w [%d]\n", data->map_char[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				+ data->ray->dir_x * MOVESPEED)]);
		printf("pos_y dans w [%d]\n", data->map_char[(int)(data->ray->pos_y + data->ray->dir_y
				* MOVESPEED)][(int)(data->ray->pos_x)]);
		if (data->map_char[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				+ data->ray->dir_x * MOVESPEED)] != 1)
			data->ray->pos_x += data->ray->dir_x * MOVESPEED;
		if (data->map_char[(int)(data->ray->pos_y + data->ray->dir_y
				* MOVESPEED)][(int)(data->ray->pos_x)] != 1)
			data->ray->pos_y += data->ray->dir_y * MOVESPEED;
	}
	if (keysym == XK_s)
	{
		printf("pos_x dans s [%d]\n", data->map_char[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				- data->ray->dir_x * MOVESPEED)]);
		printf("pos_y dans s [%d]\n", data->map_char[(int)(data->ray->pos_y + data->ray->dir_y
				* MOVESPEED)][(int)(data->ray->pos_x)]);
		if (data->map_char[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				- data->ray->dir_x * MOVESPEED)] != 1)
			data->ray->pos_x -= data->ray->dir_x * MOVESPEED;
		if (data->map_char[(int)(data->ray->pos_y + data->ray->dir_y
				* MOVESPEED)][(int)(data->ray->pos_x)] != 1)
			data->ray->pos_y -= data->ray->dir_y * MOVESPEED;
	}
	if (keysym == XK_d)
	{
		if (data->map_char[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				+ data->ray->plane_x * MOVESPEED)] != 1)
			data->ray->pos_x += data->ray->plane_x * MOVESPEED;
		if (data->map_char[(int)(data->ray->pos_y + data->ray->plane_y
				* MOVESPEED)][(int)(data->ray->pos_x)] != 1)
			data->ray->pos_y += data->ray->plane_y * MOVESPEED;
	}
	if (keysym == XK_a)
	{
		if (data->map_char[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				- data->ray->plane_x * MOVESPEED)] != 1)
			data->ray->pos_x -= data->ray->plane_x * MOVESPEED;
		if (data->map_char[(int)(data->ray->pos_y + data->ray->plane_y
				* MOVESPEED)][(int)(data->ray->pos_x)] != 1)
			data->ray->pos_y -= data->ray->plane_y * MOVESPEED;
	}
	return (0);
}

int	handle_buttonpress(t_data *data)
{
	free_all(data);
	close_all(data);
	exit (0);
}
