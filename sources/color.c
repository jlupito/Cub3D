
#include <../includes/cub3d.h>

int	get_color(t_data *data)
{
	int	position;
	int	color;

	position = data->ray->world_map[data->ray->map_x][data->ray->map_y];
	if (position == 1)
		color = RED;
	else if (position == 2)
		color = GREEN;
	else if (position == 3)
		color = BLUE;
	else if (position == 4)
		color = WHITE;
	else
		color = YELLOW;
	if (data->ray->side == 1)
		color = color / 2;
	return (color);
}
