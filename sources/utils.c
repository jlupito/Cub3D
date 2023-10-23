
#include <../includes/cub3d.h>

void	free_tabs(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (++i < 5)
	{
		if (data->img[i].path)
			free(data->img[i].path);
	}
	if (data->rgb_ceiling[3])
		free(data->rgb_ceiling);
	if (data->rgb_floor[3])
		free(data->rgb_floor);
	if (data->map_char)
		free_tabs(data->map_char);
	// if (data->ray->world_map)
	// 	free_tabs(data->ray->world_map);
	if (data->ray)
		free(data->ray);
	// if (data->img)
	// 	free(data->img);
	// if (data)
	// 	free(data);
}

void	print_map(t_data *data)
{
	int	i;

	i = -1;
	printf("text: %s\n", data->img[1].path);
	printf("text: %s\n", data->img[2].path);
	printf("text: %s\n", data->img[3].path);
	printf("text: %s\n", data->img[4].path);
	while (++i < 3)
		printf("rgb_ceil: %d\n", data->rgb_ceiling[i]);
	i = -1;
	while (++i < 3)
		printf("rgb_floor: %d\n", data->rgb_floor[i]);
	i = 0;
	while (data->map_char[i])
	{
		printf("map: %s\n", data->map_char[i]);
		i++;
	}
}

int	text_colors_filled(t_data *data)
{
	if (!data->img[1].path || !data->img[1].path || !data->img[1].path
		|| !data->img[1].path)
		return (1);
	if (!data->rgb_ceiling[3] || !data->rgb_floor[3])
		return (1);
	return (0);
}
