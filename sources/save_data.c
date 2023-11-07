
#include <../includes/cub3d.h>

static void	save_cf(char *line, t_data *data)
{
	if (!colors_filled(data))
		data->flag_pars = 1;
	else if (colors_filled(data))
	{
		if (fill_colors(line, data))
			data->flag_pars = 1;
	}
}

static void	save_text(char *line, t_data *data)
{
	if (!text_filled(data))
		data->flag_pars = 1;
	else if (text_filled(data))
	{
		if (fill_text(line, data))
			data->flag_pars = 1;
	}
}

int	save_data(char *infile, t_data *data)
{
	int		fd;
	char	*line;

	data->index_map = 0;
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		data->index_map++;
		if (line[0] == 'F' || line[0] == 'C')
			save_cf(line, data);
		else if (!ft_strncmp(line, "NO ./", 5) || !ft_strncmp(line, "EA ./", 5)
			|| !ft_strncmp(line, "SO ./", 5) || !ft_strncmp(line, "WE ./", 5))
			save_text(line, data);
		else if (text_colors_filled(data) && line[0] != '\n' && line)
			data->flag_pars = 1;
		else if (!text_colors_filled(data) && line[0] != '\n' && line)
			// save_map(line, data, flag);
			data->line_map++;
		(free(line), line = get_next_line(fd));
	}
	if (text_colors_filled(data) || data->flag_pars)
		return (free(line), ft_error("---WRONG MAP---\n"), EXIT_FAILURE);
	(free(line), close(fd));
	return (0);
}
