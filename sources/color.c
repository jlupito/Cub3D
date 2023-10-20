
#include <../includes/cub3d.h>

int	get_color(t_data *data, int x, int y, int i)
{
	return (*(int *)(data->img[i].addr + (y * data->img[i].line_len + x
			* (data->img[i].bpp / 8))));
}
