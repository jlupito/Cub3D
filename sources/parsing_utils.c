#include <../includes/cub3d.h>

void	ft_error(char *message)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}

bool empty_line(char *str) // OK
{
	while (*str)
	{
		if ((*str != ' ') || (*str != '\t'))
			return false;
		str++;
	}
	return true;
}

int	check_empty_line(t_data *data) // OK
{
	int	y;

	y = -1;
	while (data->map->map_char[++y])
		if (empty_line(data->map->map_char[y]))
			return (1);
	return (SUCCESS);
}

int	is_nothing(char c)
{
	if (!c)
		return (1);
	if (c != ' ')
		return (SUCCESS);
	return (1);
}

bool	test_path_texture(char *code_texture) // OK mais verifier les index
{
	char	*path;
	int	i;

	i = 4; // attention debut a l'index 0
	if (!code_texture || !code_texture[i])
		return (NULL);
	while (code_texture[i])
		i++;
	path = malloc(sizeof(*path) * i + 1);
	if (!path)
		return (false);
	if (!access(path, F_OK))
	{
		free(path);
		return (false);
	}
	else
		return (true);
}
