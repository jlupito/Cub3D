
#include <../includes/cub3d.h>

int	text_colors_filled(t_data *data)
{
	if (!data->img[1].path || !data->img[2].path || !data->img[3].path
		|| !data->img[4].path)
		return (1);
	if (!data->rgb_ceiling[3] || !data->rgb_floor[3])
		return (1);
	return (0);
}

int	text_filled(t_data *data)
{
	if (!data->img[1].path || !data->img[2].path || !data->img[3].path
		|| !data->img[4].path)
		return (1);
	return (0);
}

int	colors_filled(t_data *data)
{
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
