
#include <../includes/cub3d.h>

int	check_args(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (EXIT_FAILURE);
	i = 0;
	while (av[1][i] != '.' && av[1][i])
		i++;
	if (av[1][i + 1] == 'c' && av[1][i + 2] == 'u'
		&& av[1][i + 3] == 'b' && av[1][i + 4] == '\0')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

// int	search_player_pos(char *str, int y, t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((str[i] == 'N' || str[i] == 'W' || str[i] == 'E'
// 				|| str[i] == 'S') && !data->player->flag)
// 		{
// 			data->player->pos_x = i;
// 			data->player->pos_y = y;
// 			data->player->plane_x = 0;
// 			data->player->plane_y = 0.66;
// 			if (str[i] == 'N')
// 			{
// 				data->player->dir_x = i;
// 				data->player->dir_y = y - 1;
// 			}
// 			else if (str[i] == 'W')
// 			{
// 				data->player->dir_x = i - 1;
// 				data->player->dir_y = y;
// 			}
// 			else if (str[i] == 'E')
// 			{
// 				data->player->dir_x = i;
// 				data->player->dir_y = y - 1;
// 			}
// 			else if (str[i] == 'S')
// 			{
// 				data->player->dir_x = i + 1;
// 				data->player->dir_y = y;
// 			}
// 			data->player->flag == 1;
// 			return (0);
// 		}
// 		else if ((str[i] == 'N' || str[i] == 'W' || str[i] == 'E'
// 				|| str[i] == 'S') && data->player->flag)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
