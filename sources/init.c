#include <../includes/cub3d.h>

int	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(t_map) * 1);
	if (!data->map)
		return (1);
	data->map->map_char = NULL;
	data->map->no_text = NULL;
	data->map->so_text = NULL;
	data->map->we_text = NULL;
	data->map->ea_text = NULL;
	data->map->nb_line = 0;
	// data->player->flag = 0;
	data->map->rgb_ceiling = ft_calloc(4, sizeof(int));
	if (!data->map->rgb_ceiling)
		return (1);
	data->map->rgb_floor = ft_calloc(4, sizeof(int));
	if (!data->map->rgb_floor)
		return (1);
	data->ray = malloc(sizeof(t_ray) * 1);
	if (!data->ray)
		return (1);
	init_ray_cast(data->ray);
	data->ray->world_map = malloc(sizeof(char *) * 15);
	while (i < 14)
	{
		data->ray->world_map[i] = malloc(sizeof(char) * 25);
		i++;
	}
	return (0);
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
