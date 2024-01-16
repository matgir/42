/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:04:22 by itahani           #+#    #+#             */
/*   Updated: 2024/01/15 23:47:20 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./Libft/libft.h"
# include <math.h>
# include <limits.h> // SUPPRIMER
# include <unistd.h>

# define TILE_SIZE 128
# define TEXT_SIZE 128
# define FORWARD 119 // W
# define BACKWARD 115 // S
# define LEFT 97 // A
# define RIGHT 100 // D
# define ESC 65307
# define WINDOW_WIDTH 1500 // add secur par rapport a resolution max de l'ecran
# define WINDOW_HEIGHT 900
# define WALL_STRIP_WIDTH 1

# define NUM_RAYS (WINDOW_WIDTH / WALL_STRIP_WIDTH)
# define FOV_ANGLE (60 * (M_PI / 180))
# define TWO_PI M_PI * 2

# define N 1
# define S 2
# define E 3
# define W 4
// # define NUM_RAYS 10

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


// AJOUT de la branche elise-freshstart
typedef struct s_config {			//
	char	**tab;					//
	char	*north;					//
	char	*south;					//
	char	*west;					//
	char	*east;					//
	int		floor;					//
	int		ceiling;				//
}			t_config;				//
// AJOUT de la branche elise-freshstart

typedef struct s_player {
	float	x; //middle of the map, window width/2
	float	y; //window height/2
	int		radius; //3pxl
	float	turndirection; //-1 if left and +1 if right
	float	waldirection; //-1 if back and +1 if forward
	float	rotationangle; //Math.PI/2 (90 degrees)
	float	sidedirection;
	float	step;
	float	movespeed; // 2.0
	float	rotationspeed; // 2 * (MAth.PI / 180)
}				t_player;

typedef struct s_window {
	void	*win;
	int		width; //y //en pixel
	int		height; //x // en pixel
}				t_window;

typedef struct s_ray {
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	float	minimap_dist;
	int		ray_facingdown;
	int		ray_facingup;
	int		ray_facingright;
	int		ray_facingleft;
	int		wall_hitcontent; /* what is in the tile	that was hit by the ray
								(1 ? 0 ?...?). Useful for the textures*/
	int		was_hitvertical;
}				t_ray;

typedef struct s_cast {
	int		ray_facingdown;
	int		ray_facingup;
	int		ray_facingright;
	int		ray_facingleft;
	float	next_vertical_x;
	float	next_vertical_y;
	float	next_horizontal_x;
	float	next_horizontal_y;
	float	x_inter;
	float	y_inter;
	float	x_step;
	float	y_step;
	int		horizontal_hit;
	float	horizontal_hit_x;
	float	horizontal_hit_y;
	int		horizontal_content;
	int		vertical_hit;
	float	vertical_hit_x;
	float	vertical_hit_y;
	int		vertical_content;
	int		wall_hit;
	int		wall_content;
	int		wall_hit_vertical;
	int		wall_hit_horizontal;
	float	current_x;
	float	current_y;
	float	vertical_hit_distance;
	float	horizontal_hit_distance;
}				t_cast;

typedef struct s_vars {
	t_data		img;
	t_player	player;
	void		*mlx;
	int			mapwidth;
	int			mapheight;
	t_window	win;
	char		**infile;
	char		**map;
	t_config	config; // struct for elements parsing
	t_ray		rays[NUM_RAYS];
	t_data		text[4];
	float		tmp_distance; //SUPPRIMER
}				t_vars;

typedef struct s_color {
	char	*rgb;
	char	*r;
	char	*g;
	char	*b;
	char	*r_hexa;
	char	*g_hexa;
	char	*b_hexa;
	char	*hexa;
}				t_color;

typedef struct s_render
{
	float	dist_proj_plane;
	float	wallstripheight;
	float	wallstripwidth;
	int		walltoppxl;
	int		wallbottompxl;
	int		distfromtop;
	int		offset_x;
	int		offset_y;
	int		pxl;
}				t_render;

// Utils

int		ft_height(char **map);
char	**split_for_cub(const char *s, char c);
int		nb_lignes(const char *str);
int		tab_len(char **tab);
void	print_error(char *err);
char	**ft_trim_tab(char **tab);

