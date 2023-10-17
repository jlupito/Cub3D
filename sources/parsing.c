#include <../includes/cub3d.h>

int	check_args(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (EXIT_FAILURE);
	i = 0;
	while (av[1][i] != '.' && av[1][i])
		i++;
	if (av[1][i + 1] == 'c' && av[1][i + 2] == 'u'
		&& av[1][i + 3] == 'b' && av[1][i + 4] == '\0')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

void	ft_error(char *message)
{
	ft_putstr_fd("ERROR\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}

/************************** SO_LONG FUNCTIONS A ADAPTER ************************/

int	check_empty_line(t_data *data) // A FINIR
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (data->map->map_char[++y])
	{
		while (data->map->map_char[y][++x])
		{
			if (data->map->map_char[y][x] )
		}
	}
}

int	check_closed_map(t_data *data) // A REFAIRE
{
	int	x;
	int	y;
	int	width;
	int	height;

	y = 0;
	width = ft_strlen(data->map.map_ber[0]);
	height = data->map.lines;
	while (y < height)
	{
		x = 0;
		if (data->map.map_ber[y][x] != WALL
			|| data->map.map_ber[y][width - 1] != WALL)
			return (0);
		y++;
	}
	x = 0;
	while (x < width)
	{
		if (data->map.map_ber[0][x] != WALL
			|| data->map.map_ber[height - 1][x] != WALL)
			return (0);
		x++;
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
	if (!check_closed_map(data))
		ft_error("---MAP IS NOT CLOSED---\n");
	if (!check_elements_map(data))
		ft_error("---UNAPPROVED MAP COMPONENT---\n");
	if (!count_map_elements(data))
		ft_error("---WRONG NUMBER OF PLAYERS---\n");
	return (SUCCESS);
}
