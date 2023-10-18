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

int	check_(char c)
{
	if (!c)
		return (1);
	if (c != ' ')
		return (SUCCESS);
	return (1);
}

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
