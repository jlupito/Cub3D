
#include <../includes/cub3d.h>

int	check_args(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (ft_putendl_fd("Bad number fo arguments", 2), EXIT_FAILURE);
	i = 0;
	while (av[1][i] != '.' && av[1][i])
		i++;
	if (av[1][i + 1] == 'c' && av[1][i + 2] == 'u'
		&& av[1][i + 3] == 'b' && av[1][i + 4] == '\0')
		return (EXIT_SUCCESS);
	else
		return (ft_putendl_fd("Wrong type of map", 2), EXIT_FAILURE);
}

int	fill_map(char *str, t_data *data, int i)
{
	if (i == 0)
	{
		data->map_char = malloc(sizeof(char *) * (data->nb_line + 1));
		if (!data->map_char)
			return (1);
	}
	data->map_char[i] = ft_strdup(str);
	if (!data->map_char[i])
		return (1);
	if (init_player_pos(data->map_char[i], i, data))
		return (1);
	if (i == (data->nb_line - 1))
		data->map_char[i + 1] = NULL;
	return (0);
}

int	fill_colors(char *str, t_data *data)
{
	char	**tmp;
	int		i;
	int		flag;

	flag = 0;
	if (str[0] == 'F')
		flag = 1;
	str++;
	tmp = ft_split(str, ',');
	if (!tmp)
		return (free_tabs(tmp), 1);
	i = -1;
	while (++i < 3)
	{
		if (flag)
			data->rgb_floor[i] = ft_atoi(tmp[i]);
		else
			data->rgb_ceiling[i] = ft_atoi(tmp[i]);
	}
	if (flag)
		data->rgb_floor[3] = 1;
	else
		data->rgb_ceiling[3] = 1;
	free_tabs(tmp);
	return (EXIT_SUCCESS);
}

int	fill_text(char *str, t_data *data)
{
	if (!ft_strncmp(str, "NO", 2))
	{
		while (*str && *str != '.')
			str++;
		data->img[1].path = ft_strdup_trim(str);
	}
	else if (!ft_strncmp(str, "SO", 2))
	{
		while (*str && *str != '.')
			str++;
		data->img[2].path = ft_strdup_trim(str);
	}
	else if (!ft_strncmp(str, "WE", 2))
	{
		while (*str && *str != '.')
			str++;
		data->img[3].path = ft_strdup_trim(str);
	}
	else if (!ft_strncmp(str, "EA", 2))
	{
		while (*str && *str != '.')
			str++;
		data->img[4].path = ft_strdup_trim(str);
	}
	return (0);
}

int	save_data(char *infile, t_data *data, int flag)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'F' || line[0] == 'C')
		{
			if (text_colors_filled(data))
			{
				if (fill_colors(line, data))
					return (free(line), 1);
			}
		}
		else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "EA", 2)
			|| !ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "WE", 2))
		{
			if (text_colors_filled(data))
			{
				if (fill_text(line, data))
					return (free(line), 1);
			}
		}
		else if (!text_colors_filled(data) && line[0] != '\n')
		{
			if (flag)
			{
				if (fill_map(line, data, i))
					return (free(line), 1);
			}
			i++;
		}
		// else if (line[0] != '\n')
		// 	return (free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	if (text_colors_filled(data))
		return (ft_error("---MISSING MAP COMPONENT---\n"), EXIT_FAILURE);
	if (!flag)
		data->nb_line = i;
	(free(line), close(fd));
	return (0);
}
