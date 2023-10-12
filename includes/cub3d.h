
#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define BLACK_PIXEL 0x000000
# define WINDOW_WIDTH 1800
# define WINDOW_HEIGHT 1200

typedef struct s_map {
	int		nbline;
	int		nbcol;
}				t_map;

typedef struct s_data {
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				color;
	// int				vertical;
	// int				offset;
	// int				horizontal;
	struct s_map	map;
}					t_data;

int			handle_keypress(int keysym, t_data *cub);
int			handle_buttonpress(t_data *cub);

#endif