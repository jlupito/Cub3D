
#include <../includes/cub3d.h>

void	ray_throw(t_data *data, int x)
{
	data->ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	data->ray->ray_dir_x = data->ray->dir_x + data->ray->plane_x
		* data->ray->camera_x;
	data->ray->ray_dir_y = data->ray->dir_y + data->ray->plane_y
		* data->ray->camera_x;
	data->ray->map_x = (int)data->ray->pos_x;
	data->ray->map_y = (int)data->ray->pos_y;
	if (data->ray->ray_dir_x == 0)
		data->ray->delta_dist_x = INT_MAX;
	else
		data->ray->delta_dist_x = fabs(1 / data->ray->ray_dir_x);
	if (data->ray->ray_dir_y == 0)
		data->ray->delta_dist_y = INT_MAX;
	else
		data->ray->delta_dist_y = fabs(1 / data->ray->ray_dir_y);
}

void	step_side_dist(t_data *data)
{
	data->ray->hit = 0;
	if (data->ray->ray_dir_x < 0)
	{
		data->ray->step_x = -1;
		data->ray->side_dist_x = (data->ray->pos_x - data->ray->map_x)
			* data->ray->delta_dist_x;
	}
	else
	{
		data->ray->step_x = 1;
		data->ray->side_dist_x = (data->ray->map_x + 1.0 - data->ray->pos_x)
			* data->ray->delta_dist_x;
	}
	if (data->ray->ray_dir_y < 0)
	{
		data->ray->step_y = -1;
		data->ray->side_dist_y = (data->ray->pos_y - data->ray->map_y)
			* data->ray->delta_dist_y;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->side_dist_y = (data->ray->map_y + 1.0 - data->ray->pos_y)
			* data->ray->delta_dist_y;
	}
}

void	perform_dda(t_data *data)
{
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
		if (data->map_char[data->ray->map_y][data->ray->map_x] > 0)
			data->ray->hit = 1;
	}
	if (data->ray->side == 0)
		data->ray->perp_wall_dist = (data->ray->side_dist_x
				- data->ray->delta_dist_x);
	else
		data->ray->perp_wall_dist = (data->ray->side_dist_y
				- data->ray->delta_dist_y);
}

void	prep_drawing(t_data *data)
{
	data->ray->line_height = (int)(WIN_HEIGHT / data->ray->perp_wall_dist);
	data->ray->draw_start = -data->ray->line_height / 2 + WIN_HEIGHT / 2;
	if (data->ray->draw_start < 0)
		data->ray->draw_start = 0;
	data->ray->draw_end = data->ray->line_height / 2 + WIN_HEIGHT / 2;
	if (data->ray->draw_end >= WIN_HEIGHT)
		data->ray->draw_end = WIN_HEIGHT - 1;
	if (data->ray->side == 0 && data->ray->ray_dir_x < 0)
		data->ray->tex_img = 1;
	else if (data->ray->side == 0 && data->ray->ray_dir_x > 0)
		data->ray->tex_img = 2;
	else if (data->ray->side == 1 && data->ray->ray_dir_y < 0)
		data->ray->tex_img = 3;
	else if (data->ray->side == 1 && data->ray->ray_dir_y > 0)
		data->ray->tex_img = 4;
}

void	calc_texture(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->wall_x = data->ray->pos_y + data->ray->perp_wall_dist
			* data->ray->dir_y;
	else
		data->ray->wall_x = data->ray->pos_x + data->ray->perp_wall_dist
			* data->ray->dir_x;
	data->ray->wall_x -= floor(data->ray->wall_x);
	data->ray->tex_x = (int)(data->ray->wall_x * (double)TEX_WIDTH);
	if ((data->ray->side == 0 && data->ray->dir_x > 0)
		|| (data->ray->side == 1 && data->ray->dir_y < 0))
		data->ray->tex_x = TEX_WIDTH - data->ray->tex_x - 1;
	data->ray->step_tex = 1.0 * TEX_HEIGHT / data->ray->line_height;
	data->ray->tex_pos = (data->ray->draw_start - WIN_HEIGHT / 2
			+ data->ray->line_height / 2) * data->ray->step_tex;
}
