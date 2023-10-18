
#include <../includes/cub3d.h>

int	get_color(t_data *data)
{
	int	position;
	int	color;

	position = data->world_map[data->ray->map_x][data->ray->map_y];
	if (mapValue == 1)
		color = RGB_Red;
	else if (mapValue == 2)
		color = GREEN;
	else if (mapValue == 3)
		color = BLUE;
	else if (mapValue == 4)
		color = WHITE;
	else
		color = YELLOW;
	if (side == 1)
		color = color / 2;
	return (color);
}
