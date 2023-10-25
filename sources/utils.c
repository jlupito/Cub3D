
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

	i = -1;
	if (data->rgb_ceiling[3])
		free(data->rgb_ceiling);
	if (data->rgb_floor[3])
		free(data->rgb_floor);
	if (data->map_char)
		free_tabs(data->map_char);
	if (data->ray)
		free(data->ray);
	while (++i < 5)
	{
		if (data->img[i].path)
			free(data->img[i].path);
	}
}

void	close_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(data->mlx_ptr, data->img[i].img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	text_colors_filled(t_data *data)
{
	if (!data->img[1].path || !data->img[2].path || !data->img[3].path
		|| !data->img[4].path)
		return (1);
	if (!data->rgb_ceiling[3] || !data->rgb_floor[3])
		return (1);
	return (0);
}

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}


// void	print_map(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	printf("text: %s\n", data->img[1].path);
// 	printf("text: %s\n", data->img[2].path);
// 	printf("text: %s\n", data->img[3].path);
// 	printf("text: %s\n", data->img[4].path);
// 	while (++i < 3)
// 		printf("rgb_ceil: %d\n", data->rgb_ceiling[i]);
// 	i = -1;
// 	while (++i < 3)
// 		printf("rgb_floor: %d\n", data->rgb_floor[i]);
// 	i = 0;
// 	while (data->map_char[i])
// 	{
// 		printf("map: %s\n", data->map_char[i]);
// 		i++;
// 	}
// }