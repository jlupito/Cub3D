
#include <../includes/cub3d.h>

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
		if (line[0] == 'F' || line[0] == 'C') // Floors and ceilings
		{
			if (text_colors_filled(data))
			{
				if (fill_colors(line, data))
					return (free(line), 1);
			}
		}
		else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "EA", 2) // Textures
			|| !ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "WE", 2))
		{
			if (text_colors_filled(data))
			{
				if (fill_text(line, data))
					return (free(line), 1);
			}
		}
		else if (!text_colors_filled(data) && line[0] != '\n' && line != NULL) // Map_char
		{
			printf("map fausse mais on y va quand meme ...!\n");
			if (flag)
			{
				if (fill_map(line, data, i))
					return (free(line), 1);
			}
			// if (!flag)
			// 	return (ft_error("---MISSING MAP ARGUMENTS---\n"), free(line), 1);
			i++;
		}
		(free(line), line = get_next_line(fd));
	}
	if (text_colors_filled(data))
		return (ft_error("---MISSING MAP COMPONENT---\n"), EXIT_FAILURE);
	if (!flag)
		data->nb_line = i;
	(free(line), close(fd));
	return (0);
}
