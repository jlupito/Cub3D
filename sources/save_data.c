
#include <../includes/cub3d.h>

int	fill_map(char *str, t_data *data, int i)
{
	if (i == 0)
	{
		data->map->map_char = malloc(sizeof(char *) * (data->map->nb_line + 1));
		if (!data->map->map_char)
			return (1);
	}
	data->map->map_char[i] = ft_strdup(str);
	if (!data->map->map_char[i])
		return (1);
	// if (search_player_pos(data->map->map_char[i], i, data))
	// 	return (1);
	if (i == (data->map->nb_line - 1))
		data->map->map_char[i + 1] = NULL;
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
			data->map->rgb_floor[i] = ft_atoi(tmp[i]);
		else
			data->map->rgb_ceiling[i] = ft_atoi(tmp[i]);
	}
	if (flag)
		data->map->rgb_floor[3] = 1;
	else
		data->map->rgb_ceiling[3] = 1;
	free_tabs(tmp);
	return (0);
}

int	fill_text(char *str, t_data *data)
{
	if (!ft_strncmp(str, "NO", 2))
	{
		while (*str && *str != '.')
			str++;
		data->map->no_text = ft_strdup(str);
	}
	else if (!ft_strncmp(str, "SO", 2))
	{
		while (*str && *str != '.')
			str++;
		data->map->so_text = ft_strdup(str);
	}
	else if (!ft_strncmp(str, "WE", 2))
	{
		while (*str && *str != '.')
			str++;
		data->map->we_text = ft_strdup(str);
	}
	else if (!ft_strncmp(str, "EA", 2))
	{
		while (*str && *str != '.')
			str++;
		data->map->ea_text = ft_strdup(str);
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
		free(line);
		line = get_next_line(fd);
	}
	if (!flag)
		data->map->nb_line = i;
	(free(line), close(fd));
	return (0);
}
