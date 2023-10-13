
#include <../includes/cub3d.h>

t_data	save_data(char *infile)
{
	int		fd;
	char	*line;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == "F" || line[0] == "C")
			fill_colors(line);
		else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "EA", 2)
			|| !ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "WE", 2))
			fill_text(line);
		else
			return (free(line), NULL);
	}
	return (data);
}
