#include <../includes/cub3d.h>

void	ft_error(char *message)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}

bool	empty_line(char *str)
{
	while (*str)
	{
		if ((*str != ' ') || (*str != '\t'))
			return (false);
		str++;
	}
	return (true);
}

int	check_empty_line(t_data *data)
{
	int	y;

	y = -1;
	while (data->map_char[++y])
		if (empty_line(data->map_char[y]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_nothing(char c)
{
	if (!c)
		return (EXIT_FAILURE);
	if (c != ' ')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

bool	test_path_texture(char *code_texture)
{
	char	*path;
	int		i;

	i = 4;
	if (!code_texture || !code_texture[i])
		return (NULL);
	while (code_texture[i])
		i++;
	path = malloc(sizeof(*path) * i + 1);
	if (!path)
		return (false);
	if (!access(path, F_OK))
		return (free(path), false);
	else
		return (free(path), true);
}
