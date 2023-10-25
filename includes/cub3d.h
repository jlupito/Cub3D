
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
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define TEX_WIDTH 100
# define TEX_HEIGHT 100
# define ROTSPEED 0.05
# define MOVESPEED 0.05

typedef struct s_ray {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
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
	double	old_dir_x;
	double	old_plane_x;
	int		tex_img;
	double	step_tex;
	double	tex_pos;
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
	t_ray		*ray;
	int			player;
	char		**map_char;
	int			nb_line;
	int			*rgb_ceiling;
	int			*rgb_floor;
}					t_data;

/********** HOOKS ***********/
int		handle_keypress(int keysym, t_data *data);
int		handle_buttonpress(t_data *data);

/************************ INIT *************************/
int		save_data(char *infile, t_data *data, int flag);
int		init_data(t_data *data);
int		init_player_pos(char *str, int y, t_data *data);
void	init_ray_cast(t_ray *ray);
int		check_args(int ac, char **av);

/************************  MAP  *************************/
int		fill_colors(char *str, t_data *data);
int		fill_text(char *str, t_data *data);
int		text_colors_filled(t_data *data);
int		fill_map(char *str, t_data *data, int i);

/************************PARSING*************************/
int		parsing(t_data *data);
int		parsing_textures(t_data *data);
int		count_map_elements(t_data *data);
int		check_elements_map(t_data *data);
int		check_closed_map(t_data *data);
bool	empty_line(char *str);
int		check_empty_line(t_data *data);
bool	parsing_colors(t_data *data);

/***********************  UTILS  ************************/
void	free_tabs(char **tab);
void	free_all(t_data *data);
void	close_all(t_data *data);
// void	print_map(t_data *data);
int		len_tab(char **tab);
int		is_nothing(char c);
bool	test_path_texture(char *code_texture);

/*********************** ERRORS ************************/
void	ft_error(char *message);

/********** DRAW ***********/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_verti(t_data *data, int x);
int		get_tex_color(t_data *data, int x, int y, int i);
int		get_int_color(int rgb[3]);
int		render(t_data *data);

/********** RAY_CAST ***********/
void	ray_throw(t_ray *ray, int x);
void	step_side_dist(t_ray *ray);
void	prep_drawing(t_ray *ray);
void	perform_dda(t_ray *ray, t_data *data);
void	calc_texture(t_ray *ray);
int		game_init(t_data *data);
int		game_loop(t_data *data);

#endif
