#include <../includes/cub3d.h>

// les 0 doivent forcement etre entoures par quelque chose (0 ou 1 ou player)
// donc on verifie pour chaque 0, si un 0 a un cote ' ', la map est brechee.
int	check_closed_map(t_data *data) // ok
{
	int	x;
	int	y;

	y = -1;
	while (data->map->map_char[++y])
	{
		x = -1;
		while (data->map->map_char[y][++x])
		{
			if (data->map->map_char[y][x] == EMPTY)
			{
					if ((is_nothing(data->map->map_char[y - 1][x]))
					|| (is_nothing(data->map->map_char[y + 1][x]))
					|| (is_nothing(data->map->map_char[y][x - 1]))
					|| (is_nothing(data->map->map_char[y][x + 1]))
					|| (is_nothing(data->map->map_char[y + 1][x + 1]))
					|| (is_nothing(data->map->map_char[y + 1][x - 1]))
					|| (is_nothing(data->map->map_char[y - 1][x + 1]))
					|| (is_nothing(data->map->map_char[y - 1][x - 1]))
					|| (y == 0) || (y = len_tab(data->map->map_char)))
						return (FAILURE);
			}
		}
	}
	return (SUCCESS);
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

int	count_map_elements(t_data *data) // OK - a voir si faite par JLO
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
	if ((player != 1))
		return (FAILURE);
	return (SUCCESS);
}

bool	parsing_textures(t_data *data) // si espace ou tab ?
{
	int	i;

	if (!(data->map->no_text) || !(data->map->so_text)
		|| !(data->map->we_text) || !(data->map->ea_text))
			return false;
	if (ft_strncmp(data->map->no_text, "NO ./", 5)
		|| ft_strncmp(data->map->so_text, "SO ./", 5)
		|| ft_strncmp(data->map->we_text, "NO ./", 5)
		|| ft_strncmp(data->map->ea_text, "NO ./", 5))
		return false;
	if (!test_path_texture(data->map->no_text)
		|| !test_path_texture(data->map->so_text)
		|| !test_path_texture(data->map->we_text)
		|| !test_path_texture(data->map->ea_text))
			return false;
}

bool	parsing_colors(t_data *data)  // TEST si on entre autre chose que int (demi parsing ?)
{
	int	i;
	int	j;

	if (!data->map->rgb_ceiling || !data->map->rgb_floor)
		return false;
	// REPENSER LE PARSING AU NiVEAU DES COLORS ?? char ** ? parser avant ou apres ?
	i = -1;
	while (++i < 3)
	{
		if ((data->map->rgb_ceiling[i] < 0)
			|| (data->map->rgb_ceiling[i]) > 255)
			return false;
	}
	j = -1;
	while (++j < 3)
	{
		if ((data->map->rgb_floor[i] < 0)
			|| (data->map->rgb_floor[i]) > 255)
			return false;
	}
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
	if (!parsing_textures(data) || ! parsing_colors(data))
		ft_error("---ERROR IN TEXTURES & COLORS---\n");
	return (SUCCESS);
}
