
#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <limits.h>

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define ROTSPEED 0.05
# define MOVESPEED 0.05

typedef struct s_map {
	char	**map_char;
	int		nb_line;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	int		*rgb_ceiling;
	int		*rgb_floor;
}				t_map;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		flag;
}				t_player;

typedef struct s_ray {
	double	pos_x; //position x du joueur
	double	pos_y; //position y du joueur
	double	dir_x; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double	dir_y; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double	plane_x; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double	plane_y; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double	ray_dir_x; //calcul de direction x du rayon
	double	ray_dir_y; //calcul de direction y du rayon
	double	camera_x; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		map_x; // coordonée x du carré dans lequel est pos
	int		map_y; // coordonnée y du carré dans lequel est pos
	double	side_dist_x; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double	side_dist_y; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double	delta_dist_x; //distance que rayon parcours entre chaque point d'intersection vertical
	double	delta_dist_y; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int		step_x; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		step_y; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double	perp_wall_dist; // distance du joueur au mur
	int		line_height; //hauteur de la ligne a dessiner
	int		draw_start; //position de debut ou il faut dessiner
	int		draw_end; //position de fin ou il faut dessiner
	char	**world_map;
	double	old_dir_x;
	double	old_plane_x;
	double	ta_mere;
	int		tex_img;
	int		tex_height;
	double	tex_incr_y;
	double	step_tex;
	double	tex_pos;
	int		tex_num;
	double	tex_width;
	int		tex_x;
	int		tex_y;
	double	wall_x;
}				t_ray;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	char	*path;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}				t_img;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img[5];
	t_map		*map;
	t_ray		*ray;
	t_player	*player;
}					t_data;

/********** HOOKS ***********/
int		handle_keypress(int keysym, t_data *data);
int		handle_buttonpress(t_data *data);

/********** INIT ***********/
int		save_data(char *infile, t_data *data, int flag);
int		init_data(t_data *data);
int		check_args(int ac, char **av);

/********** MAP ***********/
int		fill_colors(char *str, t_data *data);
int		fill_text(char *str, t_data *data);
int		text_colors_filled(t_data *data);
int		fill_map(char *str, t_data *data, int i);
// int		search_player_pos(char *str, int y, t_data *data);

/********** UTILS ***********/
void	free_tabs(char **tab);
void	free_all(t_data *data);
void	print_map(t_data *data);

/********** DRAW ***********/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_verti(t_data *data, int x);
int		get_color(t_data *data, int x, int y, int i);
int		render(t_data *data);

/********** RAY_CAST ***********/
void	ray_throw(t_data *data, int x);
void	step_side_dist(t_data *data);
void	prep_drawing(t_data *data);
void	perform_dda(t_data *data);
void	init_ray_cast(t_ray *ray);
int		game_loop(t_data *data);

#endif
