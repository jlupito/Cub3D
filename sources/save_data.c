/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:31 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/08 13:47:33 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3d.h>

static void	save_cf(char *line, t_data *data)
{
	if (!colors_filled(data)
		|| (line[0] == 'F' && data->rgb_floor[3])
		|| (line[0] == 'C' && data->rgb_ceiling[3]))
		data->flag_pars = 1;
	else if (colors_filled(data))
	{
		if (fill_colors(line, data))
			data->flag_pars = 1;
	}
}

static void	save_text(char *line, t_data *data)
{
	if (!text_filled(data)
		|| (!ft_strncmp(line, "NO ./", 5) && data->img[1].path)
		|| (!ft_strncmp(line, "EA ./", 5) && data->img[4].path)
		|| (!ft_strncmp(line, "SO ./", 5) && data->img[2].path)
		|| (!ft_strncmp(line, "WE ./", 5) && data->img[3].path))
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
			data->line_map++;
		(free(line), line = get_next_line(fd));
	}
	if (text_colors_filled(data) || data->flag_pars)
		return (free(line), ft_error("---WRONG MAP---\n"), EXIT_FAILURE);
	return (free(line), close(fd), 0);
}
