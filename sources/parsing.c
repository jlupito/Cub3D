#include <../includes/cub3d.h>

int	check_empty_line(t_data *data) // OK
{
	int	y;

	y = -1;
	while (data->map->map_char[++y])
		if (empty_line(data->map->map_char[y]))
			return (1);
	return (SUCCESS);
}

int	check_closed_map(t_data *data) // A REFAIRE
{
	int	x;
	int	y;

	y = -1;
	while (data->map->map_char[++y])
	{
		x = -1;
		while (data->map->map_char[y][++x])
		{
			if (data->map->map_char[y][x] == EMPTY) // si on a un mur 0
			{
				// si on est sur la premiere ou la derniere ligne de la map
			}
		}
	}

	return (FAILURE);
}

int	check_elements_map(t_data *data) // OK
{
	int	x;
	int	y;

	y = -1;
	while (data->map->map_char[++y])
	{
		x = -1;
		while (data->map->map_char[y][++x])
		{
			if ((data->map->map_char[y][x] != 'N')
				&& (data->map->map_char[y][x] != 'S')
				&& (data->map->map_char[y][x] != 'E')
				&& (data->map->map_char[y][x] != 'W')
				&& (data->map->map_char[y][x] != WALL)
				&& (data->map->map_char[y][x] != EMPTY)
				&& (data->map->map_char[y][x] != ' '))
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	count_map_elements(t_data *data) // OK
{
	int	x;
	int	y;
	int player;

	x = -1;
	y = -1;
	player = 0;
	while (data->map->map_char[++y])
	{
		while (data->map->map_char[y][++x])
		{
			if ((data->map->map_char[y][x] == 'N')
				&& (data->map->map_char[y][x] == 'S')
				&& (data->map->map_char[y][x] == 'E')
				&& (data->map->map_char[y][x] == 'W'))
				player++;
		}
	}
	if ((player > 1) || (player < 1))
		return (FAILURE);
	return (SUCCESS);
}

int	parsing(t_data *data)
{
	if (check_empty_line(data))
		ft_error("---MAP HAS EMPTY LINE---\n");
	if (!check_closed_map(data))
		ft_error("---MAP IS NOT CLOSED---\n");
	if (!check_elements_map(data))
		ft_error("---UNAPPROVED MAP COMPONENT---\n");
	if (!count_map_elements(data))
		ft_error("---WRONG NUMBER OF PLAYERS---\n");
	return (SUCCESS);
}