// Parsing

int		check_extension(char *filename);
int		check_xpm(char *path);

int		parsing(t_vars *var);
int		one_player(char **map);
int		is_player(char c);
int		wall_surrounded(char **map);
int		wall_surrounded_loop(char **map, int x, int y, int y_max);
int		allowed_char(char **map);

int		parsing_elements(t_vars *var, char **file);
int		is_only_whitespace(char *line);
void	ret_to_one(int *ret);
int		is_color_code(char *element, int i);
int		valid_rgb_index(char *element, int *i);
char	*get_path_texture(char *element);
int		is_identifier(char *element);
int		is_valid_element(char *element);
int		check_doublons(char **tab, char *elem);
int		add_element(char *element, t_vars *var);
void	set_valid_value(char **file, int *i, int *valid);

// Draw Minimap

void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
void	draw_square(t_vars *var, int x, int y, int color);
void	draw_grid(t_vars *var, int x, int y, int color);
void	composer_map(t_vars *var);
void	show_player_on_minimap(t_player *player, t_vars *var);

// Check error

int		check_cr(char *valeur);

// Init Map

void	get_win_size(t_vars *var);
void	def_var(t_vars *var);
char	**cub_to_tab(int fd);
char	**get_map(t_vars *var, char **file);

// Init config for rendering

void	get_rgb(t_color	*color);
void	init_config(t_config *config);
void	get_hexa(char *tmp_rgb, int *rgb);
void	hexa_str_to_int(t_color *color, int *hex);
char	*get_hexa_color(char *color);
void	init_config_text(t_config *config, char **elm, int i);
void	ft_puthexa(unsigned int nbr, int i, char *res);
int		hexa_char_to_int(char c);
void	ft_strjoin_hexa(char *res, t_color *color);
void	get_color(char *rgb, char *color, int *i);

// Player SetUp

void	start_position(t_vars *var, t_player *player);
void	stop_wall(t_player *player, t_vars *var, int keycode);
void	init_player(t_player *player, t_vars *var);
void	vision_line(t_data *img, t_player *player, int color); // à supprimer

// Free

void	*ft_free(t_vars *var);
int		free_mlx(t_vars *var);
int		free_mlxptr(t_vars *var);
int		free_for_parser(t_vars *var);
void	*free_tab(char **tab);
void	destroy_textures(t_vars *var);

// Key Hook

int		key_hook(int keycode, t_vars *var);
void	update_img(t_vars *var);

// Raycasting

void	init_rays(t_vars *cub);
void	cast_all_rays(t_vars *cub);
float	normalize_angle(float angle);
void	get_ray_orientation(t_cast *cast, float ray_angle);
int		is_wall(t_vars *cub, float x, float y);
void	horizontal_step(t_vars *cub, float ray_angle, t_cast *cast);
void	horizontal_hit(t_vars *cub, t_cast *cast);
void	vertical_step(t_vars *cub, float ray_angle, t_cast *cast);
void	vertical_hit(t_vars *cub, t_cast *cast);
float	distance_calculus(float p_x, float p_y, float hit_x, float hit_y);
void	set_distance(t_vars *cub, t_cast *cast);
void	compare_distance(t_cast *cast, t_ray *ray, float ray_angle);
void	render_fov(t_vars *cub, t_player *player, int color);
void	adjust_distance(t_player *player, t_ray *ray);

// Rendering

void	render_walls(t_vars *var);
// void	update_render(t_vars *var);
t_data	*get_texture(t_ray *ray, t_vars *var);
void	compose_wall_strip(t_vars *var, t_render *render, int i, t_data *text);
void	put_pix(t_data *img, int x, int y, int color);
void	render_minimap(t_vars *var);
void	render_3d_map(t_vars *var);
void	render_floor_ceiling(t_vars *var, t_config *config);
void	render_floor(t_vars *var, int y, int color);
void	render_ceiling(t_vars *var, int y, int color);
void	text_offset_x(t_ray *ray, t_render *render);
void	init_textures(t_vars *var);

#endif