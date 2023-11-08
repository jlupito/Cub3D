
#include <../includes/cub3d.h>

int	check_args(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (ft_putendl_fd("--BAD NUMBER OF ARGUMENTS--", 2), EXIT_FAILURE);
	i = 0;
	while (av[1][i] != '.' && av[1][i])
		i++;
	if (av[1][i + 1] == 'c' && av[1][i + 2] == 'u'
		&& av[1][i + 3] == 'b' && av[1][i + 4] == '\0')
		return (EXIT_SUCCESS);
	else
		return (ft_putendl_fd("---WRONG TYPE OF MAP---", 2), EXIT_FAILURE);
}

int	fill_map(char *str, t_data *data, int i)
{
	if (i == 0)
	{
		data->map_char = malloc(sizeof(char *) * (data->line_map + 1));
		if (!data->map_char)
			return (EXIT_FAILURE);
	}
	data->map_char[i] = ft_strdup(str);
	if (!data->map_char[i])
		return (EXIT_FAILURE);
	if (init_player_pos(data->map_char[i], i, data))
		return (EXIT_FAILURE);
	if (i == (data->line_map - 1))
		data->map_char[i + 1] = NULL;
	return (EXIT_SUCCESS);
}

void	fill_cf_colors(int flag, int i, t_data *data, char **tmp)
{
	if (flag)
		data->rgb_floor[i] = ft_atoi(tmp[i]);
	else
		data->rgb_ceiling[i] = ft_atoi(tmp[i]);
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
	if (len_tab(tmp) != 3)
		return (ft_error("---ERROR IN COLORS---\n"), free_tabs(tmp), 1);
	while (++i < 3)
		fill_cf_colors(flag, i, data, tmp);
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
	return (EXIT_SUCCESS);
}
