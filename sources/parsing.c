#include <../includes/cub3d.h>

int	check_closed_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map_char[++y])
	{
		x = -1;
		while (data->map_char[y][++x])
		{
			if (data->map_char[y][x] == 0)
			{
				if ((is_nothing(data->map_char[y - 1][x]))
				|| (is_nothing(data->map_char[y + 1][x]))
				|| (is_nothing(data->map_char[y][x - 1]))
				|| (is_nothing(data->map_char[y][x + 1]))
				|| (is_nothing(data->map_char[y + 1][x + 1]))
				|| (is_nothing(data->map_char[y + 1][x - 1]))
				|| (is_nothing(data->map_char[y - 1][x + 1]))
				|| (is_nothing(data->map_char[y - 1][x - 1]))
				|| (y == 0) || (y == len_tab(data->map_char)))
					return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	check_elements_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map_char[++y])
	{
		x = -1;
		while (data->map_char[y][++x])
		{
			if ((data->map_char[y][x] != 'N')
				&& (data->map_char[y][x] != 'S')
				&& (data->map_char[y][x] != 'E')
				&& (data->map_char[y][x] != 'W')
				&& (data->map_char[y][x] != 1)
				&& (data->map_char[y][x] != 0)
				&& (data->map_char[y][x] != ' '))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	count_map_elements(t_data *data) // OK - a voir si faite par JLO
{
	int	x;
	int	y;
	int	player;

	x = -1;
	y = -1;
	player = 0;
	while (data->map_char[++y])
	{
		while (data->map_char[y][++x])
		{
			if ((data->map_char[y][x] == 'N')
				&& (data->map_char[y][x] == 'S')
				&& (data->map_char[y][x] == 'E')
				&& (data->map_char[y][x] == 'W'))
				player++;
		}
	}
	if ((player != 1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parsing_textures(t_data *data) // si espace ou tab ?
{
	int	i;

	i = 0;
	while (++i < 5)
	{
		if (!(data->img[i].path))
			return (EXIT_FAILURE);
		if (ft_strncmp(data->img[i].path, "NO ./", 5)
			|| ft_strncmp(data->img[i].path, "SO ./", 5)
			|| ft_strncmp(data->img[i].path, "WE ./", 5)
			|| ft_strncmp(data->img[i].path, "EA ./", 5))
			return (EXIT_FAILURE);
		if (!test_path_texture(data->img[i].path))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parsing(t_data *data)
{
	if (check_empty_line(data))
		return (ft_error("---MAP HAS EMPTY LINE---\n"), EXIT_FAILURE);
	if (!check_closed_map(data))
		return (ft_error("---MAP IS NOT CLOSED---\n"), EXIT_FAILURE);
	if (!check_elements_map(data))
		return (ft_error("---UNAPPROVED MAP COMPONENT---\n"), EXIT_FAILURE);
	if (!count_map_elements(data))
		return (ft_error("---WRONG NUMBER OF PLAYERS---\n"), EXIT_FAILURE);
	if (!parsing_textures(data) || ! parsing_colors(data))
		return (ft_error("---ERROR IN TEXTURES & COLORS---\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
