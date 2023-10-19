
#include <../includes/cub3d.h>

int	get_color(t_ray *ray)
{
	int		position;
	// char	*tmp;
	int		color;

	printf("y: %d, x: %d\n", ray->map_y, ray->map_x);
	printf("char: %c\n", ray->world_map[ray->map_y][ray->map_x]);
	// tmp = ray->world_map[ray->map_y][ray->map_x];
	position = 0;
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
	if (ray->side == 1)
		color = color / 2;
	return (color);
}
