#include <../includes/cub3d.h>

int	init_data(t_data *data)
{
	int	i;

	data->nb_line = 0;
	data->player = 0;
	data->rgb_ceiling = ft_calloc(4, sizeof(int));
	if (!data->rgb_ceiling)
		return (EXIT_FAILURE);
	data->rgb_floor = ft_calloc(4, sizeof(int));
	if (!data->rgb_floor)
		return (EXIT_FAILURE);
	data->ray = malloc(sizeof(t_ray) * 1);
	if (!data->ray)
		return (EXIT_FAILURE);
	init_ray_cast(data->ray);
	i = 0;
	while (i < 5)
	{
		data->img[i].path = NULL;
		data->img[i].addr = NULL;
		i++;
	}
	return (EXIT_SUCCESS);
}

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
	ray->tex_img = 0;
	ray->tex_height = 0;
	ray->tex_incr_y = 0;
	ray->step_tex = 0;
	ray->tex_pos = 0;
	ray->tex_num = 0;
	ray->tex_width = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->wall_x = 0;
}
