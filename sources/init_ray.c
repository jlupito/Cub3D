#include <../includes/cub3d.h>

void	init_ray_cast(t_data *data)
{
	data->ray->pos_x = 0;
	data->ray->pos_y = 0;
	data->ray->dir_x = 0;
	data->ray->dir_y = 0;
	data->ray->plane_x = 0;
	data->ray->plane_y = 0.66;
	data->ray->ray_dir_x = 0;
	data->ray->ray_dir_y = 0;
	data->ray->camera_x = 0;
	data->ray->map_x = 0;
	data->ray->map_y = 0;
	data->ray->side_dist_x = 0;
	data->ray->side_dist_y = 0;
	data->ray->delta_dist_x = 0;
	data->ray->delta_dist_y = 0;
	data->ray->step_x = 0;
	data->ray->hit = 0;
	data->ray->side = 0;
	data->ray->perp_wall_dist = 0;
	data->ray->line_height = 0;
	data->ray->draw_end = 0;
	data->ray->world_map = NULL;
	data->ray->old_dir_x = 0;
	data->ray->old_plane_x = 0;
}
