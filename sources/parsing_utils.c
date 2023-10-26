#include <../includes/cub3d.h>

void	ft_error(char *message)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}

bool	empty_line(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || str[i] == '\n')
		return (false);
	while (str[i] && str[i] != '\n')
	{
		if ((str[i] != ' ') && (str[i] != '\t'))
			return (false);
		i++;
	}
	return (true);
}

int	check_empty_line(t_data *data)
{
	int	y;

	y = 0;
	while (data->map_char[y])
	{
		if (empty_line(data->map_char[y]) == true)
			return (EXIT_FAILURE);
		y++;
	}
	return (EXIT_SUCCESS);
}

int	is_nothing(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	test_path_texture(char *path_texture)
{
	char	*path;
	int		i;

	if (!path_texture || !*path_texture)
		return (false);
	i = 0;
	while (path_texture[i])
		i++;
	path = malloc(sizeof(char) * (i + 1));
	if (!path)
		return (false);
	i = 0;
	while (path_texture[i])
	{
		path[i] = path_texture[i];
		i++;
	}
	path[i] = '\0';
	if (access(path, F_OK) == -1)
		return (free(path), false);
	else
		return (free(path), true);
}
