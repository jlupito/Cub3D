
#include <../includes/cub3d.h>

int	init_data(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (1);
	data->map->map = NULL;
	data->map->no_text = NULL;
	data->map->so_text = NULL;
	data->map->we_text = NULL;
	data->map->ea_text = NULL;
	data->map->nb_line = 0;
	data->map->rgb_ceiling = ft_calloc(4, sizeof(int));
	if (!data->map->rgb_ceiling)
		return (1);
	data->map->rgb_floor = ft_calloc(4, sizeof(int));
	if (!data->map->rgb_floor)
		return (1);
	return (0);
}

void	free_tabs(char **tabs)
{
	int	i;

	i = -1;
	if (!tabs)
		return ;
	while (tabs[++i])
	{
		if (tabs[i])
			free(tabs[i]);
	}
	if (tabs)
		free(tabs);
}

void	free_all(t_data *data)
{
	if (data->map->no_text)
		free(data->map->no_text);
	if (data->map->so_text)
		free(data->map->so_text);
	if (data->map->we_text)
		free(data->map->we_text);
	if (data->map->ea_text)
		free(data->map->ea_text);
	if (data->map->map)
		free_tabs(data->map->map);
	if (data->map)
		free(data->map);
	if (data)
		free(data);
}

void	print_map(t_data *data)
{
	int	i;

	i = -1;
	printf("text: %s\n", data->map->no_text);
	printf("text: %s\n", data->map->so_text);
	printf("text: %s\n", data->map->ea_text);
	printf("text: %s\n", data->map->we_text);
	while (++i < 3)
		printf("rgb_ceil: %d\n", data->map->rgb_ceiling[i]);
	i = -1;
	while (++i < 3)
		printf("rgb_floor: %d\n", data->map->rgb_floor[i]);
	i = -1;
	while (++i < data->map->nb_line)
		printf("map: %s\n", data->map->map[i]);
}
