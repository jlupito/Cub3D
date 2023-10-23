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

int	init_player_pos(char *str, int y, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == 'N' || str[i] == 'W' || str[i] == 'E'
				|| str[i] == 'S') && !data->player)
		{
			data->ray->pos_x = i;
			data->ray->pos_y = y;
			data->ray->plane_x = 0;
			data->ray->plane_y = 0.66;
			if (str[i] == 'N')
			{
				data->ray->dir_x = i;
				data->ray->dir_y = y - 1;
			}
			else if (str[i] == 'W')
			{
				data->ray->dir_x = i - 1;
				data->ray->dir_y = y;
			}
			else if (str[i] == 'E')
			{
				data->ray->dir_x = i;
				data->ray->dir_y = y - 1;
			}
			else if (str[i] == 'S')
			{
				data->ray->dir_x = i + 1;
				data->ray->dir_y = y;
			}
			data->player++;
			return (EXIT_SUCCESS);
		}
		else if ((str[i] == 'N' || str[i] == 'W' || str[i] == 'E'
				|| str[i] == 'S') && data->player)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_ray_cast(t_ray *ray)
{
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
	ray->draw_start = 0;
	ray->old_dir_x = 0;
	ray->old_plane_x = 0;
	ray->tex_img = 0;
	ray->step_tex = 0;
	ray->tex_pos = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->wall_x = 0;
}
