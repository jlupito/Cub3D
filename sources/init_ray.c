#include <../includes/cub3d.h>

void	init_ray_cast(t_ray *ray)
{
	ray->pos_x = 0;
	ray->pos_y = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0.66;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->camera_x = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->step_x = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->perp_wall_dist = 0;
	ray->line_height = 0;
	ray->draw_end = 0;
	ray->world_map = NULL;
	ray->old_dir_x = 0;
	ray->old_plane_x = 0;
}
