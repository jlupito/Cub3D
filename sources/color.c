
#include <../includes/cub3d.h>

int	get_tex_color(t_data *data, int x, int y, int i)
{
	int	color;

	color = (*(int *)(data->img[i].addr + (y * data->img[i].line_len + x
					* (data->img[i].bpp / 8))));
	return (color);
}

int	get_int_color(int rgb[3])
{
	int	color;

	color = (((rgb[0]) & 0xff) << 16) + \
		(((rgb[1]) & 0xff) << 8) + ((rgb[2]) & 0xff);
	return (color);
}

bool	parsing_colors(t_data *data)  // TEST si on entre autre chose que int (demi parsing ?)
{
	int	i;
	int	j;

	if (!data->rgb_ceiling || !data->rgb_floor)
		return (false);
	i = -1;
	while (++i < 3)
	{
		if ((data->rgb_ceiling[i] < 0)
			|| (data->rgb_ceiling[i]) > 255)
			return (false);
	}
	j = -1;
	while (++j < 3)
	{
		if ((data->rgb_floor[i] < 0)
			|| (data->rgb_floor[i]) > 255)
			return (false);
	}
	return (true);
}
