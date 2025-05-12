/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:04:22 by itahani           #+#    #+#             */
/*   Updated: 2024/01/17 16:05:23 by itahani          ###   ########.fr       */
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

typedef struct s_line {
	int		delta_x;
	int		delta_y;
	int		sidelength;
	float	yinc;
	float	xinc;
	float	current_x;
	float	current_y;
}				t_line;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		e;
}				t_data;

typedef struct s_config {
	char	**tab;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
}			t_config;				

typedef struct s_player {
	float	x;
	float	y;
	int		radius;
	float	turndirection;
	float	waldirection;
	float	rotationangle;
	float	sidedirection;
	float	step;
	float	movespeed;
	float	rotationspeed;
	t_line	trajectory;
	float	new_x;
	float	new_y;
}				t_player;

typedef struct s_window {
	void	*win;
	int		width;
	int		height;
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
	int		wall_hitcontent;
	int		was_hitvertical;
	t_line	line;
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
	t_config	config;
	float		scale_minimap;
	t_ray		rays[WINDOW_WIDTH / WALL_STRIP_WIDTH];
	t_data		text[5];
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
int		ft_exit(char *str);

// Parsing

int		check_extension(char *filename);
int		check_xpm(char *path);

int		parsing(t_vars *var, int fd);
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

// Check error

int		check_cr(char *valeur);
int		margin_check(t_player *player, char	**map, int i);

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
void	stop_wall(t_player *player, t_vars *var);
void	init_player(t_player *player, t_vars *var);

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
void	keycode_assignation(t_vars *var, int i);

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
void	assign_verthit_val(t_cast *cast, int i);
void	assign_horhit_val(t_cast *cast, int i);
int		mapped_region(t_vars *var, int x, int y);
int		is_wall(t_vars *cub, float x, float y);

// Rendering

void	render_walls(t_vars *var);
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
void	dda(t_player *player, t_vars *var, t_ray *ray, int color);
void	my_mlx_pixel_put(t_vars *var, int x, int y, int color);
void	draw_square(t_vars *var, int x, int y, int color);
void	draw_grid(t_vars *var, int x, int y, int color);
void	composer_map(t_vars *var);
void	show_player_on_minimap(t_player *player, t_vars *var);
void	compose_wall(t_vars *var);
void	compose_floor(t_vars *var);

#endif