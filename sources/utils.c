
#include <../includes/cub3d.h>

int	init_data(t_data *data)
{
	data->map = malloc(sizeof(t_map) * 1);
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
	if (data->map->no_text)
		free(data->map->no_text);
	if (data->map->so_text)
		free(data->map->so_text);
	if (data->map->we_text)
		free(data->map->we_text);
	if (data->map->ea_text)
		free(data->map->ea_text);
	if (data->map->rgb_ceiling[3])
		free(data->map->rgb_ceiling);
	if (data->map->rgb_floor[3])
		free(data->map->rgb_floor);
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
	i = 0;
	while (data->map->map[i])
	{
		printf("map: %s\n", data->map->map[i]);
		i++;
	}
}

int	text_colors_filled(t_data *data)
{
	if (!data->map->no_text || !data->map->so_text || !data->map->ea_text
		|| !data->map->we_text)
		return (1);
	if (!data->map->rgb_ceiling[3] || !data->map->rgb_floor[3])
		return (1);
	return (0);
}