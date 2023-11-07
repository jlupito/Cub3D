
#include <../includes/cub3d.h>

// int	extract_line_map(char *line, t_data *data, int flag, int *i)
// {


// 	return (0);
// }

// int	extract_line_fct(char *line, t_data *data, int flag, int *i)
// {
// 	if (line[0] == 'F' || line[0] == 'C')
// 	{
// 		if (!colors_filled(data) && !flag)
// 			return (ft_error("---too many colors---\n"), free(line), 1);
// 		else if (colors_filled(data) && !flag)
// 		{
// 			if (fill_colors(line, data))
// 				return (ft_error("---error in colors---\n"), free(line), 1);
// 		}
// 	}
// 	else if (!ft_strncmp(line, "NO ./", 5) || !ft_strncmp(line, "EA ./", 5)
// 		|| !ft_strncmp(line, "SO ./", 5) || !ft_strncmp(line, "WE ./", 5))
// 	{
// 		if (!text_filled(data) && !flag)
// 			return (ft_error("---too many text---\n"), free(line), 1);
// 		else if (text_filled(data) && !flag)
// 		{
// 			if (fill_text(line, data))
// 				return (ft_error("---error in text---\n"), free(line), 1);
// 		}
// 	}
// 	else if (text_colors_filled(data) && line[0] != '\n' && line)
// 		return (ft_error("---WRONG LINE---\n"), free(line), 1);
// 	else if (!text_colors_filled(data) && line[0] != '\n' && line != NULL)
// 		// extract_line_map(line, data, flag, i);
// 	{
// 		if (flag)
// 		{
// 			if (fill_map(line, data, *i))
// 				return (free(line), 1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }


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
		printf("line: %s\n", line);
		if (line[0] == 'F' || line[0] == 'C')
		{
			if (!colors_filled(data) && !flag)
				return (ft_error("---too many colors---\n"), free(line), 1);
			else if (colors_filled(data) && !flag)
			{
				if (fill_colors(line, data))
					return (ft_error("---error in colors---\n"), free(line), 1);
			}
		}
		else if (!ft_strncmp(line, "NO ./", 5) || !ft_strncmp(line, "EA ./", 5)
			|| !ft_strncmp(line, "SO ./", 5) || !ft_strncmp(line, "WE ./", 5))
		{
			if (!text_filled(data) && !flag)
				return (ft_error("---too many text---\n"), free(line), 1);
			else if (text_filled(data) && !flag)
			{
				if (fill_text(line, data))
					return (ft_error("---error in text---\n"), free(line), 1);
			}
		}
		else if (text_colors_filled(data) && line[0] != '\n' && line)
			return (ft_error("---WRONG LINE---\n"), free(line), 1);
		else if (!text_colors_filled(data) && line[0] != '\n' && line != NULL)
		{
			if (flag)
			{
				if (fill_map(line, data, i))
					return (free(line), 1);
			}
			// else if (!flag)
			// 	return (free(line), 1);
			i++;
		}
		(free(line), line = get_next_line(fd));
	}
	if (text_colors_filled(data))
		return (ft_error("---WRONG MAP---\n"), EXIT_FAILURE);
	if (!flag)
		data->nb_line = i;
	(free(line), close(fd));
	return (0);
}


		// if (line[0] == 'F' || line[0] == 'C')
		// {
		// 	if (!colors_filled(data) && !flag)
		// 		return (ft_error("---too many colors---\n"), free(line), 1);
		// 	else if (colors_filled(data) && !flag)
		// 	{
		// 		if (fill_colors(line, data))
		// 			return (ft_error("---error in colors---\n"), free(line), 1);
		// 	}
		// }
		// else if (!ft_strncmp(line, "NO ./", 5) || !ft_strncmp(line, "EA ./", 5)
		// 	|| !ft_strncmp(line, "SO ./", 5) || !ft_strncmp(line, "WE ./", 5))
		// {
		// 	if (!text_filled(data) && !flag)
		// 		return (ft_error("---too many text---\n"), free(line), 1);
		// 	else if (text_filled(data) && !flag)
		// 	{
		// 		if (fill_text(line, data))
		// 			return (ft_error("---error in text---\n"), free(line), 1);
		// 	}
		// }
		// else if (text_colors_filled(data) && line[0] != '\n' && line)
		// 	return (ft_error("---WRONG LINE---\n"), free(line), 1);
		// else if (!text_colors_filled(data) && line[0] != '\n' && line != NULL)
		// {
		// 	if (flag)
		// 	{
		// 		if (fill_map(line, data, i))
		// 			return (free(line), 1);
		// 	}
		// 	i++;
		// }